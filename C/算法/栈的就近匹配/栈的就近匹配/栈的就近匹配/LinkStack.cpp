#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"LinkStack.h"


typedef struct _tag_LinkStack{
	LinkStackNode header;
	int length;
}TLinkStack;

LinkStack* LinkStack_Create() {
	TLinkStack* temp = NULL;
	temp = (TLinkStack*)malloc(sizeof(TLinkStack));

	if (temp == NULL) {
		printf("func LinkStack_Create() err: -1");
		return NULL;
	}

	temp->length = 0;
	temp->header.next = NULL;

	return temp;
}
int LinkStack_Destory(LinkStack* stack) {
	TLinkStack* temp = NULL;

	if (stack == NULL) {
		printf("func LinkStack_Length() err: -1");
		return NULL;
	}
	temp = (TLinkStack*)stack;
	free(temp);
	return 0;
}
int LinkStack_Clear(LinkStack* stack) {
	TLinkStack* temp = NULL;

	if (stack == NULL) {
		printf("func LinkStack_Length() err: -1");
		return NULL;
	}
	temp = (TLinkStack*)stack;

	while (temp->length > 0) {
		LinkStack_Pop(temp);
	}
	temp->header.next = NULL;
}
int LinkStack_Length(LinkStack* stack) {
	TLinkStack* temp = NULL;

	if (stack == NULL) {
		printf("func LinkStack_Length() err: -1");
		return NULL;
	}
	temp = (TLinkStack*)stack;

	return temp->length;
}
void* LinkStack_Top(LinkStack* stack) {
	TLinkStack* temp = NULL;

	if (stack == NULL) {
		printf("func LinkStack_Top() err: -1");
		return NULL;
	}
	temp = (TLinkStack*)stack;

	return temp->header.next->item;
}
void* LinkStack_Pop(LinkStack* stack) {
	TLinkStack* temp = NULL;
	LinkStackNode* node = NULL;
	LinkStackNode* current = NULL;
	void* item = NULL;

	if (stack == NULL) {
		printf("func LinkStack_Pop() err: -1");
		return NULL;
	}
	temp = (TLinkStack*)stack;
	current = &(temp->header);

	node = current->next;
	item = node->item;

	current->next = node->next;

	free(node);
	temp->length--;
	return item;
}
int LinkStack_Insert(LinkStack* stack, LinkStackNode* node) {
	TLinkStack* temp = NULL;
	LinkStackNode* tnode = NULL;
	LinkStackNode* current = NULL;
	if (stack == NULL || node == NULL) {
		printf("func int LinkStack_Insert() err: -1");
		return NULL;
	}
	temp = (TLinkStack*)stack;

	tnode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	memset(tnode, 0, sizeof(LinkStackNode));

	current = &(temp->header);

	tnode->item = node;
	tnode->next = current->next;

	current->next = tnode;
	temp->length++;
	return 0;
}