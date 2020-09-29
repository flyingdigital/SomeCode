#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SeqStack.h"

typedef struct _tag_SeqStack {
	int length;
	int capital;
	unsigned* node;
} TSeqStack;

SeqStack* SeqStack_Create(int capital)
{
	TSeqStack* temp = NULL;

	temp = (TSeqStack*)malloc(sizeof(TSeqStack));

	int ret = 0;
	if (temp == NULL) {
		ret = -1;
		printf("func SeqStack_Create() err: %d", ret);
		return NULL;
	}

	temp->node = (unsigned*)malloc(sizeof(unsigned) * capital);

	temp->capital = capital;
	temp->length = 0;

	return temp;
}

int SeqStack_Destory(SeqStack* seq) {
	TSeqStack* temp = NULL;

	int ret = 0;
	if (seq == NULL) {
		ret = -1;
		printf("func SeqStack_Destory() err: %d", ret);
		return NULL;
	}

	temp = (TSeqStack*)seq;

	free(temp->node);
	free(temp);
	return ret;
}
int SeqStack_Clear(SeqStack* seq)
{
	TSeqStack* temp = NULL;

	int ret = 0;
	if (seq == NULL) {
		ret = -1;
		printf("func SeqStack_Clear() err: %d", ret);
		return NULL;
	}

	temp = (TSeqStack*)seq;

	temp->length = 0;

	return ret;
}

int SeqStack_Capital(SeqStack* seq)
{
	TSeqStack* temp = NULL;

	int ret = 0;
	if (seq == NULL) {
		ret = -1;
		printf("func SeqStack_Capital() err: %d", ret);
		return NULL;
	}

	temp = (TSeqStack*)seq;

	return temp->capital;
}

int SeqStack_Length(SeqStack* seq) {
	TSeqStack* temp = NULL;

	int ret = 0;
	if (seq == NULL) {
		ret = -1;
		printf("func SeqStack_Length() err: %d", ret);
		return NULL;
	}

	temp = (TSeqStack*)seq;

	return temp->length;
}

//µ¯³öÔªËØ
SeqStackNode* SeqStack_Pop(SeqStack* seq) {
	TSeqStack* temp = NULL;
	SeqStackNode* ele = NULL;

	int ret = 0;
	if (seq == NULL) {
		ret = -1;
		printf("func SeqStack_Pop() err: %d", ret);
		return NULL;
	}

	temp = (TSeqStack*)seq;

	if (temp->length >= temp->capital) {
		ret = -2;
		printf("func SeqStack_Pop() err: %d", ret);
		return NULL;
	}

	ele = (SeqStackNode*)temp->node[temp->length - 1];
	temp->node[temp->length - 1] = NULL;

	temp->length--;
	return ele;
}

int SeqStack_Insert(SeqStack* seq, SeqStackNode* node) {
	TSeqStack* temp = NULL;
	SeqStackNode* ele = NULL;

	int ret = 0;
	if (seq == NULL || node==NULL) {
		ret = -1;
		printf("func SeqStack_Insert() err: %d", ret);
		return NULL;
	}

	temp = (TSeqStack*)seq;

	if (temp->length >= temp->capital) {
		ret = -2;
		printf("func SeqStack_Insert() err: %d", ret);
		return NULL;
	}

	temp->node[temp->length] = (unsigned)node;
	temp->length++;

	return ret;
}
SeqStackNode* SeqStack_Get(SeqStack* seq) {
	TSeqStack* temp = NULL;
	SeqStackNode* ele = NULL;

	int ret = 0;
	if (seq == NULL) {
		ret = -1;
		printf("func SeqStack_Insert() err: %d", ret);
		return NULL;
	}

	temp = (TSeqStack*)seq;

	ele = (SeqStackNode*)temp->node[temp->length - 1];

	return ele;
}