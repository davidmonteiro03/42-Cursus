from django import forms
from .models import User, Friend

class UserAdminForm(forms.ModelForm):
    password = forms.CharField(widget=forms.PasswordInput)

    class Meta:
        model = User
        fields = '__all__'

class FriendAdminForm(forms.ModelForm):
    class Meta:
        model = Friend
        fields = '__all__'
