#include <stdio.h>
#include "seqlist.h"
#include "LinkList.h"

// ÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(SeqList R, int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		if (R[i].key < R[i - 1].key)
		{
			R[0] = R[i];
			for (j = i - 1; R[0].key < R[j].key; j--)
				R[j + 1] = R[j];
			R[j + 1] = R[0];
		}
	}
}

/* œ£∂˚≈≈–Ú */
void ShellInsert(SeqList R, int dk, int n)
{
	int i, j;
	for (i = dk + 1; i <= n; i++)
		if (R[i].key < R[i - dk].key)
		{
			R[0] = R[i];
			j = i - dk;
			while (j > 0 && R[0].key < R[j].key)
			{
				R[j + dk] = R[j];
				j = j - dk;
			}
			R[j + dk] = R[0];
		}
}

void ShellSort(SeqList R, int d[], int t, int n)
{
	int k;
	for (k = 0; k < t; k++)
	{
		ShellInsert(R, d[k], n);
		for (int i = 1; i <= n; i++)
		{
			printf("%d,", R[i]);
		}
		printf("\n");
	}

}
/* œ£∂˚≈≈–Ú */

// √∞≈›≈≈–Ú

void BubbleSort(SeqList R, int n)
{
	int i, j, flag;
	for (i = 1; i < n; i++)
	{
		flag = 0;
		for (j = n; j >= i + 1; j--)
		{
			if (R[j].key < R[j - 1].key)
			{
				R[0] = R[j - 1];
				R[j - 1] = R[j];
				R[j] = R[0];
				flag = 1;
			}
		}
		if (flag == 0) return;
	}
}

// øÏÀŸ≈≈–Ú
int Partition(SeqList R, int i, int j)
{
	RecType x = R[i];
	while (i < j)
	{
		while (i < j && R[j].key >= x.key)
			j--;
		if (i < j) {
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i].key <= x.key)
			i++;

		if (i < j) {
			R[j] = R[i];
			j--;
		}
	}

	R[i] = x;
	return i;
}

void QuickSort(SeqList R, int low, int high)
{
	int p;
	if (low < high) {
		p = Partition(R, low, high);
		QuickSort(R, low, p - 1);
		QuickSort(R, p + 1, high);
	}
}

// —°‘Ò≈≈–Ú
void SelectSort(SeqList R, int n)
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		k = i;

		for (j = i + 1; j <= n; j++)
		{
			if (R[j].key < R[k].key)
				k = j;
		}

		if (k != i)
		{
			R[0] = R[i];
			R[i] = R[k];
			R[k] = R[0];
		}
	}
}

//µ•¡¥±Ì—°‘Ò≈≈–Ú
LinkList LselectSort(LinkList head)
{
	ListNode *p, *q, *r, *s, *t, *t1;

	t = NULL;
	while (head != NULL)
	{
		s = head;
		p = head;
		q = NULL;
		r = NULL;
		while (p != NULL)
		{
			if (p->data < s->data)
			{
				s = p;
				r = q;
			}
			q = p;
			p = p->next;
		}

		if (s == head)
			head = head->next;
		else
		{
			r->next = s->next;
		}

		if (t == NULL) {
			t = s;
			t1 = t;
		}
		else
		{
			t1->next = s;
			t1 = s;
		}
	}
	t1->next = NULL;
	return t;
}

// ∂—≈≈–Ú
void Sift(SeqList R, int i, int h)
{
	int j;
	RecType x = R[i];
	j = 2 * i;
	while (j <= h)
	{
		if (j < h && R[j].key < R[j + 1].key)
			j++;

		if (x.key >= R[j].key)
			break;

		R[i] = R[j];
		i = j;
		j = 2 * i;
	}
	R[i] = x;
}

void HeapSort(SeqList R, int n)
{
	int i;
	for (i = n / 2; i > 0; i--)
	{
		Sift(R, i, n);
	}
	for (i = n; i > 1; i--)
	{
		R[0] = R[1];
		R[1] = R[i];
		R[i] = R[0];
		Sift(R, i, i - 1);
	}
}

// πÈ≤¢≈≈–Ú

void Merge(SeqList R, SeqList MR, int low, int m, int high)
{
	int i, j, k;
	i = low;
	j = m + 1;
	k = low;
	while (i <= m && j <= high)
	{
		if (R[i].key <= R[i].key)
			MR[k++] = R[i++];
		else
		{
			MR[k++] = R[j++];
		}
		while (i <= m)
		{
			MR[k++] = R[i++];
		}

		while (j <= high)
		{
			MR[k++] = R[j++];
		}
	}
}

void MergePass(SeqList R, SeqList MR, int len, int n) 
{
	int i, j;
	for (i = 1; i + 2 * len - 1 <= n; i = i + 2 * len)
		Merge(R, MR, i, i + len - 1, i + 2 * len - 1);
	if (i + len - 1 < n)
		Merge(R, MR, i, i + len - 1, n);
	else
	{
		for (j = i; i <=n ; j++)
		{
			MR[j] = R[j];
		}
	}
}

void MergeSort(SeqList R, SeqList MR, int n) 
{
	int len = 1;
	while (len <n)
	{
		MergePass(R, MR, len, n);
		len = len * 2;
		MergePass(MR, R, len, n);
		len = len * 2;
	}
}

// œ‰≈≈–Ú

void BinSort(SeqList R, int n) 
{
	
}
int main()
{
	SeqList arr = { 46,39,17,23,28,55,18,46 };

	InsertSort(arr, 7);
	//for (int i = 0; i < 8; i++)
	//{
	//	printf("%d\n", arr[i]);
	//}

	SeqList arr_shell = { 0,36,25,48,27,65,25,43,58,76,32 };
	int d[] = { 5,3,1 };
	ShellSort(arr_shell, d, 3, 10);

	SeqList arr_buble = { 0,36,28,45,13,67,36,18,56 };

	BubbleSort(arr_buble, 8);
	printf("BubbleSort\n");
	for (int i = 1; i <= 8; i++)
	{
		printf("%d,", arr_buble[i]);
	}
	printf("\n");
	SeqList arr_quick = { 0,47,33,61,82,72,11,25,47 };

	QuickSort(arr_quick, 1, 8);

	printf("QuickSort\n");
	for (int i = 1; i <= 8; i++)
	{
		printf("%d,", arr_quick[i]);
	}

	SeqList arr_select = { 0,38,33,65,82,76,38,24,11 };
	SelectSort(arr_select, 8);
	printf("\n");

	printf("SelectSort\n");
	for (int i = 1; i <= 8; i++)
	{
		printf("%d,", arr_select[i]);
	}

	printf("\n");
	/* Œ“µƒµ⁄“ª∏ˆ C ≥Ã–Ú */
	printf("Hello, World! \n");

	return 0;
}