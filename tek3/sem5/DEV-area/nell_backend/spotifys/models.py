from django.db import models
from django.contrib.auth.models import User

class SpotifyAction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    track_name = models.CharField(max_length=255)
    artist_name = models.CharField(max_length=255)
    spotify_user_id = models.CharField(max_length=255, blank=True, null=True)
    created_at = models.DateTimeField(auto_now_add=True)
    
    def __str__(self):
        return f"{self.user.username} - {self.artist_name}: {self.track_name}"

class SpotifySongAction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    song_name = models.CharField(max_length=255)
    artist_name = models.CharField(max_length=255)
    album_name = models.CharField(max_length=255)
    song_id = models.CharField(max_length=255, unique=True)
    played_at = models.DateTimeField()
    processed = models.BooleanField(default=False)

    def __str__(self):
        return f"Spotify Song: {self.song_name} by {self.artist_name}"

class TwitchChatReaction(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    channel_name = models.CharField(max_length=255)
    message_content = models.TextField()
    song_name = models.CharField(max_length=255)
    posted_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"Twitch Chat Message for song: {self.song_name}"
