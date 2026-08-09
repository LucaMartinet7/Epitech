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

def check_spotify_playback():
    """Checks Spotify playback status for users and triggers reactions if currently playing a track."""
    actions = SpotifySongReaction.objects.all()
    
    for action in actions:
        user = action.user
        social_user = SocialUser.objects.filter(user=user, provider='spotify').first()
        
        if not social_user or not social_user.access_token:
            print(f"No Spotify access token found for user {user.username}")
            continue
    
        try:
            response = requests.get("https://api.spotify.com/v1/me/player", headers={
                "Authorization": f"Bearer {social_user.access_token}",
                "Content-Type": "application/json"
            })

            if response.status_code == 200:
                playback_info = response.json()
                is_playing = playback_info.get('is_playing', False)
                if is_playing:
                    print(f"User {user.username} is currently playing a track.")
                    run_twitch_reaction(user)  # Trigger the reaction if playing
                else:
                    print(f"User {user.username} is not currently playing any track.")
            else:
                logger.error(f"Failed to check playback status for user {user.username}: {response.text}")

        except Exception as e:
            logger.error(f"Error checking Spotify playback for user {user.username}: {e}")
            print(f"Error checking Spotify playback for user {user.username}. Exception: {e}")

def check_spotify_playback_for_twitch():
    """Checks Spotify playback status for users and triggers reactions if currently playing a track."""
    actions = SpotifySongReaction.objects.all()

    for action in actions:
        user = action.user
        social_user = SocialUser.objects.filter(user=user, provider='spotify').first()
        
        if not social_user or not social_user.access_token:
            print(f"No Spotify access token found for user {user.username}")
            continue
      
        try:
            response = requests.get("https://api.spotify.com/v1/me/player", headers={
                "Authorization": f"Bearer {social_user.access_token}",
                "Content-Type": "application/json"
            })

            print(f"Spotify playback response status: {response.status_code}")
            if response.status_code == 200:
                playback_info = response.json()
                is_playing = playback_info.get('is_playing', False)
                if is_playing:
                    print(f"User {user.username} is currently playing a track.")
                    run_twitch_reaction(user)  # Trigger the reaction if playing
                    return 0
                else:
                    print(f"User {user.username} is not currently playing any track.")
            else:
                logger.error(f"Failed to check playback status for user {user.username}: {response.text}")

        except Exception as e:
            logger.error(f"Error checking Spotify playback for user {user.username}: {e}")
            print(f"Error checking Spotify playback for user {user.username}. Exception: {e}")
            return 1

def check_spotify_playback_for_bluesky():
    """Checks Spotify playback status for users and triggers reactions if currently playing a track."""
    actions = SpotifySongReaction.objects.all()
 
    for action in actions:
        user = action.user
        social_user = SocialUser.objects.filter(user=user, provider='spotify').first()
        
        if not social_user or not social_user.access_token:
            print(f"No Spotify access token found for user {user.username}")
            continue
      
        try:
            response = requests.get("https://api.spotify.com/v1/me/player", headers={
                "Authorization": f"Bearer {social_user.access_token}",
                "Content-Type": "application/json"
            })

            print(f"Spotify playback response status: {response.status_code}")
            reaction = BlueskyPostReaction.objects.filter(user=user).first()
            if response.status_code == 200:
                playback_info = response.json()
                is_playing = playback_info.get('is_playing', False)
                if is_playing:
                    print(f"User {user.username} is currently playing a track.")
                    run_bluesky_reaction(reaction)  # Trigger the reaction if playing
                    return 0
                else:
                    print(f"User {user.username} is not currently playing any track.")
            else:
                logger.error(f"Failed to check playback status for user {user.username}: {response.text}")

        except Exception as e:
            logger.error(f"Error checking Spotify playback for user {user.username}: {e}")
            print(f"Error checking Spotify playback for user {user.username}. Exception: {e}")
            return 1
