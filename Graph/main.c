#include <stdio.h>
#include <limits.h>
#include "queue.h"
#include "SeqStack.h"
#define MaxVertexNum 50 //顶点最大数
#define TRUE 1
// 邻接矩阵
typedef struct {
	char vexs[MaxVertexNum];  // 顶点数组 V(G)
	int arcs[MaxVertexNum][MaxVertexNum]; //邻接矩阵 
}MGraph;

typedef int VRType;
typedef struct {
	char ver;
	VRType lowcost;
} minedge[MaxVertexNum];

// 邻接表
typedef struct node {
	int adjvex;// 顶点序号
	struct  node * next; // 指向下条边的指针
}EdgeNode;

typedef struct vnode {
	char vertex; // 顶点域
	EdgeNode * link; // 边表头指针
}VNode, Adjlist[MaxVertexNum]; //邻接表

typedef Adjlist ALGraph; // 定义为图类型
// 矩阵
void CreateMGraph(MGraph* G, int n, int e) {
	int i, j, k, w;
	scanf("%d,%d", &n, &e); // 读入顶点数，边数
	for (i = 0; i < n; i++)
	{
		scanf("%c", &G->vexs[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			G->arcs[i][j] = INT_MAX;
		}
	}

	for (k = 0; k < e; k++) {
		scanf("%d,%d,%d", &i, &j, &w);
		G->arcs[i][j] = w;
		G->arcs[j][i] = w;
	}
}
// 图 链表
void CreateGraph(ALGraph GL, int n, int e) {
	int i, j, k;
	EdgeNode * p;

	for (i = 0; i < n; i++)
	{
		GL[i].vertex = getchar();
		GL[i].link = NULL;
	}

	for (k = 0; k < e; k++)
	{
		// 0，3 0，4
		scanf("%d,%d", &i, &j);
		p = (EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvex = j; //2 //3
		p->next = GL[i].link;
		GL[i].link = p;

		p = (EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvex = i;
		p->next = GL[j].link;
		GL[j].link = p;
	}
}

int visited[20];

// 深度优先搜索
void DFS(MGraph G, int i, int n)
{
	int j;
	printf("v%d->", i);
	visited[i] = 1;
	for (j = 0; j < n; n++)
	{
		if (G.arcs[i][j] == 1 && !visited[j])
			DFS(G, j, n);
	}
}

void DFS1(ALGraph G, int i)
{
	EdgeNode * p;
	int j;
	printf("v%d->", i);
	visited[i] = 1;
	p = G[i].link;
	while (p != NULL)
	{
		j = p->adjvex;
		if (!visited[j])
			DFS1(G, j);

		p = p->next;
	}
}

// 广度优先搜索

void BFS(MGraph G, int i, int n) {
	CirQueue Q;
	int k, j;
	InitQueue(&Q);

	printf("v%d->", i);

	visited[i] = 1;

	EnQueue(&Q, i);
	while (!QueueEmpty(&Q))
	{
		k = DeQueue(&Q);
		for (j = 0; j < n; j++)
		{
			if (G.arcs[k][j] == 1 && !visited[j]) {
				printf("v%d->", j);
				visited[j] = TRUE;
				EnQueue(&Q, j);
			}
		}
	}
}

void BFS1(ALGraph G, int i, int n) {
	CirQueue Q;
	int k, j;
	InitQueue(&Q);
	EdgeNode * p;

	int visited[20];
	printf("v%d->", i);
	visited[i] = 1;
	EnQueue(&Q,i);

	while (!QueueEmpty(&Q))
	{
		k = DeQueue(&Q);
		p = G[k].link;

		while (p != NULL)
		{
			j = p->adjvex;
			if (!visited[j]) {
				printf("v%d->", j);
				visited[j] = 1;
				EnQueue(&Q,j);
			}

			p = p->next;

		}
	}
}

// 普瑞姆算法
void Prim(MGraph G, char u, int n) 
{
	int k, v, j;
	//k = Vtxnum(G, u);

	//for (v = 0; v < n; v++)
	//{
	//	if (v != k) 
	//	{
	//		minedge[v].ver = u;
	//		minedge[v].lowcost = G.arcs[k][v];
	//	}
	//}
	//minedge[k].lowcost = 0;


}

//拓扑排序
void TopuSort(ALGraph G, int n) 
{
	int i, j, m = 0;
	int inde[20];
	SeqStack S;
	EdgeNode *p;
	for ( i = 0; i < n; i++)
	{
		inde[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		p = G[i].link;
		while (p)
		{
			inde[p->adjvex] ++;
			p = p->next;
		}
	}

	InitStack(&S);

	for (i = 0; i < 0; i++)
	{
		if (inde[i] == 0)
			push(&S, i);
	}

	while (!StackEmpty(&S))
	{
		i = Pop(&S);
		printf("v%d", i);
		m++;
		p = G[i].link;
		while (p)
		{
			j = p->adjvex;
			inde[j] --;

			if (inde[j] == 0)
				push(&S, j);
			p = p->next;
		}
	}

	if (m < n) 
	{
		printf("The Graph has acycle!");
	}
}
int main()
{
	MGraph g;
	CreateMGraph(&g, 4, 4);
	/* 我的第一个 C 程序 */
	printf("Hello, World! \n");

	return 0;
}