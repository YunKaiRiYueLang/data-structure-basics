#pragma once
typedef int DataType;
#include<malloc.h>
#include<iostream>
// ˳��洢������.�ռ��ϵ��˷Ѳ��Զ���.������
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
	{//���ǿ�
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
		T = (BitTree)malloc(sizeof(BitNode)); //���ɸ��ڵ�.
		if (!T)
			exit(-1);
		T->data = ch;
		CreatBitTree(T->lchild);//������������
		CreatBitTree(T->rchild);
	}
}

int InsertChild(BitTree p, int LR, BitTree c)
{
	if(p)
	{//�����ǿ���
		if (LR == 0)
		{

		}
	}
}