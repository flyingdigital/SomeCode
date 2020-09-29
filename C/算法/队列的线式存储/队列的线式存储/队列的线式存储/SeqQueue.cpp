#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "seqlist.h"
#include "SeqQueue.h"


SeqQueue* SeqQueue_Create(int capital) {
	return SeqList_Create(10);
}
int SeqQueue_Destory(SeqQueue* list) {
	return SeqList_Destory(list);
}
int SeqQueue_Clear(SeqQueue* list) {
	return SeqList_Clear(list);
}

int SeqQueue_Length(SeqQueue* list) {
	return SeqList_Length(list);
}
int SeqQueue_Capital(SeqQueue* list) {
	return SeqList_Capital(list);
}
int SeqQueue_Append(SeqQueue* list, SeqQueueNode* node) {
	return SeqList_Insert_Pos(list, node,SeqList_Length(list));
}
SeqQueue* SeqQueue_Delete(SeqQueue* list) {
	return SeqList_Delete(list, 0);
}
SeqQueueNode* SeqQueue_Get(SeqQueue* list) {
	return SeqList_Get(list, 0);
}