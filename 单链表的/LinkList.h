#pragma once
/*�������ݽṹ,c c++�����ܻ���,���ڽṹ,����ط���ϸ��̫��ǽṹ��Ϯ�� ��c++Ӧ����ģ��ʵ�ִ�����ʱ��,û�в����ض��ķ���,��β��ͷ�� */
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
{/*��ʼ������*/
	if ((head = (LinkList)malloc(sizeof(ListNode))) == NULL)/*Ϊͷ�ڵ����洢�ռ�*/
		exit(-1);
	head->next = NULL;
}
int ListEmpty(LinkList head)
{/*�ջ�1,�����0*/
	if (head->next == NULL)
		return 1;
	else
	{
		return 0;
	}
}
ListNode *Get(LinkList head, int i)
{/*���ҵ�i���ڵ�.�ɹ��򷵻�ָ��*/
	ListNode *p;
	int j;
	if (ListEmpty(head))	return NULL;
	if (i < 1)	return NULL;//��Ų��Ϸ�.
	j = 0; p = head;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;;
	}
	if (j == i)/*����ֵ*/
		return p;
	else
	{
		return NULL;
	}
}
ListNode *LocateElement(LinkList head, DataType e)
{/*�����ݲ���,�ɹ�����ָ��*/
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
{/*��iλ�ò���ڵ�e,�ɹ�����1*/
	ListNode *pre, *p;/*pre��i��ǰ��*/
	int j=0; pre = head;
	while (pre->next != NULL && j < i - 1)
	{
		pre = pre->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("����λ�ô���");
		return 0;
	}
	/*�����ɽڵ� ��e*/
	if ((p = (LinkList)malloc(sizeof(ListNode))) == NULL)
		exit(-1);
	p->data = e;
	p->next = pre->next;
	pre->next = p;
	return 1;
}
int DeleteList(LinkList head, int i, DataType &e)
{/*ɾ����i��λ�õĽڵ� �ɹ�1*/
	ListNode *pre, *p;
	int j = 0; pre = head;
	while (pre->next != NULL && pre->next->next != NULL && j < i - 1)
	{
		pre = pre->next; j++;
	}
	if (j != i - 1)
	{
		printf("ɾ��λ������");
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
{/*���,��Ȼ,�����ͷ�ڵ�������������,��һ���ͱ���*/
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
{/*��������*/
	ListNode *p, *q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}
/*����ʱ�临�Ӷ�0(n),�����ɾ��O(1)*/