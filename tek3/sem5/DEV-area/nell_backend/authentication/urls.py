from django.urls import path
from .views import RegisterView, LoginView, OAuthInitView, OAuthCallbackView, UserInfoView, UserLoginView
from rest_framework_simplejwt.views import TokenObtainPairView, TokenRefreshView

urlpatterns = [
    # Traditional login and registration
    path('register/', RegisterView.as_view(), name='register'),
    path('login/', LoginView.as_view(), name='login'),

    # JWT token obtain and refresh endpoints
    path('token/', TokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('token/refresh/', TokenRefreshView.as_view(), name='token_refresh'),

    # OAuth login and callback URLs
    path('<str:provider>/login/', OAuthInitView.as_view(), name='oauth_login'),
    path('<str:provider>/callback/', OAuthCallbackView.as_view(), name='oauth_callback'),
    
    path('auth/login/', UserLoginView.as_view(), name='user_login'),
    path('auth/user-info/<str:username>/', UserInfoView.as_view(), name='user_info'),
]
