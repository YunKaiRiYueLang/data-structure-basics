#include"LinkList.h"
#include<iostream>				  
void Sort(LinkList &S)
{
	ListNode *p, *q, *r;
	DataType t;
	p = S->next;
	while (p->next)
	{
		r = p;
		q = p->next;
		while (q)
		{
			if (r->data > q->data)
				r = q;
			q = q->next;
		}
		if (p != r)
		{
			t = p->data;
			p->data = r->data;
			r->data = r->data;
		}
		p = p->next;
	}
}
void Interction(LinkList &A, LinkList &B, LinkList &C)
{
	ListNode *pa, *pb, *pc;
	Sort(A);
	
}
int main()
{
	int i;
	DataType a[] = {5,9,6,20,70,58,44,81};
	DataType b[] = { 21,81,8,31,5,66,20,95,50 };
	LinkList A, B, C;
	ListNode *p;
	InitList(A);
	InitList(B);
	for (i = 1; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (InsertList(A, i, a[i - 1]) == 0)
		{
			printf("位置不合法");
			return -1;
		}
	}
	for (i = 1; i < sizeof(b) / sizeof(b[0]); i++)
	{
		if (InsertList(B, i, b[i - 1]) == 0)
		{
			printf("位置不合法");
			return -1;
		}
	}
	PrintList(A); PrintList(B);


}