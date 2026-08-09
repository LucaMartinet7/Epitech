from django.shortcuts import redirect
from django.conf import settings
from django.http import JsonResponse
import spotipy
from spotipy.oauth2 import SpotifyOAuth
from rest_framework import viewsets, permissions
from rest_framework.response import Response
from rest_framework.views import APIView
from .models import *
from .serializers import *

def spotify_login(request):
    sp_oauth = SpotifyOAuth(
        client_id=settings.SPOTIFY_CLIENT_ID,
        client_secret=settings.SPOTIFY_CLIENT_SECRET,
        redirect_uri=settings.SPOTIFY_REDIRECT_URI,
        scope='user-read-private user-read-email playlist-read-private user-modify-playback-state user-read-currently-playing'
    )
    auth_url = sp_oauth.get_authorize_url()
    return redirect(auth_url)

def spotify_callback(request):
    sp_oauth = SpotifyOAuth(
        client_id=settings.SPOTIFY_CLIENT_ID,
        client_secret=settings.SPOTIFY_CLIENT_SECRET,
        redirect_uri=settings.SPOTIFY_REDIRECT_URI
    )
    
    token_info = sp_oauth.get_access_token(request.GET.get('code'))
    
    if not token_info:
        return JsonResponse({'error': 'Failed to get access token'}, status=400)

    request.session['spotify_access_token'] = token_info['access_token']
    request.session['spotify_refresh_token'] = token_info['refresh_token']
    request.session['spotify_token_expires_in'] = token_info['expires_at']

    return JsonResponse({
        'access_token': token_info['access_token'],
        'refresh_token': token_info['refresh_token'],
        'expires_in': token_info['expires_at']
    })

def get_user_playlists(request):
    access_token = request.session.get('spotify_access_token')
    
    if not access_token:
        return JsonResponse({'error': 'User not authenticated'}, status=401)

    sp = spotipy.Spotify(auth=access_token)
    
    playlists = sp.current_user_playlists()
    
    return JsonResponse(playlists)

def check_spotify_beatles(request):
    access_token = request.session.get('spotify_access_token')

    if not access_token:
        return JsonResponse({'error': 'User not authenticated'}, status=401)

    sp = spotipy.Spotify(auth=access_token)

    current_track = sp.current_playback()

    if not current_track or not current_track['is_playing']:
        return JsonResponse({'error': 'No song is currently playing'}, status=400)

    track_name = current_track['item']['name']
    artist_name = current_track['item']['artists'][0]['name']

    if artist_name.lower() == "the beatles":
        SpotifyAction.objects.create(
            user=request.user,
            track_name=track_name,
            artist_name=artist_name,
            spotify_user_id=current_track['device']['id']  # Save to db
        )
        return JsonResponse({'message': f"You're listening to a Beatles song: {track_name}"}, status=200)

    return JsonResponse({'message': f"You're listening to {artist_name}, not The Beatles."}, status=200)

def play_spotify_playlist(request): #play first playlist of the user
    access_token = request.session.get('spotify_access_token')
    if not access_token:
        return JsonResponse({'error': 'User not authenticated on Spotify'}, status=401)

    sp = spotipy.Spotify(auth=access_token)
    playlists = sp.current_user_playlists()
    if not playlists['items']:
        return JsonResponse({'error': 'No playlists found for user'}, status=404)

    playlist_id = playlists['items'][0]['id']
    sp.start_playback(context_uri=f'spotify:playlist:{playlist_id}')
    
    return JsonResponse({'message': f'Spotify playlist "{playlists["items"][0]["name"]}" is now playing.'})

class SpotifySongActionViewSet(viewsets.ModelViewSet):
    queryset = SpotifySongAction.objects.all()
    serializer_class = SpotifySongActionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)

class TwitchChatReactionViewSet(viewsets.ModelViewSet):
    queryset = TwitchChatReaction.objects.all()
    serializer_class = TwitchChatReactionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)
