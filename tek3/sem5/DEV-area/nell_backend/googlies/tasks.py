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

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def initialize_gmail_service(access_token, refresh_token, client_id, client_secret, token_uri):
    credentials = Credentials(
        token=access_token,
        refresh_token=refresh_token,
        client_id=client_id,
        client_secret=client_secret,
        token_uri=token_uri
    )
    service = build('gmail', 'v1', credentials=credentials)
    return service

def run_spotify_reaction(user):
    """Plays the specified song on Spotify for the user."""
    spotify_reaction = SpotifySongReaction.objects.filter(user=user).first()
    
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

    headers = {
        "Authorization": f"Bearer {social_user.access_token}",
        "Content-Type": "application/json"
    }
    payload = {
        "uris": [spotify_reaction.song_uri]
    }

    try:
        response = requests.put("https://api.spotify.com/v1/me/player/play", headers=headers, json=payload)
        
        if response.status_code == 204:
            logger.info(f"Playing song {spotify_reaction.song_uri} on Spotify for user {user.username}")
            return 0
        else:
            logger.error(f"Failed to play song on Spotify: {response.text}")
            return 1
    except Exception as e:
        logger.error(f"Error playing song on Spotify for user {user.username}: {e}")

def run_add_song_to_first_playlist_reaction(user):
    """Adds a song from the user's SpotifySongReaction to the user's first Spotify playlist."""
    social_user = SocialUser.objects.filter(user=user, provider='spotify').first()
    if not social_user or not social_user.access_token:
        logger.error(f"No Spotify access token found for user {user.username}")
        return

    headers = {
        "Authorization": f"Bearer {social_user.access_token}",
        "Content-Type": "application/json"
    }

    try:
        playlists_response = requests.get("https://api.spotify.com/v1/me/playlists", headers=headers)

        if playlists_response.status_code != 200:
            logger.error(f"Failed to retrieve playlists for user {user.username}: {playlists_response.text}")
            return
        
        playlists_data = playlists_response.json()
        if not playlists_data['items']:
            print(f"No playlists found for user {user.username}")
            return

        first_playlist_id = playlists_data['items'][0]['id']

    except Exception as e:
        logger.error(f"Error retrieving playlists for user {user.username}: {e}")
        return

    spotify_reaction = SpotifySongReaction.objects.filter(user=user).first()
    if not spotify_reaction:
        logger.error(f"No Spotify song reaction found for user {user.username}")
        return

    payload = {
        "uris": "spotify:track:2D0oBeewyuUfaK8fwQD9uL"
    }
    print(f"Adding song {spotify_reaction.song_uri} to playlist {first_playlist_id}")

    try:
        add_song_url = f"https://api.spotify.com/v1/playlists/{first_playlist_id}/tracks"
        response = requests.post(add_song_url, headers=headers, json=payload)
        
        print(f"Add song response status: {response.status_code}")
        if response.status_code == 201:
            logger.info(f"Successfully added song {spotify_reaction.song_uri} to playlist {first_playlist_id} for user {user.username}")
            return 0
        else:
            logger.error(f"Failed to add song to playlist: {response.text}")
            return 1
    except Exception as e:
        logger.error(f"Error adding song to Spotify playlist for user {user.username}: {e}")

def run_twitch_reaction(user):
    """Sends a message to the Twitch chat for the user's channel."""
    twitch_reaction = TwitchChatReaction.objects.filter(user=user).first()
    
    if not twitch_reaction:
        logger.error(f"No Twitch chat reaction found for user {user.username}")
        return
    
    social_user = SocialUser.objects.filter(user=user, provider='twitch').first()
    if not social_user:
        logger.error(f"No SocialUser with provider 'twitch' found for user {user.username}")
        return

    headers = {
        'Authorization': f'Bearer {social_user.access_token}',
        'Client-Id': settings.TWITCH_CLIENT_ID,
        'Content-Type': 'application/json'
    }

    broadcaster_id = social_user.provider_id
    sender_id = social_user.provider_id

    if not broadcaster_id or not sender_id:
        logger.error(f"SocialUser does not have a valid broadcaster_id or sender_id for user {user.username}")
        return

    payload = {
        "message": twitch_reaction.message_content,
        "channel_name": twitch_reaction.channel_name,
        "broadcaster_id": broadcaster_id,
        "sender_id": sender_id
    }

    try:
        response = requests.post("https://api.twitch.tv/helix/chat/messages", headers=headers, json=payload)
        if response.status_code == 200:
            logger.info(f"Message posted to Twitch chat for user {user.username}")
            return 0
        else:
            logger.error(f"Failed to post message to Twitch chat: {response.text}")
            return 1
    except Exception as e:
        logger.error(f"Error sending message to Twitch chat for user {user.username}: {e}")

