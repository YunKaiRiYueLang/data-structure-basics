#pragma once
/*基础数据结构,c c++风格可能会混搭,重在结构,这个地方不细究太多非结构的袭击 用c++应该走模板实现*/
typedef int DataType;
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	DataType data;
	struct Node *next;
}ListNode,*LinkList;
//
void InitList(LinkList &head)
{/*初始化链表*/
	if ((head = (LinkList)malloc(sizeof(ListNode))) == NULL)
		exit(-1);
	head->next = NULL;
}
int ListEmpty(LinkList head)
{/*空回1,否则回0*/
	if (head->next == NULL)
		return 1;
	else
	{
		return 0;
	}
}
