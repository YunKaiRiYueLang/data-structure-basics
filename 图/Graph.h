#pragma once
#include<malloc.h>
#include<iostream>

#if 0
/* 图的邻接矩阵表示法 */
#define MaxVertexNum 100    
/* 最大顶点数设为100 */
#define INFINITY 65535        
/* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;
/* 用顶点下标表示顶点,为整型 */
typedef int WeightType;
/* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */
							  /* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;
/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum];/* 邻接矩阵 */
	DataType Data[MaxVertexNum];/* 存顶点的数据 */
	/* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph;


/* 以邻接矩阵存储的图类型 */
MGraph CreateGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;     /* 初始化邻接矩阵 */     /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{      /* 插入边 <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;          /* 若是无向图，还要插入边<V2, V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */
	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */          /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);              /* 注意：如果权重不是整型，Weight的读入格式要改 */
			InsertEdge(Graph, E);
		}
	}      /* 如果顶点有数据的话，读入数据 */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &(Graph->Data[V]));
	return Graph;
}
#endif



/*c语言代码*/
/* 图的邻接表表示法 */
#define MaxVertexNum 100    /* 最大顶点数设为100 */ 
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */ /* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode { Vertex V1, V2;      /* 有向边<V1, V2> */     WeightType Weight;  /* 权重 */ };
typedef PtrToENode Edge; /* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        /* 邻接点下标 */
	WeightType Weight;  /* 边权重 */
	PtrToAdjVNode Next;    /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;/* 边表头指针 */
	DataType Data;            /* 存顶点的数据 */     /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
}
AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;     /* 顶点数 */
	int Ne;     /* 边数   */
	AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V;
	LGraph Graph;
	Graph = (LGraph)malloc(sizeof(struct GNode)); /* 建立图 */     Graph->Nv = VertexNum;
	Graph->Ne = 0;     /* 初始化邻接表头指针 */     /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E) {
	PtrToAdjVNode NewNode;
	/* 插入边 <V1, V2> */     /* 为V2建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	/* 将V2插入V1的表头 */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;              /* 若是无向图，还要插入边 <V2, V1> */
	/* 为V1建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;     /* 将V1插入V2的表头 */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}
LGraph BuildGraph() {
	LGraph Graph;     Edge E;     Vertex V;     int Nv, i;
	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */
	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */          /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);              /* 注意：如果权重不是整型，Weight的读入格式要改 */
			InsertEdge(Graph, E);
		}
	}      /* 如果顶点有数据的话，读入数据 */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &(Graph->G[V].Data));
	return Graph;
}

#if 0
/*c语言dfs*/
/* 邻接表存储的图 - DFS */
void Visit(Vertex V) {
	printf("正在访问顶点%d\n", V);
}
/* Visited[]为全局变量，已经初始化为false */
void DFS(LGraph Graph, Vertex V, void(*Visit)(Vertex))
{   /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
	PtrToAdjVNode W;
	Visit(V); /* 访问第V个顶点 */
	Visited[V] = true; /* 标记V已访问 */
	for (W = Graph->G[V].FirstEdge; W; W = W->Next) /* 对V的每个邻接点W->AdjV */
		if (!Visited[W->AdjV])    /* 若W->AdjV未被访问 */
			DFS(Graph, W->AdjV, Visit);    /* 则递归访问之 */
}

/* 邻接矩阵存储的图 - BFS */
/* IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。  */ /* 此函数根据图的不同类型要做不同的实现，关键取决于对不存在的边的表示方法。*/ /* 例如对有权图, 如果不存在的边被初始化为INFINITY, 则函数实现如下:         */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}
/* Visited[]为全局变量，已经初始化为false */
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{   /* 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索 */
	Queue Q;
	Vertex V, W;
	Q = CreateQueue(MaxSize); /* 创建空队列, MaxSize为外部定义的常数 */     /* 访问顶点S：此处可根据具体访问需要改写 */
	Visit(S);
	Visited[S] = true; /* 标记S已访问 */
	AddQ(Q, S); /* S入队列 */
	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);  /* 弹出V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */             /* 若W是V的邻接点并且未访问过 */
			if (!Visited[W] && IsEdge(Graph, V, W)) {                 /* 访问顶点W */
				Visit(W);
				Visited[W] = true; /* 标记W已访问 */
				AddQ(Q, W); /* W入队列 */
			}
	} /* while结束*/
}





/* 邻接表存储 - 拓扑排序算法 */
bool TopSort(LGraph Graph, Vertex TopOrder[])
{ /* 对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 */
	int Indegree[MaxVertexNum], cnt;     Vertex V;     PtrToAdjVNode W;        Queue Q = CreateQueue(Graph->Nv);
	/* 初始化Indegree[] */
	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;              /* 遍历图，得到Indegree[] */
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; /* 对有向边<V, W->AdjV>累计终点的入度 */                  /* 将所有入度为0的顶点入列 */
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			AddQ(Q, V);                  /* 下面进入拓扑排序 */
	cnt = 0;
	while (!IsEmpty(Q))
	{
		V = DeleteQ(Q); /* 弹出一个入度为0的顶点 */
		TopOrder[cnt++] = V; /* 将之存为结果序列的下一个元素 */         /* 对V的每个邻接点W->AdjV */
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)/* 若删除V使得W->AdjV入度为0 */
				AddQ(Q, W->AdjV); /* 则该顶点入列 */
	} /* while结束*/
	if (cnt != Graph->Nv)
		return false; /* 说明图中有回路, 返回不成功标志 */
	else
		return true;
}
#endif