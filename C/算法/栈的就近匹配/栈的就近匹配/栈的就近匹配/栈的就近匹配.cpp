#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

int scaner(const char* code);
int isLeft(char c);
int isRight(char c);
int match(char c1, char c2);

//检验代码是非左右符号匹配
int main(void)
{
	const char* code = "#include <stdio.h> int main(void){ char name[32]; printf(\"%s\",name); reutn 0;}";
	scaner(code);

	return 0;
}

int scaner(const char* code)
{
	int i = 0;
	LinkStack* stack = LinkStack_Create();

	while (code[i] != '\0') {
		if (isLeft(code[i])) {
			LinkStack_Insert(stack, (LinkStackNode*)&code[i]);
		}

		if (isRight(code[i])) {
			int flag = match(*((char*)(LinkStack_Top(stack))),code[i]);

			if (flag) {
				LinkStack_Pop(stack);
			}
			else {
				printf("Error!!!\n");
				break;
			}
		}
		i++;
	}

	if (LinkStack_Length(stack) == 0 && code[i] == '\0')
	{
		printf("success!@!");
	}

	return 0;
}


int isLeft(char c)
{

	int ret = 1;
	switch (c) {
	case '(':
	case '{':
	case '[':
	case '\"':
	case '\'':
		ret = 1;
		break;
	default:
		ret = 0;
	}

	return ret;
}

int isRight(char c)
{
	int ret = 0;
	switch (c) {
	case ')':
	case '}':
	case ']':
	case '\"':
	case '\'':
		ret = 1;
		break;
	default:
		ret = 0;
	}

	return ret;
}

int match(char c1, char c2)
{
	int ret = 0;
	switch (c1) {
	case '(':
		ret = (c2 == ')');
		break;
	case '{':
		ret = (c2 == '}');
		break;
	case '[':
		ret = (c2 == ']');
		break;
	case '\"':
		ret = (c2 == '\"');
		break;
	case '\'':
		ret = (c2 == '\'');
		break;
	default:
		ret = 0;
	}

	return ret;
}