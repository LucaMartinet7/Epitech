from rest_framework import serializers
from .models import *

class YouTubeActionSerializer(serializers.ModelSerializer):
    class Meta:
        model = YouTubeAction
        fields = '__all__'

class SpotifyPlaylistReactionSerializer(serializers.ModelSerializer):
    class Meta:
        model = SpotifyPlaylistReaction
        fields = '__all__'

class YouTubeSubscriptionActionSerializer(serializers.ModelSerializer):
    class Meta:
        model = YouTubeSubscriptionAction
        fields = '__all__'

class OutlookEmailReactionSerializer(serializers.ModelSerializer):
    class Meta:
        model = OutlookEmailReaction
        fields = '__all__'
