/*˳�����������,С�ڵ���0�����,����0���Ҷ�.Ҫ��ռ�ö���洢�ռ�.*/

/*˼·,����ɨ��,��������Ҫ��ͣ����i j �Ϸ�,����������,�üӷ�����ʵ�ֲ�ռ�ö���洢�ռ�*/

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

	printf("˳���L�ֵ�Ԫ��:\n");
	int flag; DataType e;
	for (int i = 1; i < L.length + 1; i++)
	{/*���˳���LA*/
		flag = GetElement(L, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");
	SqlistSeqlist(L);
	printf("�����˳���L�ֵ�Ԫ��:\n");

	for (int i = 1; i < L.length + 1; i++)
	{/*���˳���LA*/
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
{/*��ĿҪ����㷨,����,��ռ�ö���洢�ռ�*/
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