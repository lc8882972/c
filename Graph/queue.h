#include <stdio.h>

#define QueueSize 100
typedef char DataType;

typedef struct {
	DataType data[QueueSize];
	int front,rear;
}CirQueue;

void InitQueue(CirQueue * Q) {
	Q->front = Q->rear = 0;
}

int QueueEmpty(CirQueue * Q) 
{
	return Q->rear == Q->front;
}

int QueueFull(CirQueue * Q) 
{
	return(Q->rear + 1) % QueueSize == Q->front;
}

void EnQueue(CirQueue * Q, DataType x) 
{
	if (QueueFull(Q)) 
	{
		printf("Queue overflow");
	}
	else
	{
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % QueueSize;
	}
}

DataType GetFront(CirQueue * Q) 
{
	if (QueueEmpty(Q)) 
	{
		printf("Queue empty");
	}
	else
	{
		return Q->data[Q->front];
	}
}

DataType DeQueue(CirQueue * Q) 
{
	DataType x;
	if (QueueEmpty(Q))
	{
		printf("Queue empty");
	}
	else
	{
		x = Q->data[Q->front];
		Q->front = Q->front + 1;
		return x;
	}
}