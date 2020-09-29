from random import randint

from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect, HttpResponseServerError, HttpResponseForbidden, JsonResponse
from django.db.models import Q,F
# Create your views here.
from django.urls import reverse

# 重定向加反向引用
from django.views.decorators.csrf import csrf_exempt

from App.models import UserModel


def reverse_url(request):
    # return HttpResponseRedirect(reverse("App:index"))
    return HttpResponseRedirect(reverse("App:show", kwargs={'name': "tom", 'age': 99}))


# 首页
def index(request):
    return HttpResponse("这是个主页")


# 带参数的视图函数
def show(request, name, age):
    return HttpResponse(name + ":" + str(age))


# 使用表单进行提交
def login(request):
    if request.method == "POST":
        username = request.POST.get("username")
        password = request.POST.get("password")
        print(username, password)

    return render(request, "app/login.html")


def ajax_register(request):
    print("123321")
    if request.is_ajax():
        print("123")
        if request.method == "POST":
            username = request.POST.get("username")
            password = request.POST.get("password")
            print(username, password)
            return JsonResponse({'code': 1})
        else:
            return HttpResponseForbidden()
    else:
        return HttpResponseServerError()


# @csrf_exempt
def register(request):
    return render(request, "app/register.html")


def handle_include(request):
    return render(request, 'app/list.html')


#数据的增删改

def api_add(request):
    # user = UserModel(username='tom',password='123')
    # user.save()
    # UserModel.objects.create(**{'username':'321','password':'333'})
    # return HttpResponse("数据增")

    firstname = ["赵","钱","孙","李","周","吴","郑","王","西门"]
    lastname = ['三','二狗','刚','华','珍','强','麻子']

    users = []
    for i in range(100):
        name = firstname[randint(0,8)] + lastname[randint(0,6)] + str(randint(11111,22222))
        password = str(randint(111111,999999))
        users.append(UserModel(username=name,password=password))

    UserModel.objects.bulk_create(users)

    return HttpResponse('添加')

def delete(request):
    UserModel.objects.get(pk=1).delete()
    return HttpResponse("数据删")


def update(request):
    user = UserModel.objects.get(pk=2)
    user.password = '123'
    user.save()
    return HttpResponse("数据改")

def display(request,name):

    return HttpResponse(name)


def find(request):

    # sql = 'select * from usermodel whhere usernamne=%s'
    # data = UserModel.objects.raw(sql,["asfda' or '1"])
    # print(data)

    users = UserModel.objects.all()


    return render(request,'app/display.html',locals())
