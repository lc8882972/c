#pragma once
typedef int KeyType;
typedef int DataType;

typedef struct node {
	KeyType key;
	DataType data;
	struct  node * next;
}HTNode;

typedef HTNode * HT[997];

int h(KeyType key, int m)
{
	return key % m;
}

HTNode * HashSearch(HT T, KeyType k, int m) 
{
	HTNode *p = T[h(k, m)];

	while (p != nullptr && p->key !=k)
	{
		p = p->next;
	}

	return p;
}

int HashInsert(HT T, HTNode *s, int m) 
{
	int d;
	HTNode *p = HashSearch(T, s->key, m);

	if (p != nullptr) return 0;
	else
	{
		d = h(s->key, m);
		s->next = T[d];
		T[d] = s;
		return 1;
	}
}