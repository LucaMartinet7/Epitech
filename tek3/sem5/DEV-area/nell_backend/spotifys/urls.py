from django.urls import path, include
from .views import *
from rest_framework.routers import DefaultRouter
from .views import *

router = DefaultRouter()
router.register(r'spotify-song-actions', SpotifySongActionViewSet)
router.register(r'twitch-chat-reactions', TwitchChatReactionViewSet)

urlpatterns = [
    path('login/', spotify_login, name='spotify_login'),
    path('callback/', spotify_callback, name='spotify_callback'),
    path('playlists/', get_user_playlists, name='get_user_playlists'),
    path('check-beatles/', check_spotify_beatles, name='check_spotify_beatles'),
    #path('check-spotify-song/', SpotifySongActionViewSet.as_view(), name='check_spotify_song'),
    path('send-twitch-message/', TwitchChatReactionViewSet.as_view(), name='send_twitch_message'),
    path('', include(router.urls)),
]
