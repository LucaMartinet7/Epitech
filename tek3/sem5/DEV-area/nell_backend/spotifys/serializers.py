from rest_framework import serializers
from .models import *

class SpotifyActionSerializer(serializers.ModelSerializer):
    class Meta:
        model = SpotifyAction
        fields = '__all__'

class SpotifySongActionSerializer(serializers.ModelSerializer):
    class Meta:
        model = SpotifySongAction
        fields = '__all__'

class TwitchChatReactionSerializer(serializers.ModelSerializer):
    class Meta:
        model = TwitchChatReaction
        fields = '__all__'
