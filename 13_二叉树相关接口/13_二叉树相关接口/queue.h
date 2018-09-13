#ifndef __QUEUE__
#define __QUEUE__
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

struct BinaryTreeNode;

typedef struct BinaryTreeNode* DataType;

typedef struct QueueNode 
{ 
    DataType  _data; 
	struct QueueNode* _next; 
}QueueNode; 

typedef struct Queue 
{ 
	QueueNode* _head; 
	QueueNode* _tail; 
}Queue; 

void QueueInit(Queue* q); 
void QueuePush(Queue* q, DataType x); 
void QueuePop(Queue* q); 
void DestroyQueue(Queue *q);
DataType QueueFront(Queue* q); 
DataType QueueBack(Queue* q); 
int QueueSize(Queue* q); 
void PrintQueue( Queue *q);
void QueueDestory(Queue* pq);
int QueueEmpty(Queue* q);
#endif