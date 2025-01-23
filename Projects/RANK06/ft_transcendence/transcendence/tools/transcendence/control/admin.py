from django.contrib import admin
from .models import User, Friend
from .forms import UserAdminForm, FriendAdminForm

class UserAdmin(admin.ModelAdmin):
    form = UserAdminForm

class FriendAdmin(admin.ModelAdmin):
    form = FriendAdminForm

admin.site.register(User, UserAdmin)
admin.site.register(Friend, FriendAdmin)
