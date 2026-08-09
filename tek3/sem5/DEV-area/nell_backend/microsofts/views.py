import requests
import msal
from django.core.mail import send_mail
from django.conf import settings
from django.shortcuts import redirect, render
from django.http import JsonResponse
from rest_framework import viewsets, permissions, status
from rest_framework.response import Response
from rest_framework.views import APIView
from .models import *
from .serializers import *
from .tasks import *

class CalendarEventReactionViewSet(viewsets.ModelViewSet):
    queryset = CalendarEventReaction.objects.all()
    serializer_class = CalendarEventReactionSerializer
    permission_classes = [permissions.IsAuthenticated]

class TriggerOneDriveToGoogleDriveSync(APIView):
    def post(self, request):
        user_id = request.user.id
        access_token = request.data.get('access_token')

        check_onedrive_for_new_file(user_id, access_token)
        return Response({"message": "OneDrive to Google Drive sync triggered."}, status=status.HTTP_200_OK)

class GoogleDriveFileReactionViewSet(viewsets.ModelViewSet):
    queryset = GoogleDriveFileReaction.objects.all()
    serializer_class = GoogleDriveFileReactionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)

class OutlookEmailActionViewSet(viewsets.ModelViewSet):
    queryset = OutlookEmailAction.objects.all()
    serializer_class = OutlookEmailActionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)

class GoogleChatMessageReactionViewSet(viewsets.ModelViewSet):
    queryset = GoogleChatMessageReaction.objects.all()
    serializer_class = GoogleChatMessageReactionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)
