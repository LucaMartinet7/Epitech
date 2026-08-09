from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import *
from .views import CheckAndPlaySpotifyView

urlpatterns = [
# Individual APIView endpoints
    path('check-twitch-live/', ChannelStatusCheckView.as_view(), name='check-twitch-live'),
    path('post-to-bluesky/', PostToBlueskyView.as_view(), name='post-to-bluesky'),
    path('setup-bluesky-user/', GetBlueskyUserIDView.as_view(), name='setup-bluesky-user'),
    path('area-twitchlive-bluesky/', CheckAndPostToBlueskyView.as_view(), name='area-twitchlive-bluesky'),
    path('area-twitchlive-spotify/', CheckAndPlaySpotifyView.as_view(), name='area-twitchlive-spotify'),
    
    # Manually defined paths for ViewSet actions
    path('twitch-live-actions/', TwitchLiveActionViewSet.as_view({'get': 'list', 'post': 'create'}), name='twitch-live-action-list'),
    path('twitch-live-actions/<int:pk>/', TwitchLiveActionViewSet.as_view({'get': 'retrieve', 'put': 'update', 'delete': 'destroy'}), name='twitch-live-action-detail'),

    path('bluesky-post-reactions/', BlueskyPostReactionViewSet.as_view({'get': 'list', 'post': 'create'}), name='bluesky-post-reaction-list'),
    path('bluesky-post-reactions/<int:pk>/', BlueskyPostReactionViewSet.as_view({'get': 'retrieve', 'put': 'update', 'delete': 'destroy'}), name='bluesky-post-reaction-detail'),
]
