from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
from App.models import PublisherModel, BookModel


def index(request):

    # 增加俩出版社
    # PublisherModel.objects.bulk_create([PublisherModel(pname='清华大学出版社'),PublisherModel(pname='长江大学出版社')])

    # 增加几本书
    # BookModel.objects.bulk_create([BookModel(book_name='长江后浪推前浪'),BookModel(book_name='川普不靠谱'),BookModel(book_name='Create语言程序设计')])

    # 给书增加出版社
    # book = BookModel.objects.get(pk=1)
    # pub = PublisherModel.objects.get(pk=2)
    # book.pub = pub
    # book.save()

    # 由书找到出版社
    # book = BookModel.objects.get(pk=1)
    # print(book.pub)

    # 由出版社找到书
    pub = PublisherModel.objects.get(pk=2)
    print(pub.pid)
    print(pub.books.all())


    return HttpResponse('ok')