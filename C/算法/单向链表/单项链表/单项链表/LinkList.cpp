#include "linklist.h"

typedef struct _tag_LinkList {
	LinkListNode* header;
	int length;
} TLinkList;


LinkList* LinkList_Create() {
	TLinkList* temp = NULL;

	temp = (TLinkList*)malloc(sizeof(TLinkList));

	int ret = 0;
	if (temp == NULL) {
		ret = -1;
		printf("func LinkList_Create() err: %d", ret);
		return NULL;
	}

	memset(temp, 0, sizeof(TLinkList));

	return temp;
}

void LinkList_Distory(LinkList* list) {
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func LinkList_Distory() err: %d", ret);
		return;
	}
	free(list);
}


void LinkList_Clear(LinkList* list) {
	TLinkList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func LinkList_Distory() err: %d", ret);
		return;
	}
	temp = (TLinkList*)list;

	temp->length = 0;
	temp->header = NULL;
}

int LinkList_Length(LinkList* list) {
	TLinkList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func LinkList_Length() err: %d", ret);
		return ret;
	}
	temp = (TLinkList*)list;


	return temp->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) {
	TLinkList* tList = NULL;
	LinkListNode* current;

	int ret = 0;
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func LinkList_Insert() err: %d", ret);
		return ret;
	}

	tList = (TLinkList*)list;
	current = tList->header;

	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	node->next = current->next;
	current->next = node;

	return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) {
	TLinkList* temp = NULL;
	LinkListNode* current = NULL;
	LinkListNode* node = NULL;

	int ret = 0;
	if (list == NULL || pos<0) {
		ret = -1;
		printf("func LinkList_Delete() err: %d", ret);
		return NULL;
	}
	temp = (TLinkList*)list;
	current = temp->header;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	node = current->next;

	current->next = node->next;

	return node;
}


LinkListNode* LinkList_Get(LinkList* list, int pos) {
	TLinkList* temp = NULL;
	LinkListNode* current = NULL;

	int ret = 0;
	if (list == NULL || pos < 0) {
		ret = -1;
		printf("func LinkList_Delete() err: %d", ret);
		return NULL;
	}
	temp = (TLinkList*)list;
	current = temp->header;

	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	return current->next;
}