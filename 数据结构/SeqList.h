#pragma once
/*һЩ��������,�ڷ���ֵ,����,io�����,������ͳһ�涨,�ص���ڻ����ṹ��*/
/*��ֵ ����ָ��,��������,ûͳһ,�ҹ����*/
#define listsize 100
typedef int DataType;
typedef struct {
	DataType list[listsize];/*listsize�����ø���������ʱ��+1*/
	int length;
}SeqList;

void InitList(SeqList *L)
{/*��ʼ�����Ա�*/
	L->length = 0;
}
int ListEmpty(SeqList L)
{/*�ж����Ա��Ƿ�Ϊ��,�շ���1 ����0*/
	if (L.length == 0)
		return 1;
	else
	{
		return 0;
	}
}

int GetElement(SeqList L, int i, DataType *e)
{/*���ҵ�i��Ԫ��,�ɹ����ظ�e,����1.���-1��ʾʧ��*/
	if (i<1 || i>L.length)	return -1;//���i�Ϸ���
	*e = L.list[i - 1];// ����e
	return 1;
}
int LocateElement(SeqList L, DataType e)
{/*����ֵe��Ԫ��,������� 1 �� L.length*/
	for (int i = 0; i < L.length; i++)
	{
		if (L.list[i] == e)
			return i + 1;
	}
	return -1;
}
int InserList(SeqList &L, int i, DataType e)
{/*��˳����ֵ�i(1��length)����e,�ɹ�����1,���Ϸ����-1��������0*/
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
{/*ɾ����i(1��length)��Ԫ��,��e���ظ�*/
	if (i<1 || i>L.length)	return -1;//���i�Ƿ���Ч
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
{/*��lb�в���la�е�Ԫ�ز���la*/
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
