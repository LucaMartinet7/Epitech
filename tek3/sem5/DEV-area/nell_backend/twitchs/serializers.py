from rest_framework import serializers
from .models import *

class TwitchLiveActionSerializer(serializers.ModelSerializer):
    class Meta:
        model = TwitchLiveAction
        fields = '__all__'

class BlueskyPostReactionSerializer(serializers.ModelSerializer):
    class Meta:
        model = BlueskyPostReaction
        fields = '__all__'

class BlueskyUserIDRequestSerializer(serializers.Serializer):
    bluesky_handle = serializers.CharField(max_length=255)
    bluesky_password = serializers.CharField(max_length=255)
    message = serializers.CharField(max_length=255)

class TwitchFollowerActionSerializer(serializers.ModelSerializer):
    class Meta:
        model = TwitchFollowerAction
        fields = '__all__'

class SpotifyPlaylistAddSongReactionSerializer(serializers.ModelSerializer):
    class Meta:
        model = SpotifyPlaylistAddSongReaction
        fields = '__all__'
