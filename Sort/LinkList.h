#pragma once

typedef int DataType ;
typedef struct node {
	DataType data;
	struct  node * next;
}ListNode;

typedef ListNode * LinkList;
