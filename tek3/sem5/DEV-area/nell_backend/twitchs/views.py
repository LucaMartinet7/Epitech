import requests
from rest_framework import viewsets, permissions, status
from rest_framework.views import APIView
from rest_framework.response import Response
from .models import *
from .serializers import *
from .tasks import *
from rest_framework import serializers
from drf_yasg.utils import swagger_auto_schema
from drf_yasg import openapi
from atproto import Client

class ChannelStatusCheckView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def post(self, request):
        user = request.user
        is_live = check_twitch_live(user)

        if is_live is None:
            return Response({"error": "No Twitch SocialUser found for the user."}, status=status.HTTP_404_NOT_FOUND)
        
        # Update or create a TwitchLiveAction with the live status
        twitch_live_action, created = TwitchLiveAction.objects.get_or_create(user=user)
        twitch_live_action.channel_status = is_live
        twitch_live_action.save()

        message = "Twitch is live; status updated successfully." if is_live else "Twitch is not live; status updated successfully."
        return Response({"message": message}, status=status.HTTP_200_OK)

class PostToBlueskyView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def post(self, request):
        user = request.user
        twitch_live_action = TwitchLiveAction.objects.filter(user=user).first()

        # Check if the user’s Twitch channel is live
        if twitch_live_action and twitch_live_action.channel_status:
            # Fetch the Bluesky post reaction and post to Bluesky
            reaction = BlueskyPostReaction.objects.filter(user=user).first()
            if reaction:
                post_to_bluesky(reaction)
                return Response({"message": "Posted to Bluesky successfully."}, status=status.HTTP_200_OK)
            else:
                return Response({"error": "Bluesky post reaction not found for the user."}, status=status.HTTP_404_NOT_FOUND)
        else:
            return Response({"message": "Channel is not live."}, status=status.HTTP_400_BAD_REQUEST)
        
class CheckAndPostToBlueskyView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def post(self, request):
        user = request.user
        
        # Step 1: Check if the Twitch channel is live
        is_live = check_twitch_live(user)
        if is_live is None:
            return Response({"error": "No Twitch SocialUser found for the user."}, status=status.HTTP_404_NOT_FOUND)
        
        # Step 2: Update or create a TwitchLiveAction with the live status
        twitch_live_action, created = TwitchLiveAction.objects.get_or_create(user=user)
        twitch_live_action.channel_status = is_live
        twitch_live_action.save()

        # Prepare a message indicating the channel status
        status_message = "Twitch is live; status updated successfully." if is_live else "Twitch is not live; status updated successfully."

        # Step 3: If the channel is live, post to Bluesky
        if is_live:
            # Attempt to retrieve the Bluesky post reaction
            reaction = BlueskyPostReaction.objects.filter(user=user).first()
            if reaction:
                # Post the message to Bluesky
                post_to_bluesky(reaction)
                return Response({"message": f"{status_message} Posted to Bluesky successfully."}, status=status.HTTP_200_OK)
            else:
                return Response({"error": f"{status_message} But Bluesky post reaction not found for the user."}, status=status.HTTP_404_NOT_FOUND)
        
        # Return the status message if the channel is not live
        return Response({"message": status_message}, status=status.HTTP_200_OK)

class CheckAndPlaySpotifyView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def post(self, request):
        user = request.user
        
        # Step 1: Check if the Twitch channel is live
        is_live = check_twitch_live(user)
        if is_live is None:
            return Response({"error": "No Twitch SocialUser found for the user."}, status=status.HTTP_404_NOT_FOUND)
        
        # Step 2: Update or create a TwitchLiveAction with the live status
        twitch_live_action, created = TwitchLiveAction.objects.get_or_create(user=user)
        twitch_live_action.channel_status = is_live
        twitch_live_action.save()

        # Prepare a message indicating the channel status
        status_message = "Twitch is live; status updated successfully." if is_live else "Twitch is not live; status updated successfully."

        # Step 3: If the channel is live, play a song on Spotify
        if is_live:
            result = run_spotify_reaction(user)
            if result == 0:
                return Response({"message": f"{status_message} Playing song on Spotify successfully."}, status=status.HTTP_200_OK)
            else:
                return Response({"error": f"{status_message} But failed to play song on Spotify."}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)
        
        # Return the status message if the channel is not live
        return Response({"message": status_message}, status=status.HTTP_200_OK)

class TwitchLiveActionViewSet(viewsets.ModelViewSet):
    queryset = TwitchLiveAction.objects.all()
    serializer_class = TwitchLiveActionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)

    def perform_create(self, serializer):
        serializer.save(user=self.request.user)

class BlueskyPostReactionViewSet(viewsets.ModelViewSet):
    queryset = BlueskyPostReaction.objects.all()
    serializer_class = BlueskyPostReactionSerializer
    permission_classes = [permissions.IsAuthenticated]

    def get_queryset(self):
        return self.queryset.filter(user=self.request.user)

    def perform_create(self, serializer):
        serializer.save(user=self.request.user)

class GetBlueskyUserIDView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    @swagger_auto_schema(
        request_body=BlueskyUserIDRequestSerializer,
        responses={200: openapi.Response('Bluesky User ID retrieved and saved successfully.')}
    )
    def post(self, request):
        serializer = BlueskyUserIDRequestSerializer(data=request.data)
        if not serializer.is_valid():
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

        bluesky_handle = serializer.validated_data.get("bluesky_handle")
        bluesky_password = serializer.validated_data.get("bluesky_password")
        message = serializer.validated_data.get("message")
        try:
            # Initialize the Bluesky client and log in
            client = Client()
            login_response = client.login(bluesky_handle, bluesky_password)

            # Check if the login was successful and attempt to retrieve the user ID (DID)
            access_token = getattr(client, 'access_token', None)

            if not access_token and hasattr(client, 'session'):
                access_token = client.session.get('accessJwt', None)

            # Retrieve the Bluesky user ID (DID)
            user_profile = client.get_profile(actor=bluesky_handle)
            bluesky_user_id = user_profile.did

            if bluesky_user_id:
                # Save the details to BlueskyPostReaction table
                BlueskyPostReaction.objects.create(
                    user=request.user,
                    bluesky_handle=bluesky_handle,
                    bluesky_password=bluesky_password,
                    bluesky_user_id=bluesky_user_id,
                    message=message  # Save the message content as well
                )
                return Response({"bluesky_user_id": bluesky_user_id}, status=status.HTTP_200_OK)
            else:
                return Response({"error": "User ID not found."}, status=status.HTTP_404_NOT_FOUND)

        except Exception as e:
            return Response({"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)
