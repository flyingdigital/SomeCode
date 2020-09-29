#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"LinkStack.h"

typedef struct Teacher {
	LinkStackNode node;
	int age;
} Teacher;

int main(void) {
	Teacher t1, t2, t3, t4, t5;

	t1.age = 1;
	t2.age = 2;
	t3.age = 3;
	t4.age = 4;
	t5.age = 5;

	LinkStack* temp = LinkStack_Create();
	LinkStack_Insert(temp, (LinkStackNode*)&t1);
	LinkStack_Insert(temp, (LinkStackNode*)&t2);
	LinkStack_Insert(temp, (LinkStackNode*)&t3);
	LinkStack_Insert(temp, (LinkStackNode*)&t4);
	LinkStack_Insert(temp, (LinkStackNode*)&t5);

	int length = LinkStack_Length(temp);

	for (int i = 0; i < length; i++) {
		printf("length:%d,", LinkStack_Length(temp));
		Teacher* t = (Teacher*)LinkStack_Pop(temp);
		printf("age:%d\n", t->age);
	}
	LinkStack_Destory(temp);
	return 0;
}