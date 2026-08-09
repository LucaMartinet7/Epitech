from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import *

router = DefaultRouter()
router.register(r'youtube-actions', YouTubeActionViewSet, basename='youtube-action')
router.register(r'spotify-reactions', SpotifyPlaylistReactionViewSet, basename='spotify-reaction')
router.register(r'youtube-actions', YouTubeSubscriptionActionView, basename='youtube-action')
router.register(r'outlook-reactions', OutlookEmailReactionView, basename='outlook-reaction')

urlpatterns = [
    path('', include(router.urls)),
    path('check-youtube-upload/', CheckYouTubeVideoUploadView.as_view(), name='check_youtube_upload'),
    path('check-youtube-watch/', CheckYouTubeWatchView.as_view(), name='check_youtube_watch'),
    path('setup-youtube-channel/', YouTubeChannelSetupView.as_view(), name='setup_youtube_channel'),
    path('youtube-action/', YouTubeSubscriptionActionView.as_view(), name='youtube_action'),
    path('outlook-reaction/', OutlookEmailReactionView.as_view(), name='outlook_reaction'),
    path('trigger-check/', TriggerYouTubeCheckView.as_view(), name='trigger_check'),
]
