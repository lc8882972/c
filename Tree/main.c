#include <stdio.h>
#include<string.h>

#define n 8
#define m 2*n-1

typedef struct {
	float weight;
	int lchild, rchild, parent;
}HTNode;
typedef HTNode HuffmanTree[m + 1];

typedef struct {
	char ch;
	char bits[n + 1];
	int len;
}CodeNode;

typedef CodeNode HuffmanCode[n + 1];

void select(HuffmanTree T, int k, int *s1, int *s2)
{
	int i, j;
	int min = 101;
	for (i = 1; i <= k; i++)
	{
		if (T[i].weight < min && T[i].parent == 0)
		{
			j = i;
			min = T[i].weight;
		}
	}

	*s1 = j;
	min = 32767;
	for (i = 1; i <= k; i++)
	{
		if (T[i].weight < min && T[i].parent == 0 && i != *s1)
		{
			j = i;
			min = T[i].weight;
		}
	}
	*s2 = j;
}

void ChuffmanTree(HuffmanTree HT)
{
	int s1, s2;
	int i,j;
	for (i = 1; i <= m; i++)
	{
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
		HT[i].weight = 0;
	}

	for (i = 1; i <= n; i++)
	{
		scanf_s("%f", &HT[i].weight);
		for (j = n + 1; j <= m; j++)
		{
			select(HT, j - 1, &s1, &s2);
		}

		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

void HuffmanEncoding(HuffmanTree HT, HuffmanCode HC)
{
	int c, p, i;
	char cd[n + 1];
	int start;
	cd[n] = '\0';
	for (i = 0; i < n; i++)
	{
		start = n;
		c = i;
		while ((p = HT[c].parent) > 0)
		{
			cd[--start] = (HT[p].lchild == c) ? '0' : '1';
			c = p;
		}

		strcpy(HC[i].bits, &cd[start]);
		HC[i].len = n - start;
	}
}
// 二叉树 定义
typedef int DataType ;
typedef struct node {
	DataType data;
	struct node *lchild, *rchild;
}BinNode;

typedef BinNode *BinTree;

// 孩子链表法
typedef struct cnode { // 孩子链表节点类型
	int child; // 孩子节点在指针数组中的序号
	struct cnode *next;
}CNode;

typedef struct {
	DataType data; // 树中节点数据域
	CNode *firstchild; // 孩子节点头指针
}PANode; // 指针数组节点类型

typedef struct {
	PANode nodes[100]; // 指针数组
	int num, r; // num 为节点数，r为根节点在指针数组中的位置
}CTree;

int main()
{
	//HuffmanTree ht;
	//
	//ChuffmanTree(ht);
	return 0;
}

