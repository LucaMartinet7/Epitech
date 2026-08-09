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

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def check_user_subscription(user, channel_id):
    """Checks if the user is subscribed to a specific YouTube channel."""
    social_user = SocialUser.objects.filter(user=user, provider='google').first()

    if not social_user or not social_user.access_token:
        logger.error(f"No YouTube access token found for user {user.username}")
        return None 

    headers = {
        "Authorization": f"Bearer {social_user.access_token}",
        "Content-Type": "application/json"
    }

    try:
        response = requests.get(
            f"https://www.googleapis.com/youtube/v3/subscriptions?part=snippet&forChannelId={channel_id}&mine=true",
            headers=headers
        )

        if response.status_code == 200:
            subscriptions_info = response.json()
            if 'items' in subscriptions_info and len(subscriptions_info['items']) > 0:
                print(f"User {user.username} is subscribed to channel {channel_id}.")
            else:
                print(f"User {user.username} is not subscribed to channel {channel_id}.")
        else:
            logger.error(f"Failed to check subscriptions for user {user.username}: {response.text}")

    except Exception as e:
        logger.error(f"Error checking subscription status for channel {channel_id} for user {user.username}: {e}")

def check_user_subscription_for_twitch(user, channel_id):
    """Checks if the user is subscribed to a specific YouTube channel."""
    
    social_user = SocialUser.objects.filter(user=user, provider='google').first()

    if not social_user or not social_user.access_token:
        logger.error(f"No YouTube access token found for user {user.username}")
        return None 

    headers = {
        "Authorization": f"Bearer {social_user.access_token}",
        "Content-Type": "application/json"
    }

    try:
        response = requests.get(
            f"https://www.googleapis.com/youtube/v3/subscriptions?part=snippet&forChannelId={channel_id}&mine=true",
            headers=headers
        )

        if response.status_code == 200:
            subscriptions_info = response.json()
            if 'items' in subscriptions_info and len(subscriptions_info['items']) > 0:
                print(f"User {user.username} is subscribed to channel {channel_id}.")
                run_twitch_reaction(user)
                return 0
            else:
                print(f"User {user.username} is not subscribed to channel {channel_id}.")
        else:
            logger.error(f"Failed to check subscriptions for user {user.username}: {response.text}")

    except Exception as e:
        logger.error(f"Error checking subscription status for channel {channel_id} for user {user.username}: {e}")
        return 1

def check_user_subscription_for_spotify(user, channel_id):
    """Checks if the user is subscribed to a specific YouTube channel."""

    social_user = SocialUser.objects.filter(user=user, provider='google').first()

    if not social_user or not social_user.access_token:
        logger.error(f"No YouTube access token found for user {user.username}")
        return None 

    headers = {
        "Authorization": f"Bearer {social_user.access_token}",
        "Content-Type": "application/json"
    }

    try:
        response = requests.get(
            f"https://www.googleapis.com/youtube/v3/subscriptions?part=snippet&forChannelId={channel_id}&mine=true",
            headers=headers
        )

        if response.status_code == 200:
            subscriptions_info = response.json()
            # Check if the response contains subscription items
            if 'items' in subscriptions_info and len(subscriptions_info['items']) > 0:
                print(f"User {user.username} is subscribed to channel {channel_id}.")
                run_spotify_reaction(user)
                return 0
            else:
                print(f"User {user.username} is not subscribed to channel {channel_id}.")
        else:
            logger.error(f"Failed to check subscriptions for user {user.username}: {response.text}")

    except Exception as e:
        logger.error(f"Error checking subscription status for channel {channel_id} for user {user.username}: {e}")
        return 1

def check_user_subscription_for_bluesky(user, channel_id):
    """Checks if the user is subscribed to a specific YouTube channel."""
    social_user = SocialUser.objects.filter(user=user, provider='google').first()

    if not social_user or not social_user.access_token:
        logger.error(f"No YouTube access token found for user {user.username}")
        return None 

    headers = {
        "Authorization": f"Bearer {social_user.access_token}",
        "Content-Type": "application/json"
    }

    try:
        response = requests.get(
            f"https://www.googleapis.com/youtube/v3/subscriptions?part=snippet&forChannelId={channel_id}&mine=true",
            headers=headers
        )
        reaction = BlueskyPostReaction.objects.filter(user=user).first()
        if response.status_code == 200:
            subscriptions_info = response.json()
            if 'items' in subscriptions_info and len(subscriptions_info['items']) > 0:
                print(f"User {user.username} is subscribed to channel {channel_id}.")
                run_bluesky_reaction(reaction)
                return 0
            else:
                print(f"User {user.username} is not subscribed to channel {channel_id}.")
        else:
            logger.error(f"Failed to check subscriptions for user {user.username}: {response.text}")

    except Exception as e:
        logger.error(f"Error checking subscription status for channel {channel_id} for user {user.username}: {e}")
        return 1
