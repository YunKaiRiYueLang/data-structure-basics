/*������A B Ԫ�طǵݼ�����  �㷨��x x�ȱ�,�õ��ݼ������C(ֵ��ֻͬ����һ��),Ҫ������ԭ����ڵ�ռ�*/

#include<iostream>
#include"LinkList.h"
using namespace std;

void MergeList(LinkList A, LinkList B, LinkList &C);
//bool InsertNum(LinkList &A, DataType *a)
//{
//	int i;
//	//cout << a[0] << endl;
//	for (i = 1; i <= sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << sizeof(a) / sizeof(a[0]) << endl;
//		if (InsertList(A, i, a[i - 1]) == 0)
//		{
//			printf("λ�ò��Ϸ�");
//			return -1;
//		}
//	}
//	return true;
//}
int main()
{
	
	DataType a[] = {8,10,1,21,67,91};
	DataType b[] = {55,9,10,13,21,78,91};
	LinkList A, B, C;
	InitList(A);
	InitList(B);
	/*LinkList test;
	InitList(test);
	InsertNum(test, a);
	PrintList(test);
	system("pause");*/
	int i;
	//cout << a[0] << endl;
	// ���鸳ֵ������
	for (i = 1; i <= sizeof(a) / sizeof(a[0]); i++)
	{

		if (InsertList(A, i, a[i - 1]) == 0)
		{
			printf("λ�ò��Ϸ�");
			return -1;
		}
	}

	//cout << a[0] << endl;
	for (i = 1; i <= sizeof(b) / sizeof(b[0]); i++)
	{

		if (InsertList(B, i, b[i - 1]) == 0)
		{
			printf("λ�ò��Ϸ�");
			return -1;
		}
	}
	PrintList(A); PrintList(B);

	MergeList(A, B, C);
	PrintList(C);
	system("pause");
	return 0;

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
			if (C->next == NULL)
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
			else if(C->next->data<qb->data)
			{
				qb->next = C->next;
				C->next = qb;
			}
			else
			{
				free(qb);
			}
		}
	}
	while (pa)
	{
		qa = pa;
		pa = pa->next;
		if (C->next&&C->next->data < qa->data)
		{
			qa->next = C->next;
			C->next = qa;
		}
	}
	while (pb)
	{
		qb = pb;
		pb = pb->next;
		if (C->next&&C->next->data < qb->data)
		{
			qb->next = C->next;
			C->next = qb;
		}
		else
		{
			free(qb);
		}
	}

}