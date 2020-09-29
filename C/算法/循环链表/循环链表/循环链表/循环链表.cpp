#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"

typedef struct Techer {
	CircleListNode circlenode;
	int age;
} Teacher;

int main(void) {
	Teacher t1, t2, t3, t4, t5, t6, t7, t8;
	t1.age = 1;
	t2.age = 2;
	t3.age = 3;
	t4.age = 4;
	t5.age = 5;
	t6.age = 6;
	t7.age = 7;
	t8.age = 8;
	t1.age = 1;

	CircleList* list = CircleList_Create();

	CircleList_Insert(list, (CircleListNode*)&t1, 0);
	CircleList_Insert(list, (CircleListNode*)&t2, 0);
	CircleList_Insert(list, (CircleListNode*)&t3, 0);
	CircleList_Insert(list, (CircleListNode*)&t4, 0);
	CircleList_Insert(list, (CircleListNode*)&t5, 0);
	CircleList_Insert(list, (CircleListNode*)&t6, 0);
	CircleList_Insert(list, (CircleListNode*)&t7, 0);
	CircleList_Insert(list, (CircleListNode*)&t8, 0);

	for (int i = 0; i < CircleList_Length(list); i++) {
		Teacher* node = (Teacher*)CircleList_Get(list, i);
		printf("%d\n", node->age);
	}

	for (int i = 0; i < CircleList_Length(list) * 2; i++) {
		Teacher* node = (Teacher*)CircleList_Next(list);
		printf("%d\n", node->age);
	}
	return 0;
}