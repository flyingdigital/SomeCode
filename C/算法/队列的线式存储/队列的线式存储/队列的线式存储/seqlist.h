#pragma once

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capital);
int SeqList_Destory(SeqList* list);
int SeqList_Clear(SeqList* list);
int SeqList_Length(SeqList* list);
int SeqList_Capital(SeqList* list);
int SeqList_Insert_Pos(SeqList* list, SeqListNode* node, int pos);
int SeqList_Insert(SeqList* list, SeqListNode* node);
SeqListNode* SeqList_Delete(SeqList* list,int pos);
SeqListNode* SeqList_Get(SeqList* list,int pos);
