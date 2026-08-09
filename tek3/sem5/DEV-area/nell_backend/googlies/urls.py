from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import *
from .views_area import *

urlpatterns = [
    path('gmail-received-action/', GmailReceivedActionViewSet.as_view({'get': 'list', 'post': 'create'}), name='gmail-received-action'),
    path('set-gmail-trigger/', SetGmailTriggerView.as_view(), name='set-gmail-trigger'),
    path('run-spotify-reaction/', RunSpotifyReaction.as_view(), name='run-spotify-reaction'),
    path('run-twitch-reaction/', RunTwitchReaction.as_view(), name='run-twitch-reaction'),
    path('check-for-new-emails/', CheckGmailNew.as_view(), name='check-for-new-emails'),
    path('check-for-new-emails/', CheckGmailNew.as_view(), name='check-for-new-emails'),

    # AREA STUFF
    path('area-check-gmail-spotify/', AREACheckGmailSpotify.as_view(), name='check-gmail-spotify'),
    path('area-check-gmail-twitch/', AREACheckGmailTwitch.as_view(), name='check-gmail-twitch'),
    path('area-check-gmail-bluesky/', AREACheckGmailBluesky.as_view(), name='check-gmail-bluesky'),
    path('area-check-bluesky-spotify/', AREACheckBlueskySpotify.as_view(), name='check-spotify-bluesky'),
    path('area-check-bluesky-twitch/', AREACheckBlueskyTwitch.as_view(), name='check-spotify-twitch'),
    path('area-check-spotify-twitch/',AREACheckSpotifyPlayTwitch.as_view(), name='check-spotify-twitch'),
    path('area-check-spotify-bluesky/',AREACheckSpotifyPlayBluesky.as_view(), name='check-spotify-bluesky'),
    path('area-check-youtube-twitch/',AREACheckYoutubeTwitch.as_view(), name='check-youtube-twitch'),
    path('area-check-youtube-spotify/',AREACheckYoutubeSpotify.as_view(), name='check-youtube-spotify'),
    path('area-check-youtube-bluesky/',AREACheckYoutubeBluesky.as_view(), name='check-youtube-bluesky'),
]