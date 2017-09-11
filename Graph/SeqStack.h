#pragma once
#define QueueSize 100
typedef char DataType;

typedef struct {
	DataType data[QueueSize];
	int front, rear;
}SeqStack;