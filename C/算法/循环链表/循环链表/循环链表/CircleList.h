#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void CircleList;
typedef struct _tag_CircleListNode {
	struct _tag_CircleListNode* next;
} CircleListNode;


CircleList* CircleList_Create();
int CircleList_Destory(CircleList* list);
int CircleList_Length(CircleList* list);
int CircleList_Clear(CircleList* list);
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);
CircleListNode* CircleList_Delete(CircleList* list, int pos);
CircleListNode* CircleList_Get(CircleList* list, int pos);
CircleListNode* CircleList_Current(CircleList* list);
CircleListNode* CircleList_Next(CircleList* list);