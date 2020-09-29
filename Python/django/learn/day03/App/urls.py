"""day03 URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path

from App import views

# 应用的名空间  用于反向引用
app_name = "App"

urlpatterns = [
    path('', views.index, name='index'),
    path('reverse/', views.reverse_url, name="reverse"),
    path('show/<slug:name>/<int:age>/', views.show, name="show"),
    path('display/<name>/',views.display,name="display"),
    #登录
    path("login/",views.login,name="login"),

    #使用ajax 注册
    path('register/',views.register,name='register'),
    path('ajax_register/',views.ajax_register,name='ajax_register'),


    path('include/',views.handle_include,name="includew"),

    #数据的增删改
    path('add/',views.api_add,name="add"),
    path('delete/',views.delete,name="delete"),
    path('update/',views.update,name="update"),

    path('find/',views.find,name='find'),
]
