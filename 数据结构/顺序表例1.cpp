#include"SeqList.h"
#include<iostream>/*别纠结c还是c++风格*/
using namespace std;
int  main()
{
	int i, flag;
	DataType e;
	DataType a[] = { 2,3,17,20,9,31 };
	DataType b[] = { 8,31,5,17,22,9,48,67 };
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

	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		if (InserList(LB, i + 1, b[i]) == 0)/*注意我在头文件了,有的函数用指针,有的则用了引用*/
		{/*B给lB*/
			return -1;
		}
	}

	printf("顺序表A种的元素:\n");
	for (int i = 1; i < LA.length+1; i++)
	{/*输出顺序表LA*/
		flag = GetElement(LA, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");

	printf("顺序表LB种的元素:\n");
	for (int i = 1; i < LB.length+1; i++)
	{/*输出顺序表LA*/
		flag = GetElement(LB, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");

	printf("将LB中但不再LA中的元素插入到LA中:\n");
	UnionAB(LA, LB);
	for (int i = 1; i < LA.length+1; i++)
	{/*输出顺序表LA*/
		flag = GetElement(LA, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	system("pause");
}

/*看文档,写注释,很重要啊,不然有人写和事实不一样的逻辑,容易下意识呗误导*/