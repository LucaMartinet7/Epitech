from django.contrib import admin
from .models import *

admin.site.register(GmailReceivedAction)
admin.site.register(TwitchChatReaction)
admin.site.register(SpotifySongReaction)