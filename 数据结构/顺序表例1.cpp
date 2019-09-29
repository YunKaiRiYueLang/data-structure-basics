#include"SeqList.h"
#include<iostream>/*�����c����c++���*/
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
		
		if (InserList(LA,i+1, a[i]) == 0)/*ע������ͷ�ļ���,�еĺ�����ָ��,�е�����������*/
		{/*a��la*/
			return -1;
		}
	}

	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		if (InserList(LB, i + 1, b[i]) == 0)/*ע������ͷ�ļ���,�еĺ�����ָ��,�е�����������*/
		{/*B��lB*/
			return -1;
		}
	}

	printf("˳���A�ֵ�Ԫ��:\n");
	for (int i = 1; i < LA.length+1; i++)
	{/*���˳���LA*/
		flag = GetElement(LA, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");

	printf("˳���LB�ֵ�Ԫ��:\n");
	for (int i = 1; i < LB.length+1; i++)
	{/*���˳���LA*/
		flag = GetElement(LB, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	printf("\n");

	printf("��LB�е�����LA�е�Ԫ�ز��뵽LA��:\n");
	UnionAB(LA, LB);
	for (int i = 1; i < LA.length+1; i++)
	{/*���˳���LA*/
		flag = GetElement(LA, i, &e);
		if (flag == 1)
		{
			printf("%4d", e);
		}
	}
	system("pause");
}

/*���ĵ�,дע��,����Ҫ��,��Ȼ����д����ʵ��һ�����߼�,��������ʶ����*/