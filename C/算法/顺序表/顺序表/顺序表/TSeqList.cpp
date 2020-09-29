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

//创建表 分配节点
SeqList* SeqList_Creat(int capital)
{
	//首先定义一个指针
	TSeqList* temp = NULL;

	temp = (TSeqList*)malloc(sizeof(TSeqList));

	//初始化temp
	memset(temp, 0, sizeof(TSeqList));
	printf("%d,%d,%p\n", temp->length, temp->capital, temp->node);
	//判断是否分配好内存空间
	int ret = 0;
	if (temp == NULL) {
		ret = -1;
		printf("func SeqList_Creat() err: %d \n", ret);
		return NULL;
	}

	//根据capital大小分配节点空间
	temp->node = (unsigned int*)malloc(sizeof(unsigned int*) * capital);
	if (temp->node == NULL) {
		ret = -2;
		printf("func SeqList_Creat() err: molloc err %d\n", ret);
		return NULL;
	}

	temp->capital = capital;
	temp->length = 0;
}


//摧毁表 
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

//清空表
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

//获取表长度
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


//获取表容量
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

//往表指定位置插入元素
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

	//容错修正
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

//往表的末尾插入元素
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

//删除指定位置元素并返回
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

//获取某一位置元素
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