/*单链表A B 元素非递减排列  算法将x x喝冰,得到递减有序的C(值相同只保留一个),要求利用原链表节点空间*/

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
			{/*为空直接插入*/
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
		{/*pb比较小*/
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