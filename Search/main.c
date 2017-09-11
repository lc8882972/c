#include <stdio.h>
#include "SeqList.h"
#include "BSTree.h"

// 二分查找算法
int BinSearch(SeqList R, KeyType k, int low, int high)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (R[mid].key == k)
			return mid;

		if (R[mid].key > k)
		{
			return BinSearch(R, k, low, mid - 1);
		}
		else
		{
			return BinSearch(R, k, mid + 1, high);
		}
	}

	return 0;
}

void BinInsert(SeqList R, KeyType key, DataType data, int n) 
{
	int low = 1, high = n, mid, inspace, i;
	int find = 0;
	while (low <= high && !find)
	{
		mid = (low + high) / 2;
		if (key < R[mid].key)
			high = mid - 1;
		else if (key > R[mid].key)
			low = mid + 1;
		else
			find = 1;

		if (find)
			inspace = mid;
		else
			inspace = low;

		for (i = n; i >= inspace; i--) 
		{
			R[i + 1] = R[i];
		}

		//R[inspace].data = data;
		R[inspace].key = key;
	}
}

BSTree InsertBST(BSTree * T, BSTNode * S) 
{

	BSTNode *f, *p = T;
	while (p)
	{
		f = p;

		if (S->key < p->key) 
			p = p->lchild;
		else
			p = p->rchild;
	}

	if (T == NULL) 
		T = S;
	else if(S->key < f->key)
		f->lchild = S;
	else
		f->rchild = S;

	return T;
}

BSTree CreateBST() 
{
	BSTree T = NULL;
	KeyTyke k;
	BSTNode *s;
	scanf("%d", &k);

	while (k)
	{
		s = (BSTNode *)malloc(sizeof(BSTNode));
		s->key = k;
		s->lchild = s->rchild = NULL;
		T = InsertBST(T, s);
		scanf("%d", &k);
	}

	return T;
}

BSTNode * SearchBST(BSTree tree, KeyTyke key)
{
	if (tree == NULL || tree->key == key)
		return tree;

	if (key < tree->key )
		return SearchBST(tree->lchild, key);
	else
		return SearchBST(tree->rchild, key);
}

//typedef struct {
//	KeyType key;
//	DataType data;
//}NodeType;
typedef NodeType HashTable[997];

//hash 线性探查法
int h(KeyType key, int m) 
{
	return key % m;
}

int HashSearch(HashTable HT, KeyType k, int m) 
{
	int d, temp;
	d = h(k, m);
	temp = d;

	while (HT[d].key != -32768)
	{
		if (HT[d].key == k) 
		{
			return d;
		}
		else 
		{
			d = (d + 1) % m;
		}

		if (d == temp)
			return -1;
	}

	return d;
}

int HashInsert(HashTable HT, NodeType s, int m) 
{
	int d;
	d = HashSearch(HT, s.key, m);
	if (d == -1) return -1;
	else 
	{
		if (HT[d].key == s.key) return 0;
		else
		{
			HT[d] = s;
			return 1;
		}
	}
}
int main()
{
	SeqList arr = { {0,0},{13,0},{25,0},{36,0},{42,0},{48,0},{56,0},{64,0},{69,0},{78,0},{85,0},{92,0} };


	int index = BinSearch(arr, 42, 1, 11);

	printf("%d\n", index);

	//index = BinSearch(arr, 80, 1, 11);

	//printf("%d\n", index);

	BSTree tree = CreateBST();

	BSTNode *n = SearchBST(tree, 53);
}