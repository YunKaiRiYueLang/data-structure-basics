/*������A B Ԫ�طǵݼ�����  �㷨��x x�ȱ�,�õ��ݼ������C(ֵ��ֻͬ����һ��),Ҫ������ԭ����ڵ�ռ�*/

#include<iostream>
#include"LinkList.h"
using namespace std;

void MergeList(LinkList A, LinkList B, LinkList &C);

int main()
{
	int *p = (int *)malloc(sizeof(int) * 4);
	//LinkList p;
	//InitList(p);
	system("pause");
}

void MergeList(LinkList A, LinkList B, LinkList &C)
{
	ListNode *pa, *pb, *qa, *qb;
	pa = A->next;
	pb = B->next;//
	C = A;
	C->next = NULL;
	while (pa&&pb)
	{
		if (pa->data < pb->data)
		{
			qa = pa;
			pa = pa->next;
			if (C->next->data == NULL)
			{/*Ϊ��ֱ�Ӳ���*/
				qa->next = C->next;
				C->next = qa;
			}
			else if (C->next->data < qa->data)
			{
				qa->next = C->next;
				C->next = qa;
			}
			else
			{
				free(qa);
			}
		}
		else
		{/*pb�Ƚ�С*/
			qb = pb;
			pb = pb->next;
			if (C->next == NULL)
			{
				qb->next = C->next;
				C->next = qb;
			}
		}
	}

}