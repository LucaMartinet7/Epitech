import requests
import logging
from datetime import datetime, timezone
from .models import *
from spotipy import Spotify
from spotipy.oauth2 import SpotifyOAuth

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def check_youtube_video_upload():
    actions = YouTubeAction.objects.filter(action_type='upload')
    for action in actions:
        logger.info(f"Checking YouTube uploads for channel ID: {action.channel_id}")
        response = requests.get(
            f'https://www.googleapis.com/youtube/v3/activities?part=snippet,contentDetails&channelId={action.channel_id}&key={action.api_key}'
        )
        data = response.json()
        logger.info(f"YouTube API response for {action.channel_id}: {data}")

        if 'items' in data:
            latest_video_timestamp = data['items'][0]['snippet']['publishedAt']
            latest_video_datetime = datetime.fromisoformat(latest_video_timestamp.replace("Z", "+00:00"))

            if action.last_checked < latest_video_datetime:
                logger.info(f"New video uploaded by channel {action.channel_id} since last check.")
                action.last_checked = latest_video_datetime
                action.save()
                create_spotify_playlist(action.user)

def create_spotify_playlist(user):
    reaction = SpotifyPlaylistReaction.objects.filter(user=user).first()
    if reaction:
        sp = Spotify(auth=reaction.access_token)
        playlist_name = f"New Videos by {user.username}"
        
        playlist = sp.user_playlist_create(reaction.spotify_user_id, playlist_name, public=True)
        
        if playlist:
            logger.info(f"Spotify playlist created: {playlist['id']}")
        else:
            logger.error(f"Failed to create playlist for user {user}")

def check_youtube_watch():
    actions = YouTubeAction.objects.filter(action_type='subscription')
    for action in actions:
        logger.info(f"Checking YouTube watch history for user: {action.user}")

        response = requests.get(
            f'https://www.googleapis.com/youtube/v3/activities?part=snippet&channelId={action.channel_id}&key={action.api_key}'
        )
        data = response.json()
        
        video_watched = False
        if 'items' in data:
            current_time = datetime.now()
            for item in data['items']:
                if item['snippet']['type'] == 'watchHistory' and 'publishedAt' in item['snippet']:
                    video_timestamp = item['snippet']['publishedAt']
                    video_datetime = datetime.fromisoformat(video_timestamp.replace("Z", "+00:00"))
                    
                    # Check if the video was watched very recently (within last minute)
                    if (current_time - video_datetime).total_seconds() < 60:
                        video_watched = True
                        logger.info(f"User {action.user} is currently watching a video.")
                        break
        if video_watched:
            play_spotify_track(action.user)

def play_spotify_track(user):
    reaction = SpotifyPlaylistReaction.objects.filter(user=user).first()
    if reaction:
        sp = Spotify(auth=reaction.access_token)
        track_uri = "spotify:track:2TpxZ7JUBn3uw46aR7qd6V"  # Crazy Frog Axel F URI

        devices = sp.devices()
        if devices['devices']:
            device_id = devices['devices'][0]['id']  # Use the first available device
            sp.start_playback(device_id=device_id, uris=[track_uri])
            logger.info(f"Playing 'Crazy Frog Axel F' for user {user}")
        else:
            logger.error(f"No active Spotify device found for user {user}")

def check_youtube_subscription():
    actions = YouTubeSubscriptionAction.objects.all()
    for action in actions:
        logger.info(f"Checking YouTube subscription for channel ID: {action.channel_id}")
        
        response = requests.get(
            'https://www.googleapis.com/youtube/v3/channels',
            params={
                'part': 'statistics',
                'id': action.channel_id,
                'key': action.api_key
            }
        )
        data = response.json()
        logger.info(f"YouTube API response for channel {action.channel_id}: {data}")

        if 'items' in data and len(data['items']) > 0:
            current_subscriber_count = int(data['items'][0]['statistics']['subscriberCount'])

            if current_subscriber_count > action.last_subscriber_count:
                logger.info(f"New subscription detected for {action.channel_id}. Triggering reaction.")
                send_outlook_email(action)

            action.last_subscriber_count = current_subscriber_count
            action.last_checked = timezone.now()
            action.save()

def send_outlook_email(action):
    email_reaction = OutlookEmailReaction.objects.filter(user=action.user).first()
    
    if email_reaction:
        try:
            subject = email_reaction.subject_template.format(subscriber_name="New Subscriber")
            body = email_reaction.body_template.format(subscriber_name="New Subscriber")

            response = requests.post(
                'https://graph.microsoft.com/v1.0/me/sendMail',
                headers={
                    'Authorization': f'Bearer YOUR_ACCESS_TOKEN',
                    'Content-Type': 'application/json'
                },
                json={
                    'message': {
                        'subject': subject,
                        'body': {
                            'contentType': 'Text',
                            'content': body
                        },
                        'toRecipients': [
                            {'emailAddress': {'address': email_reaction.user_email}}
                        ]
                    },
                    'saveToSentItems': 'true'
                }
            )
            if response.status_code == 202:
                logger.info(f"Email sent successfully to {email_reaction.user_email}")
            else:
                logger.error(f"Failed to send email. Response: {response.json()}")

        except Exception as e:
            logger.error(f"An error occurred while sending email: {e}")
