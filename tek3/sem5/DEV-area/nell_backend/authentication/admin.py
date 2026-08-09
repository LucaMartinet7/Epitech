from django.contrib import admin
from .models import SocialUser, PersistentToken

class PersistentTokenAdmin(admin.ModelAdmin):
    list_display = ('user', 'token')

# Register your models here.
admin.site.register(SocialUser)
admin.site.register(PersistentToken, PersistentTokenAdmin)