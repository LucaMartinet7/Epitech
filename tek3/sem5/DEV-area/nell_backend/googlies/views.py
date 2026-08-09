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

class GmailReceivedActionViewSet(viewsets.ModelViewSet):
    queryset = GmailReceivedAction.objects.all()
    serializer_class = GmailReceivedActionSerializer

    def get_queryset(self):
        user = self.request.user
        if isinstance(user, AnonymousUser):
            return GmailReceivedAction.objects.none()  # Return an empty queryset
        return self.queryset.filter(user=user)

    def perform_create(self, serializer):
        serializer.save(user=self.request.user)

class SetGmailTriggerView(APIView):
    @swagger_auto_schema(
        request_body=GmailCheckRequestSerializer,
        responses={200: openapi.Response('Gmail trigger saved successfully.')}
    )
    def post(self, request):
        print("Received POST request in SetGmailTriggerView")

        # Serialize request data
        serializer = GmailCheckRequestSerializer(data=request.data)
        print("Serializer initialized with data:", request.data)
        
        if not serializer.is_valid():
            print("Serializer validation failed with errors:", serializer.errors)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        
        # Extract validated data
        channel_name = serializer.validated_data.get("channel_name")
        message_content = serializer.validated_data.get("message_content")
        song_uri = serializer.validated_data.get("song_uri")
        print("Extracted channel_name:", channel_name)
        print("Extracted message_content:", message_content)
        print("Current user:", request.user)
        print("Provider filter:", 'gmail')
        # Find social user for Gmail
        social_user = SocialUser.objects.filter(user=request.user, provider='google').first()
        print("social_user:", social_user)
        if social_user:
            print(f"Found SocialUser with access_token: {social_user.access_token}")
        else:
            print("No SocialUser found for Gmail provider.")
            return Response({"error": "No Gmail social user found."}, status=status.HTTP_404_NOT_FOUND)
        
        try:
            # Create GmailReceivedAction
            print("Creating GmailReceivedAction entry...")
            GmailReceivedAction.objects.create(
                user=request.user,
                #access_token=social_user.access_token,
            )
            print("GmailReceivedAction entry created successfully.")

            # Create TwitchChatReaction
            print("Creating TwitchChatReaction entry...")
            TwitchChatReaction.objects.create(
                user=request.user,
                channel_name=channel_name,
                message_content=message_content
            )
            print("TwitchChatReaction entry created successfully.")

            # Create SpotifySongReaction
            print("Creating SpotifySongReaction entry...")
            SpotifySongReaction.objects.create(
                user=request.user,
                song_uri=song_uri
            )
            print("SpotifySongReaction entry created successfully.")

            # Return success response
            print("All entries created successfully. Returning success response.")
            return Response({"message": "Gmail trigger saved successfully."}, status=status.HTTP_200_OK)

        except Exception as e:
            print("Exception occurred:", str(e))
            return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)
 
class CheckGmailNew(APIView):
    def post(self, request):
        user = request.user
        if check_gmail_for_emails() == 0:
            return Response({"message": "Gmail status check executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class RunSpotifyReaction(APIView):
    permission_classes = [permissions.IsAuthenticated]
    def post(self, request):
        user = request.user
        if run_spotify_reaction(user) == 0: 
            return Response({"message": "Spotify reaction executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)
    
class RunTwitchReaction(APIView):
    permission_classes = [permissions.IsAuthenticated]
    def post(self, request):
        user = request.user
        print(f"run_twitch_reaction return code: {run_twitch_reaction(user)}")
        if run_twitch_reaction(user) == 0:
            return Response({"message": "Twitch reaction executed successfully."}, status=status.HTTP_200_OK)
        else:
            return Response("error: status 500" , status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class SpotifyPlaybackCheckView(APIView):
    @swagger_auto_schema(
        request_body=SpotifyCheckRequestSerializer,
        responses={200: openapi.Response('Spotify playback check executed successfully.')}
    )
    def post(self, request):
        print("Received POST request in SpotifyPlaybackCheckView")

        serializer = SpotifyCheckRequestSerializer(data=request.data)
        print("Serializer initialized with data:", request.data)
        
        if not serializer.is_valid():
            print("Serializer validation failed with errors:", serializer.errors)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        
        print("Current user:", request.user)

        social_user = SocialUser.objects.filter(user=request.user, provider='spotify').first()
        print("social_user:", social_user)
        if social_user:
            print(f"Found SocialUser with access_token: {social_user.access_token}")
        else:
            print("No SocialUser found for Spotify provider.")
            return Response({"error": "No Spotify social user found."}, status=status.HTTP_404_NOT_FOUND)
        
        try:
            # Create action entry for Spotify
            print("Creating SpotifyReceivedAction entry...")
            SpotifyReceivedAction.objects.create(
                user=request.user,
            )
            print("SpotifyReceivedAction entry created successfully.")

            # Return success response
            print("Spotify check executed successfully. Returning success response.")
            return Response({"message": "Spotify playback check executed successfully."}, status=status.HTTP_200_OK)

        except Exception as e:
            print("Exception occurred:", str(e))
            return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)

class YouTubeSubscriptionCheckView(APIView):
    @swagger_auto_schema(
        request_body=YouTubeCheckRequestSerializer,
        responses={200: openapi.Response('YouTube subscription check executed successfully.')}
    )
    def post(self, request):
        print("Received POST request in YouTubeSubscriptionCheckView")

        # Serialize request data
        serializer = YouTubeCheckRequestSerializer(data=request.data)
        print("Serializer initialized with data:", request.data)

        if not serializer.is_valid():
            print("Serializer validation failed with errors:", serializer.errors)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

        # Extract channel_id from validated data
        channel_id = serializer.validated_data.get("channel_id")
        print("Current user:", request.user)

        # Find social user for YouTube
        social_user = SocialUser.objects.filter(user=request.user, provider='youtube').first()
        if social_user:
            print(f"Found SocialUser with access_token: {social_user.access_token}")
        else:
            print("No SocialUser found for YouTube provider.")
            return Response({"error": "No YouTube social user found."}, status=status.HTTP_404_NOT_FOUND)

        try:
            # Check if the user is subscribed to the channel
            is_subscribed = check_user_subscription(request.user, channel_id)
            if is_subscribed is True:
                return Response({"message": f"User is subscribed to channel {channel_id}."}, status=status.HTTP_200_OK)
            elif is_subscribed is False:
                return Response({"message": f"User is not subscribed to channel {channel_id}."}, status=status.HTTP_200_OK)
            else:
                return Response({"error": "Could not verify subscription status."}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)

        except Exception as e:
            print("Exception occurred:", str(e))
            return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)
