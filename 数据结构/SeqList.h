#pragma once
/*一些基础程序,在返回值,断言,io输出等,不设置统一规定,重点放在基础结构上*/
/*传值 有用指针,有用引用,没统一,我故意的*/
#define listsize 100
typedef int DataType;
typedef struct {
	DataType list[listsize];/*listsize的设置根据需求有时会+1*/
	int length;
}SeqList;

void InitList(SeqList *L)
{/*初始化线性表*/
	L->length = 0;
}
int ListEmpty(SeqList L)
{/*判断线性表是否为空,空返回1 否则0*/
	if (L.length == 0)
		return 1;
	else
	{
		return 0;
	}
}

int GetElement(SeqList L, int i, DataType *e)
{/*查找第i个元素,成功返回给e,返回1.否侧-1表示失败*/
	if (i<1 || i>L.length)	return -1;//检查i合法性
	*e = L.list[i - 1];// 返还e
	return 1;
}
int LocateElement(SeqList L, DataType e)
{/*查找值e的元素,返回序号 1 到 L.length*/
	for (int i = 0; i < L.length; i++)
	{
		if (L.list[i] == e)
			return i + 1;
	}
	return -1;
}
int InserList(SeqList &L, int i, DataType e)
{/*在顺序表种第i(1到length)插入e,成功返回1,不合法情况-1表满返回0*/
	if (i<1 || i>L.length + 1)
	{
		return -1;
	}
	if (L.length >= listsize)
	{
		return 0;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.list[j] = L.list[j - 1];
	}
	L.list[i - 1] = e;
	L.length++;
	return 1;
}
int DeleteList(SeqList &L, int i, DataType &e)
{/*删除第i(1到length)个元素,用e返回改*/
	if (i<1 || i>L.length)	return -1;//检查i是否有效
	e = L.list[i - 1];
	for (int j = i; j < L.length - 1; j++)
	{
		L.list[j]=L.list[j+1];
	}
	L.length--;
	return 1;
}
int ListLength(SeqList L)
{
	return L.length;
}
void ClearList(SeqList &L)
{
	L.length =0;
}
void UnionAB(SeqList &LA, SeqList LB)
{/*将lb中不再la中的元素插入la*/
	int i, flag, pos;
	DataType e;
	for (i = 1; i < LB.length+1; i++)
	{
		flag = GetElement(LB, i, &e);
		if (flag == 1)
		{
			pos = LocateElement(LA, e);
			if (pos == -1)
			{
				InserList(LA, LA.length + 1,e);
			}
		}
	}
}
