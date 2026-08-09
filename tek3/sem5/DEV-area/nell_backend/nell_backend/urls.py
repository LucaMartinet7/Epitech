from rest_framework import permissions
from drf_yasg.views import get_schema_view
from drf_yasg import openapi
from django.contrib import admin
from django.urls import path, include
from .views_about import about_view
schema_view = get_schema_view(
    openapi.Info(
        title="Social Auth API",
        default_version='v1',
        description="API for Social Authentication using OAuth2",
        contact=openapi.Contact(email="contact@example.com"),
    ),
    public=True,
    permission_classes=(permissions.AllowAny,),
)

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/auth/', include('authentication.urls')),
    #path('api/spotifys/', include('spotifys.urls')),
    #path('api/microsofts/', include('microsofts.urls')),
    #path('api/youtube/', include('youtube.urls')),
    path('api/twitchs/', include('twitchs.urls')),
    path('api/googlies/', include('googlies.urls')),
    path('about.json', about_view, name='about-json'),
    path('swagger/', schema_view.with_ui('swagger', cache_timeout=0), name='schema-swagger-ui'),
    path('redoc/', schema_view.with_ui('redoc', cache_timeout=0), name='schema-redoc'),

    path('accounts/', include('allauth.urls')),
]
