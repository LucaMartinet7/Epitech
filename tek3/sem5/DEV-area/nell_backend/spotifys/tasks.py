# tasks.py
import requests
import logging
from django.utils import timezone
from .models import SpotifySongAction, TwitchChatReaction

logger = logging.getLogger(__name__)

def check_spotify_new_song(user_id, access_token):
    logger.info(f"Checking Spotify for new song playback for user: {user_id}")
    
    url = "https://api.spotify.com/v1/me/player/currently-playing"
    headers = {
        'Authorization': f'Bearer {access_token}',
        'Content-Type': 'application/json'
    }
    
    response = requests.get(url, headers=headers)
    data = response.json()
    
    if response.status_code != 200 or not data:
        logger.error(f"Error fetching Spotify data: {data}")
        return None

    song_id = data['item']['id']
    song_name = data['item']['name']
    artist_name = ', '.join([artist['name'] for artist in data['item']['artists']])
    album_name = data['item']['album']['name']
    played_at = timezone.datetime.fromisoformat(data['timestamp'] / 1000).replace(tzinfo=timezone.utc)

    song_obj, created = SpotifySongAction.objects.get_or_create(
        user_id=user_id,
        song_id=song_id,
        defaults={
            'song_name': song_name,
            'artist_name': artist_name,
            'album_name': album_name,
            'played_at': played_at,
            'processed': False
        }
    )

    if created or not song_obj.processed:
        send_message_to_twitch_chat(user_id, song_obj)
        song_obj.processed = True
        song_obj.save()

def send_message_to_twitch_chat(user_id, song):
    logger.info(f"Sending message to Twitch chat for song: {song.song_name}")

    # Twitch API endpoint for sending chat message
    twitch_url = f"https://api.twitch.tv/helix/chat/messages"
    twitch_access_token = "YOUR_TWITCH_ACCESS_TOKEN"  # Make sure this is securely stored and retrieved
    twitch_client_id = "YOUR_TWITCH_CLIENT_ID"  # Required for Twitch API requests
    message_content = f"Now playing on Spotify: {song.song_name} by {song.artist_name}!"

    headers = {
        'Authorization': f'Bearer {twitch_access_token}',
        'Client-Id': twitch_client_id,
        'Content-Type': 'application/json'
    }
    payload = {
        "content": message_content,
        "channel_name": TwitchChatReaction.channel_name
    }

    response = requests.post(twitch_url, headers=headers, json=payload)
    
    if response.status_code == 204:
        TwitchChatReaction.objects.create(
            user_id=user_id,
            channel_name=payload['channel_name'],
            message_content=message_content,
            song_name=song.song_name
        )
        logger.info(f"Message posted to Twitch chat for song: {song.song_name}")
    else:
        logger.error(f"Failed to post message to Twitch chat: {response.text}")
