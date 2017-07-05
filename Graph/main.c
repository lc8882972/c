#include <stdio.h>
#include <limits.h>

#define MaxVertexNum 50
#define TRUE 1;

// 邻接矩阵
typedef struct {
	char vexs[MaxVertexNum];
	int arcs[MaxVertexNum][MaxVertexNum];
}MGraph;

// 邻接表
typedef struct node {
	int adjvex;
	struct  node * next;
}EdgeNode;

typedef struct vnode {
	char vertex;
	EdgeNode * link;
}VNode, Adjlist[MaxVertexNum];

typedef Adjlist ALGraph;

void CreateMGraph(MGraph* G, int n, int e) {
	int i, j, k, w;
	scanf("%d,%d", &n, &e);
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
		scanf("%d,%d", &i, &j);
		p = (EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvex = j;
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
	for (j = 0; i < n; n++)
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
		K = DeQueue(&Q);
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
	EnQueue(&Q);

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

int main()
{
	MGraph g;
	CreateMGraph(&g, 4, 4);
	/* 我的第一个 C 程序 */
	printf("Hello, World! \n");

	return 0;
}