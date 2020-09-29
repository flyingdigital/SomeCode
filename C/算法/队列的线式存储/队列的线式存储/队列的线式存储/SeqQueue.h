#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void SeqQueue;
typedef void SeqQueueNode;

SeqQueue* SeqQueue_Create(int capital);
int SeqQueue_Destory(SeqQueue* list);
int SeqQueue_Clear(SeqQueue* list);
int SeqQueue_Length(SeqQueue* list);
int SeqQueue_Capital(SeqQueue* list);
int SeqQueue_Append(SeqQueue* list, SeqQueueNode* node);
SeqQueue* SeqQueue_Delete(SeqQueue* list);
SeqQueueNode* SeqQueue_Get(SeqQueue* list);














