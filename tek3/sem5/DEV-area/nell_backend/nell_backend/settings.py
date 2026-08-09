from pathlib import Path
from decouple import config
from datetime import timedelta
import os
from dotenv import load_dotenv
import pymysql
pymysql.install_as_MySQLdb()

load_dotenv()

BASE_DIR = Path(__file__).resolve().parent.parent

SECRET_KEY = os.getenv('SECRET_KEY')
DEBUG = os.getenv('DEBUG', 'False') == 'True'

ALLOWED_HOSTS = [
    '127.0.0.1',
    'localhost',
    'https://5a70-45-154-248-67.ngrok-free.app',
    '5a70-45-154-248-67.ngrok-free.app',
]

SITE_ID = 3

# Social Auth Config
SOCIAL_AUTH_GOOGLE_OAUTH2_KEY = config('SOCIAL_AUTH_GOOGLE_OAUTH2_KEY')
SOCIAL_AUTH_GOOGLE_OAUTH2_SECRET = config('SOCIAL_AUTH_GOOGLE_OAUTH2_SECRET')

SOCIAL_AUTH_GITHUB_KEY = config('SOCIAL_AUTH_GITHUB_KEY')
SOCIAL_AUTH_GITHUB_SECRET = config('SOCIAL_AUTH_GITHUB_SECRET')

SOCIAL_AUTH_DISCORD_KEY = config('SOCIAL_AUTH_DISCORD_KEY')
SOCIAL_AUTH_DISCORD_SECRET = config('SOCIAL_AUTH_DISCORD_SECRET')

SPOTIFY_CLIENT_ID = config('SPOTIFY_CLIENT_ID')
SPOTIFY_CLIENT_SECRET = config('SPOTIFY_CLIENT_SECRET')
SPOTIFY_REDIRECT_URI = config('SPOTIFY_REDIRECT_URI')

OPENWEATHER_API_KEY = config('OPENWEATHER_API_KEY')

MICROSOFT_CLIENT_ID = config('MICROSOFT_CLIENT_ID')
MICROSOFT_CLIENT_SECRET = config('MICROSOFT_CLIENT_SECRET')
MICROSOFT_TENANT_ID = config('MICROSOFT_TENANT_ID')
MICROSOFT_REDIRECT_URI = config('MICROSOFT_REDIRECT_URI')
MICROSOFT_AUTHORITY = config('MICROSOFT_AUTHORITY')
MICROSOFT_SCOPE = config('MICROSOFT_SCOPE', cast=lambda v: [s.strip() for s in v.split(',')])

YOUTUBE_CLIENT_ID = config('YOUTUBE_CLIENT_ID')
YOUTUBE_CLIENT_SECRET = config('YOUTUBE_CLIENT_SECRET')
YOUTUBE_REDIRECT_URI = config('YOUTUBE_REDIRECT_URI')
YOUTUBE_SCOPES = config('YOUTUBE_SCOPES').split(',')

TWITCH_CLIENT_ID=config('TWITCH_CLIENT_ID')
TWITCH_CLIENT_SECRET=config('TWITCH_CLIENT_SECRET')
TWITCH_REDIRECT_URI=config('TWITCH_REDIRECT_URI')
TWITCH_SCOPES = config('TWITCH_SCOPES')

TWITCH_WEBHOOK_CALLBACK_URL = config('TWITCH_WEBHOOK_CALLBACK_URL')
TWITCH_WEBHOOK_SECRET = config('TWITCH_WEBHOOK_SECRET')

DISCORD_WEBHOOK_URL = config('DISCORD_WEBHOOK_URL')

REDDIT_CLIENT_ID = config('REDDIT_CLIENT_ID')
REDDIT_CLIENT_SECRET = config('REDDIT_CLIENT_SECRET')\

YOUTUBE_CHANNEL_ID = config('YOUTUBE_CHANNEL_ID')

# OAuth URL Configuration
AUTHORIZATION_URL_GITHUB = config('AUTHORIZATION_URL_GITHUB')
AUTHORIZATION_URL_GOOGLE = config('AUTHORIZATION_URL_GOOGLE')
AUTHORIZATION_URL_DISCORD = config('AUTHORIZATION_URL_DISCORD')
AUTHORIZATION_URL_SPOTIFY = config('AUTHORIZATION_URL_SPOTIFY')
AUTHORIZATION_URL_TWITCH = config('AUTHORIZATION_URL_TWITCH')
AUTHORIZATION_URL_REDDIT = config('AUTHORIZATION_URL_REDDIT')

