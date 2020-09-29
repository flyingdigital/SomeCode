#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SeqStack.h"

typedef struct Teacher{
	int age;
	char name;
} Teacher;

int main(void) {

	Teacher t1, t2, t3, t4, t5, t6, t7, t8;

	t1.age = 11;
	t1.name = 'a';

	t2.age = 12;
	t2.name = 'b';

	t3.age = 13;
	t3.name = 'c';

	t4.age = 14;
	t4.name = 'd';

	t5.age = 15;
	t5.name = 'e';

	t6.age = 16;
	t6.name = 'f';

	t7.age = 17;
	t7.name = 'g';

	t8.age = 18;
	t8.name = 'h';

	SeqStack* stack = SeqStack_Create(10);

	SeqStack_Insert(stack, (SeqStackNode*)&t1);
	SeqStack_Insert(stack, (SeqStackNode*)&t2);
	SeqStack_Insert(stack, (SeqStackNode*)&t3);
	SeqStack_Insert(stack, (SeqStackNode*)&t4);
	SeqStack_Insert(stack, (SeqStackNode*)&t5);
	SeqStack_Insert(stack, (SeqStackNode*)&t6);
	SeqStack_Insert(stack, (SeqStackNode*)&t7);
	SeqStack_Insert(stack, (SeqStackNode*)&t8);

	for (int i = 0; i < 8; i++) {
		Teacher* temp = (Teacher*)SeqStack_Pop(stack);
		printf("age:%d,name:%c length=%d\n", temp->age, temp->name,SeqStack_Length(stack));
		
	}
	return 0;
}