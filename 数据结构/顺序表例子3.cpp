/*设计表示任意长的正整数的数据结构,计算任意给定的整数之和的算法*/


/*输入9 9 9 9 9 9  9 9 9  9 9 9 9 9 的形式.*/
/*经典数据结构习题*/
#include"SeqList.h"
#include<iostream>

using namespace std;
#define MaxLen 100
typedef int sqlist[MaxLen];
int input(sqlist A)
{/*输入数组a中的数据,注意格式,返回位数*/
	int i;
	for (int i = 0; i < MaxLen; i++)
	{
		A[i] = 0;
	}
	printf("输入一个正整数的各位(-1结束)\n");
	i = 0;
	while (1)
	{
		cin >> A[i];
		if (A[i] < 0)
		{
			break;
		}
		i++;
	}
	return i;
}

void output(sqlist A, int low, int high)
{
	int i;
	for (i = low; i < high; i++)
	{
		printf("%d", A[i]);
	}
	printf("\n");
}
void move(sqlist A, int na)
{/*移动位置*/
	int i;
	for (i = 0; i < na; i++)
		A[MaxLen - 1 - i] = A[na - i - 1];
}
int add(sqlist &A, int na, sqlist B, int nb)
{
	int nc, i, j;
	int length = 0;
	if (na > nb)
		nc = na;
	else
	{
		nc = nb;
	}
	move(A, na);
	move(B, nb);
	for (i = MaxLen - 1; i >= MaxLen - nc; i--)
	{
		j = A[i] + B[i];
		if (j > 9)
		{
			A[i - 1] = A[i - 1] + 1;
			A[i] = j - 10;
		}
		else
		{
			A[i] = j;
		}
		if (i == MaxLen - nc)
		{
			if (j > 9)
			{
				//A[i - 1] = 1;
				length = nc + 1;
			}
			else
			{
				length = nc;
			}
		}
	}
	return length;
}
int main()
{
	sqlist A, B;
	int na, nb, nc;
	na = input(A);
	cin.ignore();
	nb = input(B);
	printf("数A:");
	output(A, 0, na);
	printf("数B:");
	output(B, 0, nb);
	nc = add(A, na, B, nb);
	printf("相加后的结果:");
	output(A, MaxLen - nc, MaxLen);
	system("pause");
}