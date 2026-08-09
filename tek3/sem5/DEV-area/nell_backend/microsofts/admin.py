from django.contrib import admin
from .models import *

admin.site.register(OutlookReaction)
admin.site.register(CalendarEventReaction)
admin.site.register(OneDriveFile)
admin.site.register(GoogleDriveFileReaction)
admin.site.register(OutlookEmailAction)
admin.site.register(GoogleChatMessageReaction)
