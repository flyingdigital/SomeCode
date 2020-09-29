#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef void SeqStack;
typedef void SeqStackNode;

SeqStack* SeqStack_Create(int capital);
int SeqStack_Destory(SeqStack* seq);
int SeqStack_Clear(SeqStack* seq);
int SeqStack_Capital(SeqStack* seq);
int SeqStack_Length(SeqStack* seq);
SeqStackNode* SeqStack_Pop(SeqStack* seq);
int SeqStack_Insert(SeqStack* seq,SeqStackNode* node);
SeqStackNode* SeqStack_Get(SeqStack* seq);