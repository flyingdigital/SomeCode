#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct BiTNode {
	char data;
	struct BiTNode* lnode, * rnode;
} BiTNode;

int sum;
//先序遍历
void preOrder(BiTNode* root) {
	if (root == NULL) {
		return;
	}

	printf("%c ", root->data);

	preOrder(root->lnode);
	preOrder(root->rnode);
}

//中序遍历
void inOrder(BiTNode* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->lnode);
	printf("%c ", root->data);

	
	inOrder(root->rnode);
}
//后序遍历
void posOrder(BiTNode* root) {
	if (root == NULL) {
		return;
	}
	posOrder(root->lnode);
	


	posOrder(root->rnode);
	printf("%c ", root->data);
}


//求树的叶子节点个数 
void leafCount(BiTNode* root ) {
	if (root != NULL) {
		if (!root->lnode && !root->rnode) {
			sum++;
		}

		if (root->lnode) {
			leafCount(root->lnode);
		}
		if (root->rnode) {
			leafCount(root->rnode);
		}
	}
}


int main(void) {
	BiTNode t1, t2, t3, t4, t5, t6, t7, t8;

	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));
	memset(&t6, 0, sizeof(BiTNode));
	memset(&t7, 0, sizeof(BiTNode));
	memset(&t8, 0, sizeof(BiTNode));

	t1.data = 'A';
	t2.data = 'B';
	t3.data = 'C';
	t4.data = 'D';
	t5.data = 'E';
	t6.data = 'F';
	t7.data = 'G';
	t8.data = 'H';

	t1.lnode = &t2;
	t1.rnode = &t6;
	t2.rnode = &t3;
	t3.lnode = &t4;
	t3.rnode = &t5;
	t6.rnode = &t7;
	t7.lnode = &t8;


	//遍历二叉树
	preOrder(&t1);
	printf("\n");
	inOrder(&t1);
	printf("\n");
	posOrder(&t1);
	printf("\n");

	//求树的叶子节点
	sum = 0;
	leafCount(&t1);
	printf("%d\n", sum);

	return 0;
}