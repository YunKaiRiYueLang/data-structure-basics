#pragma once
typedef int DataType;
#include<malloc.h>
#include<iostream>
// 顺序存储用数组.空间上的浪费不言而喻.不提了
typedef struct Node
{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
	
}*BitTree,BitNode;

void InitBitTree(BitTree &T)
{
	T = nullptr;
}

void DestroyBitTree(BitTree &T)
{
	if (T)
	{//若非空
		if (T->lchild)	DestroyBitTree(T->lchild);
		if (T->rchild)	DestroyBitTree(T->rchild);
		free(T);
		T = NULL;
	}
}

void CreatBitTree(BitTree &T)
{
	DataType ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = (BitTree)malloc(sizeof(BitNode)); //生成根节点.
		if (!T)
			exit(-1);
		T->data = ch;
		CreatBitTree(T->lchild);//创建左右子树
		CreatBitTree(T->rchild);
	}
}

int InsertChild(BitTree p, int LR, BitTree c)
{
	if(p)
	{//操作非空树
		if (LR == 0)
		{

		}
	}
}