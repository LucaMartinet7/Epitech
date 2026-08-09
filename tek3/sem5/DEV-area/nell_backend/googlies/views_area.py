from rest_framework import viewsets, permissions, status
from rest_framework.views import APIView
from rest_framework.response import Response
from .models import *
from .serializers import *
from .tasks import *
from drf_yasg.utils import swagger_auto_schema
from drf_yasg import openapi
from django.contrib.auth.models import AnonymousUser
from authentication.models import SocialUser
from django.conf import settings
from .task_secondbase import *
from .task_spotify import *
from .task_gmail import *

class AREACheckGmailSpotify(APIView):
    def post(self, request):
        if check_gmail_for_spotify() == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)
        
class AREACheckGmailTwitch(APIView):
    def post(self, request):
        if check_gmail_for_twitch() == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)
       
class AREACheckGmailBluesky(APIView):
    def post(self, request):
        if check_gmail_for_bluesky() == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class AREACheckBlueskySpotify(APIView):
    def post(self, request):
        if check_bluesky_for_spotify() == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)
        
class AREACheckBlueskyTwitch(APIView):
    def post(self, request):
        if check_bluesky_for_twitch() == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class AREACheckSpotifyPlayBluesky(APIView):
    def post(self, request):
        if check_spotify_playback_for_bluesky() == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class AREACheckSpotifyPlayTwitch(APIView):
    def post(self, request):
        if check_spotify_playback_for_twitch() == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class AREACheckYoutubeTwitch(APIView):
    def post(self, request):
        user = request.user
        if check_user_subscription_for_twitch(user, settings.YOUTUBE_CHANNEL_ID) == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class AREACheckYoutubeSpotify(APIView):
    def post(self, request):
        user = request.user
        if check_user_subscription_for_spotify(user, settings.YOUTUBE_CHANNEL_ID) == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class AREACheckYoutubeBluesky(APIView):
    def post(self, request):
        user = request.user
        if check_user_subscription_for_bluesky(user, settings.YOUTUBE_CHANNEL_ID) == 0: 
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)
