#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"

typedef struct _tag_CircleList {
	CircleListNode herder;
	CircleListNode* slider;
	int length;
} TCircleList;

CircleList* CircleList_Create() {
	TCircleList* temp = NULL;
	int ret = 0;
	temp = (TCircleList*)malloc(sizeof(TCircleList));

	if (temp == NULL) {
		ret = -1;
		printf("func CircleList_Create() err: %d", ret);
		return NULL;
	}

	memset(temp, 0, sizeof(TCircleList));

	return temp;
}


int CircleList_Destory(CircleList* list) {
	TCircleList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func CircleList_Destory() err: %d", ret);
		return ret;
	}

	temp = (TCircleList*)list;

	free(temp);
	return ret;
}

int CircleList_Length(CircleList* list) {
	TCircleList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func CircleList_Length() err: %d", ret);
		return ret;
	}

	temp = (TCircleList*)list;

	return temp->length;
}

int CircleList_Clear(CircleList* list) {
	TCircleList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func CircleList_Clear() err: %d", ret);
		return ret;
	}

	temp = (TCircleList*)list;

	temp->herder.next = NULL;
	temp->length = 0;
	temp->slider = NULL;
	
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos) {
	TCircleList* temp = NULL;
	CircleListNode* current = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func CircleList_Get() err: %d", ret);
		return NULL;
	}

	temp = (TCircleList*)list;

	current = (CircleListNode*)temp;

	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	return current->next;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) {
	TCircleList* temp = NULL;
	CircleListNode* current = NULL;

	int ret = 0;
	if (list == NULL|| node==NULL) {
		ret = -1;
		printf("func CircleList_Insert() err: %d", ret);
		return ret;
	}

	temp = (TCircleList*)list;
	current = (CircleListNode*)temp;
	
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	node->next = current->next;
	current->next = node;


	//若第一次插入节点
	if (temp->length == 0) {
		temp->slider = node;
	}


	temp->length++;

	//若头插法
	if (pos == 0) {
		CircleListNode* last = CircleList_Get(temp, CircleList_Length(temp) - 1);
		last->next = current->next;
		temp->slider = node;
	}

	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos) {
	TCircleList* temp = NULL;
	CircleListNode* current = NULL;
	CircleListNode* node = NULL;
	int ret = 0;
	if (list == NULL || pos<0) {
		ret = -1;
		printf("func CircleList_Delete() err: %d", ret);
		return NULL;
	}

	temp = (TCircleList*)list;
	current = (CircleListNode*)temp;

	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	node = current->next;

	current->next = node->next;


	if (pos == 0) {
		CircleListNode* last = CircleList_Get(temp, CircleList_Length(temp) - 1);
		last->next = current->next;
	}

	temp->length--;

	return node;
}

CircleListNode* CircleList_Current(CircleList* list) {
	TCircleList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func CircleList_Current() err: %d", ret);
		return NULL;
	}

	temp = (TCircleList*)list;

	return temp->slider;
}

CircleListNode* CircleList_Next(CircleList* list) {
	TCircleList* temp = NULL;
	CircleListNode* node = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func CircleList_Next() err: %d", ret);
		return NULL;
	}

	temp = (TCircleList*)list;

	node = temp->slider;
	temp->slider = node->next;

	return node;
}