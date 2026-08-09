import logging
import os
import requests
from django.utils import timezone
from google.oauth2 import service_account
from googleapiclient.discovery import build
from googleapiclient.http import MediaIoBaseUpload
from .models import *

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def create_google_calendar_event(user_id, message):
    logger.info(f"Creating Google Calendar event for user {user_id} based on message: {message.subject}")

    SCOPES = ['https://www.googleapis.com/auth/calendar']
    SERVICE_ACCOUNT_FILE = os.path.join('config', 'service_account.json')
    credentials = service_account.Credentials.from_service_account_file(
        SERVICE_ACCOUNT_FILE, scopes=SCOPES)
    service = build('calendar', 'v3', credentials=credentials)

    # Event details
    start_time = timezone.now()
    end_time = start_time + timezone.timedelta(hours=1)
    event = {
        'summary': f"New Teams Message: {message.subject}",
        'description': message.body_preview,
        'start': {
            'dateTime': start_time.isoformat(),
            'timeZone': 'UTC',
        },
        'end': {
            'dateTime': end_time.isoformat(),
            'timeZone': 'UTC',
        },
    }

    try:
        event = service.events().insert(calendarId='primary', body=event).execute()
        CalendarEventReaction.objects.create(
            user_id=user_id,
            summary=event['summary'],
            description=event['description'],
            start_time=start_time,
            end_time=end_time
        )
        logger.info(f"Event created: {event.get('htmlLink')}")
    except Exception as e:
        logger.error(f"Failed to create Google Calendar event: {e}")


def check_onedrive_for_new_file(user_id, access_token):
    logger.info(f"Checking OneDrive for new files for user: {user_id}")

    url = f"https://graph.microsoft.com/v1.0/me/drive/root/children"
    headers = {
        'Authorization': f'Bearer {access_token}',
        'Content-Type': 'application/json'
    }
    
    response = requests.get(url, headers=headers)
    data = response.json()

    if response.status_code != 200:
        logger.error(f"Error fetching OneDrive files: {data}")
        return None

    files = data.get('value', [])
    for file in files:
        created_time = timezone.datetime.fromisoformat(file['createdDateTime'].replace("Z", "+00:00"))

        file_obj, created = OneDriveFile.objects.get_or_create(
            user_id=user_id,
            file_id=file['id'],
            defaults={
                'name': file['name'],
                'created_at': created_time,
                'saved_to_drive': False
            }
        )

        if created or not file_obj.saved_to_drive:
            save_file_to_google_drive(user_id, file_obj, access_token)
            file_obj.saved_to_drive = True
            file_obj.save()
            break
    else:
        logger.info(f"No new files found in OneDrive for user {user_id}")

def save_file_to_google_drive(user_id, onedrive_file, access_token):
    logger.info(f"Saving OneDrive file '{onedrive_file.name}' to Google Drive for user {user_id}")

    # Download file content from OneDrive
    download_url = f"https://graph.microsoft.com/v1.0/me/drive/items/{onedrive_file.file_id}/content"
    headers = {
        'Authorization': f'Bearer {access_token}',
    }
    response = requests.get(download_url, headers=headers)
    if response.status_code != 200:
        logger.error(f"Error downloading OneDrive file '{onedrive_file.name}': {response.json()}")
        return None

    file_content = response.content

    SCOPES = ['https://www.googleapis.com/auth/drive']
    SERVICE_ACCOUNT_FILE = os.path.join('config', 'service_account.json')
    
    credentials = service_account.Credentials.from_service_account_file(
        SERVICE_ACCOUNT_FILE, scopes=SCOPES)
    service = build('drive', 'v3', credentials=credentials)

    file_metadata = {'name': onedrive_file.name}
    media = MediaIoBaseUpload(file_content, mimetype='application/octet-stream')

    try:
        created_file = service.files().create(body=file_metadata, media_body=media).execute()
        
        GoogleDriveFileReaction.objects.create(
            user_id=user_id,
            file_name=created_file['name'],
            google_drive_id=created_file['id']
        )
        logger.info(f"File '{onedrive_file.name}' successfully saved to Google Drive")
    except Exception as e:
        logger.error(f"Failed to save file to Google Drive: {e}")

def check_new_outlook_email(user_id, access_token):
    logger.info(f"Checking for new Outlook emails for user: {user_id}")
    url = f"https://graph.microsoft.com/v1.0/me/mailFolders/inbox/messages"
    headers = {
        'Authorization': f'Bearer {access_token}',
        'Content-Type': 'application/json'
    }
    params = {
        '$orderby': 'receivedDateTime desc',
        '$top': 10  # Retrieve the latest 10 messages
    }
    
    response = requests.get(url, headers=headers, params=params)
    if response.status_code != 200:
        logger.error(f"Error fetching emails: {response.json()}")
        return None

    emails = response.json().get('value', [])
    for email in emails:
        received_time = timezone.datetime.fromisoformat(email['receivedDateTime'].replace("Z", "+00:00"))
        if received_time > timezone.now() - timezone.timedelta(minutes=1):  # Check if received in last minute
            email_obj, created = OutlookEmailAction.objects.get_or_create(
                user_id=user_id,
                message_id=email['id'],
                defaults={
                    'subject': email['subject'],
                    'sender': email['from']['emailAddress']['address'],
                    'received_at': received_time,
                    'processed': False
                }
            )
            if created or not email_obj.processed:
                create_google_calendar_event(user_id, email_obj)
                post_message_to_google_chat(user_id, email_obj)
                email_obj.processed = True
                email_obj.save()
                break
    else:
        logger.info(f"No new emails for user {user_id}")

def post_message_to_google_chat(user_id, email):
    logger.info(f"Posting to Google Chat for email: {email.subject}")

    google_chat_webhook_url = 'YOUR_GOOGLE_CHAT_WEBHOOK_URL'

    message_content = {
        'text': f"New Outlook Email from {email.sender}: {email.subject}"
    }

    response = requests.post(google_chat_webhook_url, json=message_content)
    
    if response.status_code == 200:
        GoogleChatMessageReaction.objects.create(
            user_id=user_id,
            chat_space='YOUR_CHAT_SPACE_ID',
            email_subject=email.subject,
            email_sender=email.sender,
            message_id=email.message_id
        )
        logger.info(f"Message posted to Google Chat for email: {email.subject}")
    else:
        logger.error(f"Failed to post message to Google Chat: {response.text}")
