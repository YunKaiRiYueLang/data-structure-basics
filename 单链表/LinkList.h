#pragma once
/*�������ݽṹ,c c++�����ܻ���,���ڽṹ,����ط���ϸ��̫��ǽṹ��Ϯ�� ��c++Ӧ����ģ��ʵ��*/
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
{/*��ʼ������*/
	if ((head = (LinkList)malloc(sizeof(ListNode))) == NULL)
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
