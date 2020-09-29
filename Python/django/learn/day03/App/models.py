from django.db import models


# Create your models here.
class UserModel(models.Model):
    uid = models.AutoField(primary_key=True)
    username = models.CharField(max_length=12)
    password = models.CharField(max_length=32)
    register_time = models.DateTimeField(auto_now_add=True)
    modified_time = models.DateTimeField(auto_now=True)

    class Meta:
        db_table = 'usermodel'
        ordering = ['username','password','register_time','uid','modified_time']