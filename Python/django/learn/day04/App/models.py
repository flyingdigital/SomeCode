from django.db import models

# Create your models here.
class BookModel(models.Model):

    bid = models.AutoField(primary_key=True)
    book_name = models.CharField(max_length=32)

    #外键 出版社
    pub = models.ForeignKey('PublisherModel',on_delete=models.CASCADE, db_column='pid',related_name='books',blank=True,null=True)

    class Meta:
        db_table  = 'book'

class PublisherModel(models.Model):

    pid = models.AutoField(primary_key=True)

    pname = models.CharField(max_length=32)

    class Meta:
        db_table  = 'publisher'
