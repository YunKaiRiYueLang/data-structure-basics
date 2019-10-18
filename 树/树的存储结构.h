#pragma once
/*双亲表示法存储树结构,容易查找其双亲,反复调用求双亲节点,可找到肯节点*/

/*双亲表示法定义*/
#define MaxSize 200
typedef  int DataType;
typedef struct Pnode
{//节点定义
	DataType data;//数据元
	int parent;//该节点双亲在数组中的下标
}PNode;

typedef struct
{//类型定义
	PNode node[MaxSize];
	int num;
}PTree;

/*n个节点,n个孩子链表,n个结点的数据和头指针你构成顺序表*/
/*显然他,找孩子容易,但是找双亲不方便*/
typedef struct CNode
{//孩子结点
	int child;
	struct CNode *next;
}ChildNode;

typedef struct
{/*表头指针*/
	DataType data;
	ChildNode *firstchild;
}DataNode;
typedef struct
{//孩子表示法定义.
	DataNode node[MaxSize];
	int num, root;
};
/*孩子兄弟表示法,结合一下.*/
typedef struct CSNode
{
	DataNode data;
	struct  CSNode *firstchild, *nextsibling;
}CSNode,*CSTree;
//这个是树的二叉链表表示,最常用的存储结构.