#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "seqlist.h"


typedef struct tag_SeqList
{
	int length;
	int capital;
	unsigned int* node;
} TSeqList;

//������ ����ڵ�
SeqList* SeqList_Creat(int capital)
{
	//���ȶ���һ��ָ��
	TSeqList* temp = NULL;

	temp = (TSeqList*)malloc(sizeof(TSeqList));

	//��ʼ��temp
	memset(temp, 0, sizeof(TSeqList));
	printf("%d,%d,%p\n", temp->length, temp->capital, temp->node);
	//�ж��Ƿ������ڴ�ռ�
	int ret = 0;
	if (temp == NULL) {
		ret = -1;
		printf("func SeqList_Creat() err: %d \n", ret);
		return NULL;
	}

	//����capital��С����ڵ�ռ�
	temp->node = (unsigned int*)malloc(sizeof(unsigned int*) * capital);
	if (temp->node == NULL) {
		ret = -2;
		printf("func SeqList_Creat() err: molloc err %d\n", ret);
		return NULL;
	}

	temp->capital = capital;
	temp->length = 0;
}


//�ݻٱ� 
int SeqList_Distory(SeqList* list) {
	TSeqList* temp=NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("");
		return ret;
	}

	temp = (TSeqList*)list;

	if(temp->node!=NULL)
		free(temp->node);

	free(temp);

	return ret;
}

//��ձ�
int SeqList_Clear(SeqList* list) {
	TSeqList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("");
		return ret;
	}

	temp = (TSeqList*)list;

	temp->length = 0;

	return ret;
}

//��ȡ����
int SeqList_Length(SeqList* list) {
	TSeqList* temp = NULL;
	int ret = 0;
	if (list == NULL ) {
		ret = -1;
		printf("func SeqList_Length() err: %d", ret);
		return ret;
	}

	temp = (TSeqList*)list;

	return temp->length;
}


//��ȡ������
int SeqList_Capital(SeqList* list) {
	TSeqList* temp = NULL;
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func SeqList_Capital() err: %d", ret);
		return ret;
	}

	temp = (TSeqList*)list;

	return temp->capital;
}

//����ָ��λ�ò���Ԫ��
int SeqList_Insert_Pos(SeqList* list, SeqListNode* node, int pos) {
	TSeqList* temp = NULL;
	int ret = 0;

	if (list == NULL || node==NULL||pos<0) {
		ret = -1;
		printf("func SeqList_Insert_Pos() err: %d", ret);
		return ret;
	}

	temp = (TSeqList*)list;

	if (temp->capital == temp->length) {
		ret = -2;
		printf("func SeqList_Insert_Pos() err: temp->capital == temp->length %d", ret);
		return ret;
	}

	//�ݴ�����
	if (pos > temp->length) {
		pos = temp->length;
	}

	for (int i = temp->length; i > pos; i--) {
		temp->node[i] = temp->node[i - 1];
	}
	temp->node[pos] = (unsigned int)node;
	temp->length++;
	return ret;
}

//�����ĩβ����Ԫ��
int SeqList_Insert(SeqList* list, SeqListNode* node) {
	TSeqList* temp = NULL;
	int ret = 0;

	if (list == NULL || node == NULL) {
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return ret;
	}

	temp = (TSeqList*)list;

	if (temp->capital == temp->length) {
		ret = -2;
		printf("func SeqList_Insert_Pos() err: temp->capital == temp->length %d", ret);
		return ret;
	}

	temp->node[temp->length] = (unsigned int)node;

	temp->length++;
	return ret;
}

//ɾ��ָ��λ��Ԫ�ز�����
SeqListNode* SeqList_Delete(SeqList* list,int pos) {
	TSeqList* temp = NULL;
	int ret = 0;

	if (list == NULL || pos<0) {
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}

	temp = (TSeqList*)list;

	if (temp->length == 0) {
		ret = -2;
		printf("func SeqList_Insert() err: temp->length == 0 %d", ret);
		return NULL;
	}

	SeqListNode* ele = (SeqListNode*)temp->node[pos];

	for (int i = pos; i < temp->length; i++) {
		temp->node[i] = temp->node[i + 1];
	}

	temp->length--;
	return ele;
}

//��ȡĳһλ��Ԫ��
SeqListNode* SeqList_Get(SeqList* list,int pos) {
	TSeqList* temp = NULL;
	int ret = 0;

	if (list == NULL || pos<0) {
		ret = -1;
		printf("func SeqList_Insert() err: %d", ret);
		return NULL;
	}

	temp = (TSeqList*)list;

	if (temp->length < pos) {
		pos = temp->length;
	}

	return (SeqListNode*)temp->node[po+-