def run_bluesky_reaction(reaction):
    client = Client()
    try:
        
        if reaction.bluesky_handle and reaction.bluesky_password:
            print("Attempting to log in with handle and password...")
            client.login(reaction.bluesky_handle, reaction.bluesky_password)
        else:
            logger.error(f"Missing credentials for Bluesky login for user {reaction.user}")
            return

        post = client.send_post(reaction.message)
        logger.info(f"Posted to Bluesky: {post.uri}")
    except AttributeError as e:
        logger.error(f"Login method missing or incorrect in Client class: {e}")
        print(f"Error: Login method missing or incorrect in Client class: {e}")
    except Exception as e:
        logger.error(f"Failed to post to Bluesky: {e}")
        print(f"Error: Failed to post to Bluesky: {e}")
   
def check_bluesky_for_spotify():
    """Checks for new posts on Bluesky by the user and triggers Spotify reaction if found."""
    reactions = BlueskyPostReaction.objects.all()
    client = Client()

    for reaction in reactions:
        user = reaction.user
        print(f"Processing action for user {user.username}")

        try:
            if reaction.bluesky_handle and reaction.bluesky_password:
                print("Attempting to log in with handle and password...")
                client.login(reaction.bluesky_handle, reaction.bluesky_password)
            else:
                logger.error(f"Missing credentials for Bluesky login for user {user.username}")
                continue

            ten_minutes_ago = datetime.now() - timedelta(minutes=10)
            print(f"Checking for posts made after: {ten_minutes_ago}")

            posts_response = None
            posts_response = client.get_author_feed(reaction.bluesky_user_id, limit=10)

            if posts_response:
                logger.info(f"New posts found for user {user.username}. Triggering Spotify reaction.")
                run_spotify_reaction(user)
                return 0
            else:
                print("No new posts found in the last 10 minutes.")
        
        except Exception as e:
            logger.error(f"Error checking Bluesky posts for user {user.username}: {e}")
            print(f"Error checking Bluesky posts for user {user.username}: {e}")
            return 1
        
def check_bluesky_for_twitch():
    """Checks for new posts on Bluesky by the user and triggers Spotify reaction if found."""
    reactions = BlueskyPostReaction.objects.all()
    client = Client()

    for reaction in reactions:
        user = reaction.user
        print(f"Processing action for user {user.username}")

        try:
            if reaction.bluesky_handle and reaction.bluesky_password:
                print("Attempting to log in with handle and password...")
                client.login(reaction.bluesky_handle, reaction.bluesky_password)
            else:
                logger.error(f"Missing credentials for Bluesky login for user {user.username}")
                continue

            ten_minutes_ago = datetime.now() - timedelta(minutes=10)
            print(f"Checking for posts made after: {ten_minutes_ago}")

            posts_response = None
            posts_response = client.get_author_feed(reaction.bluesky_user_id, limit=10)

            if posts_response:
                logger.info(f"New posts found for user {user.username}. Triggering Spotify reaction.")
                run_twitch_reaction(user)
                return 0
            else:
                print("No new posts found in the last 10 minutes.")
        
        except Exception as e:
            logger.error(f"Error checking Bluesky posts for user {user.username}: {e}")
            print(f"Error checking Bluesky posts for user {user.username}: {e}")
            return 1
