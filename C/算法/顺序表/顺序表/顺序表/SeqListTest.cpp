#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "seqlist.h"


typedef struct Teacher
{
	int age;
	char name[32];
} Teacher;

int main(void) {

	SeqList* TeacherList = SeqList_Creat(10);


	Teacher t1;
	Teacher t2;
	Teacher t3;
	Teacher t4;
	Teacher t5;

	t1.age = 11;
	t2.age = 12;
	t3.age = 13;
	t4.age = 14;
	t5.age = 15;

	SeqList_Insert_Pos(TeacherList, (SeqList*)(&t1), 0);
	SeqList_Insert_Pos(TeacherList, (SeqList*)(&t2), 0);
	SeqList_Insert_Pos(TeacherList, (SeqList*)(&t3), 0);
	SeqList_Insert_Pos(TeacherList, (SeqList*)(&t4), 0);
	SeqList_Insert_Pos(TeacherList, (SeqList*)(&t5), 0);

	for (int i = 0; i < SeqList_Length(TeacherList); i++) {
		
		Teacher* teacher = (Teacher*)SeqList_Get(TeacherList, i);
		printf("age:%d \n", teacher->age);
	}

	for (int i = 0; i < 100; i++) {
		printf("*");
	}
	printf("\n");
	printf("TeacherList->length = %d\n", SeqList_Length(TeacherList));

	for (int i = 0,j= SeqList_Length(TeacherList); i < j; i++) {
		Teacher* node = (Teacher*)SeqList_Delete(TeacherList, 0);
		printf("age:%d \n", node->age);
		printf("TeacherList->length = %d\n", SeqList_Length(TeacherList));
	}

	SeqList_Clear(TeacherList);
	SeqList_Distory(TeacherList);


	return 0;
}