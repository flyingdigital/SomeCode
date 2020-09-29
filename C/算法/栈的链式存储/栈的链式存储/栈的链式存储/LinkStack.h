#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>


typedef void LinkStack;
typedef struct LinkStackNode {
	LinkStackNode* next;
	void* item;
}LinkStackNode;


LinkStack* LinkStack_Create();
int LinkStack_Destory(LinkStack* stack);
int LinkStack_Clear(LinkStack* stack);
int LinkStack_Length(LinkStack* stack);
void* LinkStack_Top(LinkStack* stack);
void* LinkStack_Pop(LinkStack* stack);
int LinkStack_Insert(LinkStack* stack, LinkStackNode* node);