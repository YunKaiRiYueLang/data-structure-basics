#pragma once
/*基础数据结构,c c++风格可能会混搭,重在结构,这个地方不细究太多非结构的袭击 用c++应该走模板实现创建的时候,没有采用特定的方法,如尾插头插 */
typedef int DataType;
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct Node
{
	DataType data;
	struct Node *next;
}ListNode,*LinkList;
//
void InitList(LinkList &head)
{/*初始化链表*/
	if ((head = (LinkList)malloc(sizeof(ListNode))) == NULL)/*为头节点分配存储空间*/
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
ListNode *Get(LinkList head, int i)
{/*查找第i个节点.成功则返回指针*/
	ListNode *p;
	int j;
	if (ListEmpty(head))	return NULL;
	if (i < 1)	return NULL;//序号不合法.
	j = 0; p = head;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;;
	}
	if (j == i)/*返回值*/
		return p;
	else
	{
		return NULL;
	}
}
ListNode *LocateElement(LinkList head, DataType e)
{/*按内容查找,成功返回指针*/
	ListNode *p;
	p = head->next;
	while (p)
	{
		if (p->data != e)
		{
			p = p->next;
		}
		else
		{
			break;
		}
		return p;
	}
}
bool InsertList(LinkList &head, int i, DataType e)
{/*第i位置插入节点e,成功返回1*/
	ListNode *pre, *p;/*pre的i的前驱*/
	int j=0; pre = head;
	while (pre->next != NULL && j < i - 1)
	{
		pre = pre->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("插入位置错误");
		return 0;
	}
	/*新生成节点 放e*/
	if ((p = (LinkList)malloc(sizeof(ListNode))) == NULL)
		exit(-1);
	p->data = e;
	p->next = pre->next;
	pre->next = p;
	return 1;
}
int DeleteList(LinkList head, int i, DataType &e)
{/*删除第i个位置的节点 成功1*/
	ListNode *pre, *p;
	int j = 0; pre = head;
	while (pre->next != NULL && pre->next->next != NULL && j < i - 1)
	{
		pre = pre->next; j++;
	}
	if (j != i - 1)
	{
		printf("删除位置有误");
		return 0;
	}
	p = pre->next;
	e = p->data;
	pre->next = p->next;
	free(p);
	p = NULL;
	return 1;
}
int ListLength(LinkList head)
{/*求表长,当然,如果在头节点做了其他操作,这一步就变了*/
	ListNode *p;
	int count = 0;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

void DestoryList(LinkList head)
{/*销毁链表*/
	ListNode *p, *q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}
/*查找时间复杂度0(n),插入和删除O(1)*/