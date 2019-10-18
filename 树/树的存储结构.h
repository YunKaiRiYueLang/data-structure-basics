#pragma once
/*˫�ױ�ʾ���洢���ṹ,���ײ�����˫��,����������˫�׽ڵ�,���ҵ��Ͻڵ�*/

/*˫�ױ�ʾ������*/
#define MaxSize 200
typedef  int DataType;
typedef struct Pnode
{//�ڵ㶨��
	DataType data;//����Ԫ
	int parent;//�ýڵ�˫���������е��±�
}PNode;

typedef struct
{//���Ͷ���
	PNode node[MaxSize];
	int num;
}PTree;

/*n���ڵ�,n����������,n���������ݺ�ͷָ���㹹��˳���*/
/*��Ȼ��,�Һ�������,������˫�ײ�����*/
typedef struct CNode
{//���ӽ��
	int child;
	struct CNode *next;
}ChildNode;

typedef struct
{/*��ͷָ��*/
	DataType data;
	ChildNode *firstchild;
}DataNode;
typedef struct
{//���ӱ�ʾ������.
	DataNode node[MaxSize];
	int num, root;
};
/*�����ֵܱ�ʾ��,���һ��.*/
typedef struct CSNode
{
	DataNode data;
	struct  CSNode *firstchild, *nextsibling;
}CSNode,*CSTree;
//��������Ķ��������ʾ,��õĴ洢�ṹ.