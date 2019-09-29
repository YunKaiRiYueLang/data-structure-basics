/*顺序表拆成两部分,小于等于0在左端,大于0在右端.要求不占用额外存储空间.*/

/*思路,两端扫描,遇到不符要求停下若i j 合法,交换就行了,用加法运算实现不占用额外存储空间*/

#include<iostream>
#include"SeqList.h"
using namespace std;
void SqlistSeqlist(SeqList&L);
int main()
{
	int a[] = { -12,3,-6,-10,20,-7,9,-20 };
	SeqList L;
	InitList(&L);
	int  n = sizeof(a) / sizeof(a[0]);
	for (int i = 1; i <= n; i++)
	{
		if (InserList(L, i, a[i - 1]) == 0)
			return -1;
	}

	printf("顺序表L种的元素:\n");
	int flag; DataType e;
	for (int i = 1; i < L.length + 1; i++)
	{/*输出顺序表LA*/
		flag = GetElement(L, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");
	SqlistSeqlist(L);
	printf("排序后顺序表L种的元素:\n");

	for (int i = 1; i < L.length + 1; i++)
	{/*输出顺序表LA*/
		flag = GetElement(L, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");
	system("pause");

}
void SqlistSeqlist(SeqList &L)
{/*题目要求的算法,交换,不占用额外存储空间*/
	int i, j;
	i = 0; j = L.length - 1;
	while (i < j)
	{
		while (L.list[i]<=0)
		{
			i++;
		}
		while (L.list[j] > 0)
		{
			j--;
		}
		if (i < j)
		{
			L.list[i]=L.list[i]+L.list[j];
			L.list[j] = L.list[i] - L.list[j];
			L.list[i] = L.list[i] - L.list[j];
		}
	}
}