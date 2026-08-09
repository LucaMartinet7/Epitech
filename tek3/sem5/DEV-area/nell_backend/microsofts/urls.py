from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import *

router = DefaultRouter()
router.register(r'calendar-events', CalendarEventReactionViewSet)
router.register(r'drive-file-reactions', GoogleDriveFileReactionViewSet)
router.register(r'outlook-email-actions', OutlookEmailActionViewSet)
router.register(r'google-chat-reactions', GoogleChatMessageReactionViewSet)

urlpatterns = [
    path('trigger-onedrive-sync/', TriggerOneDriveToGoogleDriveSync.as_view(), name='trigger_onedrive_sync'),
    path('check-outlook-email/', OutlookEmailActionViewSet.as_view(), name='check_outlook_email'),
    path('trigger-google-chat/', GoogleChatMessageReactionViewSet.as_view(), name='trigger_google_chat'),
    path('trigger-calendar-event/', CalendarEventReactionViewSet.as_view(), name='trigger_calendar_event'),
    path('', include(router.urls)),
]
