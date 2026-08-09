from django.db import models
from django.contrib.auth.models import User

class TwitchLiveAction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    channel_status = models.BooleanField(default=False)
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"{self.user.username} - Twitch Channel Live: {self.channel_status}"

class BlueskyPostReaction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    message = models.CharField(max_length=255)
    bluesky_handle = models.CharField(max_length=255, default='')
    bluesky_user_id = models.CharField(max_length=255, blank=True, null=True)
    bluesky_password = models.CharField(max_length=255, blank=True, null=True)
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"{self.user.username} - Bluesky Post: {self.message}"

class TwitchFollowerAction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    twitch_user_id = models.CharField(max_length=255)
    client_id = models.CharField(max_length=255)
    access_token = models.CharField(max_length=255)
    last_checked = models.DateTimeField(auto_now=True)
    last_follower_count = models.PositiveIntegerField(default=0)

    def __str__(self):
        return f"Twitch Follower Action for {self.user.username} - User ID: {self.twitch_user_id}"

class SpotifyPlaylistAddSongReaction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    spotify_playlist_id = models.CharField(max_length=255)
    spotify_access_token = models.CharField(max_length=255)

    def __str__(self):
        return f"Spotify Playlist Reaction for {self.user.username} - Playlist ID: {self.spotify_playlist_id}"
