from django.urls import path
from . import views
from front import views as front_views

urlpatterns = [
    path(route='sign-up/', view=views.sign_up, name='sign-up'),
    path(route='sign-out/', view=views.sign_out, name='sign-out'),
    path(route='sign-in/', view=views.sign_in, name='sign-in'),
    path(route='sign-with-ft/', view=views.sign_with_ft, name='sign-with-ft'),
    path(route='callback/', view=views.callback, name='callback'),
    path(route='configure-password/', view=views.configure_password, name='configure-password'),
    path(route='enable-two-factor-auth/', view=views.enable_two_factor_auth, name='enable-two-factor-auth'),
    path(route='disable-two-factor-auth/', view=views.disable_two_factor_auth, name='disable-two-factor-auth'),
    path(route='verify-two-factor-auth-code/', view=views.verify_two_factor_auth_code, name='verify-two-factor-auth-code'),
    path(route='two-factor-auth-verify-login/', view=views.two_factor_auth_verify_login, name='two-factor-auth-verify-login'),
    path(route='update/', view=views.update, name='update'),
    path(route='add-friend/', view=views.add_friend, name='add-friend'),
    path(route='remove-friend/', view=views.remove_friend, name='remove-friend'),
    path(route='delete-account/', view=views.delete_account, name='delete-account'),
    path(route='change-language/', view=views.change_language, name='change-language'),
    path(route='navbar/', view=front_views.navbar, name='navbar'),
    path(route='content/<str:page>/', view=views.content, name='content'),
    path(route='modal/', view=front_views.modal, name='modal'),
    path(route='footer/', view=front_views.footer, name='footer'),
]

