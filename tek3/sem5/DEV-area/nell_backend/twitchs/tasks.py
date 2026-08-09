import requests
import logging
import random
from django.utils import timezone
from atproto import Client
from .models import *
from authentication.models import SocialUser
from django.conf import settings
from django.contrib.auth.models import User
from googlies.models import *

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def check_twitch_live(user):
    # Retrieve all social users for the logged-in user
    social_users = SocialUser.objects.filter(user=user)
    social_user = None

    # Find the social user with provider 'twitch'
    for su in social_users:
        if su.provider == 'twitch':
            social_user = su
            break

    # Check if a Twitch social user was found
    if not social_user:
        logger.error(f"No SocialUser with provider 'twitch' found for user {user.username}")
        return

    # Proceed to check live status if Twitch social user exists
    logger.info(f"Checking Twitch live status for channel: {social_user.provider_username}")

    response = requests.get(
        f'https://api.twitch.tv/helix/streams?user_login={social_user.provider_username}',
        headers={
            'Client-ID': settings.TWITCH_CLIENT_ID,
            'Authorization': f'Bearer {social_user.access_token}'
        }
    )
    data = response.json()
    logger.info(f"Twitch API response for {social_user.provider_username}: {data}")

    if data.get('data'):
        logger.info(f"Channel {social_user.provider_username} is live.")
        return True
    else:
        logger.info(f"Channel {social_user.provider_username} is not live.")
        return False

def post_to_bluesky(reaction):
    client = Client()
    try:
        # Print debug information for each variable from the reaction instance
        print("Debug Info:")
        print(f"User ID: {reaction.bluesky_user_id}")
        print(f"Handle: {reaction.bluesky_handle}")
        print(f"Password: {reaction.bluesky_password}")
        print(f"Message: {reaction.message}")

        # Attempt to log in using handle and password if available
        if reaction.bluesky_handle and reaction.bluesky_password:
            print("Attempting to log in with handle and password...")
            client.login(reaction.bluesky_handle, reaction.bluesky_password)
        else:
            logger.error(f"Missing credentials for Bluesky login for user {reaction.user}")
            return

        # Post the message to Bluesky
        print("Attempting to post message to Bluesky...")
        post = client.send_post(reaction.message)
        logger.info(f"Posted to Bluesky: {post.uri}")
    except AttributeError as e:
        logger.error(f"Login method missing or incorrect in Client class: {e}")
        print(f"Error: Login method missing or incorrect in Client class: {e}")
    except Exception as e:
        logger.error(f"Failed to post to Bluesky: {e}")
        print(f"Error: Failed to post to Bluesky: {e}")

def get_social_user_by_provider(user, provider):
    print(f"Attempting to retrieve SocialUser with provider '{provider}' for user: {user.username}")
    try:
        social_user = SocialUser.objects.get(user=user, provider=provider)
        print(f"Retrieved SocialUser: {social_user}")
        print(f"SocialUser provider: {social_user.provider}, username: {social_user.provider_username}, access token: {social_user.access_token}")
        return social_user
    except SocialUser.DoesNotExist:
        logger.error(f"No SocialUser with provider '{provider}' found for user {user.username}")
        return None

def run_spotify_reaction(user):
    """Plays the specified song on Spotify for the user."""
    print(f"Attempting to play Spotify song for user {user.username}")
    spotify_reaction = SpotifySongReaction.objects.filter(user=user).first()
    print(f"Spotify reaction found: {spotify_reaction}")

    if not spotify_reaction:
        logger.error(f"No Spotify song reaction found for user {user.username}")
        return

    social_users = SocialUser.objects.filter(user=user)
    social_user = None
    for su in social_users:
        if su.provider == 'spotify':
            social_user = su
            break

    if not social_user:
        logger.error(f"No SocialUser with provider 'spotify' found for user {user.username}")
        return

    print("Preparing Spotify request payload")
    print(f"provider: {social_user.provider}")
    print(f"scope: {settings.OAUTH_SCOPES['spotify']}")  # Print the actual using scope for this service
    headers = {
        "Authorization": f"Bearer {social_user.access_token}",
        "Content-Type": "application/json"
    }
    payload = {
        "uris": [spotify_reaction.song_uri]
    }
    print(f"Spotify headers: {headers}")
    print(f"Spotify payload: {payload}")

    try:
        print("Sending request to Spotify API to play song")
        response = requests.put("https://api.spotify.com/v1/me/player/play", headers=headers, json=payload)
        print(f"Spotify response status: {response.status_code}")
        print(f"Spotify response text: {response.text}")

        if response.status_code == 204:
            logger.info(f"Playing song {spotify_reaction.song_uri} on Spotify for user {user.username}")
            return 0
        else:
            logger.error(f"Failed to play song on Spotify: {response.text}")
            return 1
    except Exception as e:
        logger.error(f"Error playing song on Spotify for user {user.username}: {e}")