TOKEN_URL_GITHUB = config('TOKEN_URL_GITHUB')
TOKEN_URL_GOOGLE = config('TOKEN_URL_GOOGLE')
TOKEN_URL_DISCORD = config('TOKEN_URL_DISCORD')
TOKEN_URL_SPOTIFY = config('TOKEN_URL_SPOTIFY')
TOKEN_URL_TWITCH = config('TOKEN_URL_TWITCH')
TOKEN_URL_REDDIT = config('TOKEN_URL_REDDIT')

OAUTH_SCOPES = {
    'github': 'user:email',
    'google': 'openid email profile',
    'discord': 'identify email',
    'spotify': [
        'user-read-email',
        'user-modify-playback-state',
        'user-read-playback-state',
        'user-read-currently-playing',
    ],
    'twitch': 'user:read:email',
    'reddit': 'identity',
}

REST_USE_JWT = True

INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'django.contrib.sites',
    'rest_framework',
    'rest_framework_simplejwt.token_blacklist',
    'authentication',
    #'spotifys',
    #'microsofts',
    'twitchs',
    #'youtube',
    'googlies',
    'drf_yasg',
    'allauth',
    'allauth.account',
    'allauth.socialaccount',
    'allauth.socialaccount.providers.google',
    'allauth.socialaccount.providers.github',
    'allauth.socialaccount.providers.discord',
    'allauth.socialaccount.providers.microsoft',
    'allauth.socialaccount.providers.twitch',
    'allauth.socialaccount.providers.spotify',
    'dj_rest_auth',
    'dj_rest_auth.registration',
    'rest_framework.authtoken',
    'corsheaders',
]

MIDDLEWARE = [
    'django.middleware.security.SecurityMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
    'allauth.account.middleware.AccountMiddleware',
    'corsheaders.middleware.CorsMiddleware',
    'django.middleware.common.CommonMiddleware',
]

REST_FRAMEWORK = {
    'DEFAULT_AUTHENTICATION_CLASSES': [
        'rest_framework.authentication.SessionAuthentication',
        'rest_framework.authentication.BasicAuthentication',
    ],
}

ROOT_URLCONF = 'nell_backend.urls'

TEMPLATES = [
    {
        'BACKEND': 'django.template.backends.django.DjangoTemplates',
        'DIRS': [],
        'APP_DIRS': True,
        'OPTIONS': {
            'context_processors': [
                'django.template.context_processors.debug',
                'django.template.context_processors.request',
                'django.contrib.auth.context_processors.auth',
                'django.contrib.messages.context_processors.messages',
            ],
        },
    },
]

AUTHENTICATION_BACKENDS = (
    'django.contrib.auth.backends.ModelBackend',
    'allauth.account.auth_backends.AuthenticationBackend',
)

LOGIN_REDIRECT_URL = 'http://localhost:3000/dashboard'
TWITCH_REDIRECT_URI = "https://5a70-45-154-248-67.ngrok-free.app/api/auth/twitch/callback/"
WSGI_APPLICATION = 'nell_backend.wsgi.application'

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': os.getenv('DB_NAME'),
        'USER': os.getenv('DB_USER'),
        'PASSWORD': os.getenv('DB_PASSWORD'),
        'HOST': os.getenv('DB_HOST'),
        'PORT': os.getenv('DB_PORT'),
        'OPTIONS': {
            'connect_timeout': 30,
    }
    }
}

AUTH_PASSWORD_VALIDATORS = [
    {
        'NAME': 'django.contrib.auth.password_validation.UserAttributeSimilarityValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.MinimumLengthValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.CommonPasswordValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.NumericPasswordValidator',
    },
]

CORS_ALLOW_ALL_ORIGINS = True

CORS_ALLOWED_ORIGINS = [
    "http://localhost:8000",
    "http://127.0.0.1:8000",
    "http://localhost:3000",
    "http://127.0.0.1:3000",
    "http://localhost:45195",
    "https://5a70-45-154-248-67.ngrok-free.app",
    "http://5a70-45-154-248-67.ngrok-free.app",
]

CSRF_TRUSTED_ORIGINS = [
    
    'https://5a70-45-154-248-67.ngrok-free.app',
    'http://5a70-45-154-248-67.ngrok-free.app',  # Include both HTTP and HTTPS
]

CORS_ALLOW_HEADERS = [
    'content-type',
    'authorization',
    'x-csrftoken',
    'x-requested-with',
]

SESSION_COOKIE_SAMESITE = 'None'
SESSION_COOKIE_SECURE = True

LANGUAGE_CODE = 'en-us'

TIME_ZONE = 'UTC'

USE_I18N = True

USE_TZ = True

STATIC_URL = 'static/'
DEFAULT_AUTO_FIELD = 'django.db.models.BigAutoField'
