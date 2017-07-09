#include <stdio.h>
#include "SeqList.h"

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

		R[inspace].data = data;
		R[inspace].key = key;
	}
}

int main()
{
	SeqList arr = { 0,13,25,36,42,48,56,64,69,78,85,92 };

	int index = BinSearch(arr, 42, 1, 11);

	printf("%d\n", index);

	index = BinSearch(arr, 80, 1, 11);

	printf("%d\n", index);
}