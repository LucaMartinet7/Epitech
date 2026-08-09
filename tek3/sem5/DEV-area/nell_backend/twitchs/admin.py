from django.contrib import admin
from .models import TwitchLiveAction, BlueskyPostReaction

admin.site.register(TwitchLiveAction)
admin.site.register(BlueskyPostReaction)