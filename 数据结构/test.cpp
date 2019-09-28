#include"SeqList.h"
#include<iostream>/*别纠结c还是c++风格*/
using namespace std;
int  main()
{
	int i, flag;
	DataType e;
	DataType a[] = { 2,3,17,20,9,31 };
	DataType b[] = { 8,31,5,17,22,9,8,67 };
	SeqList LA, LB;
	InitList(&LA);
	InitList(&LB);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (InserList(LA,i+1, a[i]) == 0)/*注意我在头文件了,有的函数用指针,有的则用了引用*/
		{/*a给la*/
			return -1;
		}
	}
	printf("顺序表A种的元素:\n");
	for (int i = 1; i < LA.length; i++)
	{
		flag = GetElement(LA, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");
	system("pause");
}