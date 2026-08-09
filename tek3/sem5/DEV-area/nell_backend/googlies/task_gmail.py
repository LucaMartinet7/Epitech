import requests
import logging
from datetime import datetime, timedelta, timezone
from googleapiclient.discovery import build
from google.oauth2.credentials import Credentials
from .models import GmailReceivedAction, TwitchChatReaction, SpotifySongReaction
from twitchs.models import BlueskyPostReaction
from authentication.models import SocialUser
from django.conf import settings
from atproto import Client
from .tasks import *
from .task_secondbase import *

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def check_gmail_for_spotify():
    """Checks Gmail for new emails and triggers reactions if a new email is received."""
    actions = GmailReceivedAction.objects.all()
    
    for action in actions:
        user = action.user
        social_user = SocialUser.objects.filter(user=user, provider='google').first()
        
        if not social_user or not social_user.access_token:
            print(f"No Google access token found for user {user.username}")
            continue

        print(f"Processing action for user {user.username}")
        
        try:
            service = initialize_gmail_service(
                social_user.access_token,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_KEY,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_SECRET,
                settings.AUTHORIZATION_URL_GOOGLE,
                'https://oauth2.googleapis.com/token'
            )

            two_minutes_ago = int((datetime.now(timezone.utc) - timedelta(minutes=2)).timestamp())

            response = service.users().messages().list(
                userId='me',
                q=f'after:{two_minutes_ago}'
            ).execute()

            messages = response.get('messages', [])

            if messages:
                logger.info(f"New email detected for user {user.username}. Triggering reactions.")
                run_spotify_reaction(user)
                return 0

        except Exception as e:
            if 'invalid_client' in str(e) or 'invalid_grant' in str(e):
                logger.error(f"Authentication error for user {user.username}: {e}")
            else:
                logger.error(f"Error checking Gmail for user {user.username}: {e}")
            return 1

def check_gmail_for_twitch():
    """Checks Gmail for new emails and triggers reactions if a new email is received."""
    actions = GmailReceivedAction.objects.all()
    
    for action in actions:
        user = action.user
        social_user = SocialUser.objects.filter(user=user, provider='google').first()
        
        if not social_user or not social_user.access_token:
            print(f"No Google access token found for user {user.username}")
            continue

        try:
            service = initialize_gmail_service(
                social_user.access_token,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_KEY,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_SECRET,
                settings.AUTHORIZATION_URL_GOOGLE,
                'https://oauth2.googleapis.com/token'
            )

            two_minutes_ago = int((datetime.now(timezone.utc) - timedelta(minutes=2)).timestamp())
            
            response = service.users().messages().list(
                userId='me',
                q=f'after:{two_minutes_ago}'
            ).execute()
            
            messages = response.get('messages', [])
            
            if messages:
                logger.info(f"New email detected for user {user.username}. Triggering reactions.")
                run_twitch_reaction(user)
                return 0

        except Exception as e:
            if 'invalid_client' in str(e) or 'invalid_grant' in str(e):
                logger.error(f"Authentication error for user {user.username}: {e}")
                print(f"Authentication error for user {user.username}. Please check OAuth credentials.")
            else:
                logger.error(f"Error checking Gmail for user {user.username}: {e}")
                print(f"Error checking Gmail for user {user.username}. Exception: {e}")
            return 1
        
def check_gmail_for_emails():
    """Checks Gmail for new emails and triggers reactions if a new email is received."""
    actions = GmailReceivedAction.objects.all()
    
    for action in actions:
        user = action.user
        social_user = SocialUser.objects.filter(user=user, provider='google').first()
        
        if not social_user or not social_user.access_token:
            print(f"No Google access token found for user {user.username}")
            continue
 
        try:
            service = initialize_gmail_service(
                social_user.access_token,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_KEY,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_SECRET,
                settings.AUTHORIZATION_URL_GOOGLE,
                'https://oauth2.googleapis.com/token'
            )

            two_minutes_ago = int((datetime.now(timezone.utc) - timedelta(minutes=2)).timestamp())
            response = service.users().messages().list(
                userId='me',
                q=f'after:{two_minutes_ago}'
            ).execute()
            
            messages = response.get('messages', [])
            
            if messages:
                logger.info(f"New email detected for user {user.username}. Triggering reactions.")
                print("New email detected. Triggering reactions.")
                return 0

        except Exception as e:
            if 'invalid_client' in str(e) or 'invalid_grant' in str(e):
                logger.error(f"Authentication error for user {user.username}: {e}")
                print(f"Authentication error for user {user.username}. Please check OAuth credentials.")
            else:
                logger.error(f"Error checking Gmail for user {user.username}: {e}")
                print(f"Error checking Gmail for user {user.username}. Exception: {e}")
            return 1

def check_gmail_for_bluesky():
    """Checks Gmail for new emails and triggers reactions if a new email is received."""
    actions = GmailReceivedAction.objects.all()
    
    for action in actions:
        user = action.user
        social_user = SocialUser.objects.filter(user=user, provider='google').first()
        
        if not social_user or not social_user.access_token:
            print(f"No Google access token found for user {user.username}")
            continue

        try:
            service = initialize_gmail_service(
                social_user.access_token,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_KEY,
                settings.SOCIAL_AUTH_GOOGLE_OAUTH2_SECRET,
                settings.AUTHORIZATION_URL_GOOGLE,
                'https://oauth2.googleapis.com/token'
            )

            two_minutes_ago = int((datetime.now(timezone.utc) - timedelta(minutes=2)).timestamp())
            response = service.users().messages().list(
                userId='me',
                q=f'after:{two_minutes_ago}'
            ).execute()
            
            messages = response.get('messages', [])
            reaction = BlueskyPostReaction.objects.filter(user=user).first()
            if messages and reaction:
                logger.info(f"New email detected for user {user.username}. Triggering reactions.")
                print("New email detected. Triggering reactions.")
                run_bluesky_reaction(reaction)
                return 0
            else:
                print(f"No Bluesky reaction found for user {user.username}")
                logger.error(f"No Bluesky reaction found for user {user.username}")
                
        except Exception as e:
            if 'invalid_client' in str(e) or 'invalid_grant' in str(e):
                logger.error(f"Authentication error for user {user.username}: {e}")
                print(f"Authentication error for user {user.username}. Please check OAuth credentials.")
            else:
                logger.error(f"Error checking Gmail for user {user.username}: {e}")
                print(f"Error checking Gmail for user {user.username}. Exception: {e}")
            return 1
     