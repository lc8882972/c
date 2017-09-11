#pragma once
typedef int KeyTyke ;
typedef int DataTyke;
typedef struct node {
	KeyTyke key;
	//DataTyke data;
	struct node *lchild, *rchild;
}BSTNode;

typedef BSTNode * BSTree;
