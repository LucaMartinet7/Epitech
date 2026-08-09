import requests
from rest_framework import viewsets, permissions, status
from rest_framework.views import APIView
from rest_framework.response import Response
from .models import *
from .serializers import *
from .tasks import *
from drf_yasg.utils import swagger_auto_schema
from drf_yasg import openapi

class CheckYouTubeVideoUploadView(APIView):
    def post(self, request):
        """Check if the user uploaded a new YouTube video and create a Spotify playlist if so."""
        try:
            check_youtube_video_upload()
            return Response({"message": "YouTube video upload check executed successfully."}, status=status.HTTP_200_OK)
        except Exception as e:
            return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class CheckYouTubeWatchView(APIView):
    def post(self, request):
        """Check if the user is watching a YouTube video and play a Spotify track if so."""
        try:
            check_youtube_watch()
            return Response({"message": "YouTube watch activity check executed successfully."}, status=status.HTTP_200_OK)
        except Exception as e:
            return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class YouTubeActionViewSet(viewsets.ModelViewSet):
    queryset = YouTubeAction.objects.all()
    serializer_class = YouTubeActionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)

    def perform_create(self, serializer):
        serializer.save(user=self.request.user)

class SpotifyPlaylistReactionViewSet(viewsets.ModelViewSet):
    queryset = SpotifyPlaylistReaction.objects.all()
    serializer_class = SpotifyPlaylistReactionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)

    def perform_create(self, serializer):
        serializer.save(user=self.request.user)

class YouTubeChannelSetupView(APIView):
    @swagger_auto_schema(
        request_body=YouTubeActionSerializer,
        responses={200: openapi.Response('YouTube channel setup saved successfully.')}
    )
    def post(self, request):
        """Save YouTube channel setup details."""
        serializer = YouTubeActionSerializer(data=request.data)
        if not serializer.is_valid():
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

        channel_id = serializer.validated_data.get("channel_id")
        api_key = serializer.validated_data.get("api_key")
        action_type = serializer.validated_data.get("action_type")

        try:
            YouTubeAction.objects.create(
                user=request.user,
                channel_id=channel_id,
                api_key=api_key,
                action_type=action_type
            )
            return Response({"message": "YouTube channel setup saved successfully."}, status=status.HTTP_200_OK)

        except Exception as e:
            return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class YouTubeSubscriptionActionView(APIView):
    def post(self, request):
        serializer = YouTubeSubscriptionActionSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class OutlookEmailReactionView(APIView):
    def post(self, request):
        serializer = OutlookEmailReactionSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class TriggerYouTubeCheckView(APIView):
    def post(self, request):
        logger.info("Manually triggering YouTube subscription check")
        check_youtube_subscription()
        return Response({"message": "YouTube subscription check triggered"}, status=status.HTTP_200_OK)
