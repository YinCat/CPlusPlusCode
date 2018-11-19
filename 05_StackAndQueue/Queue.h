#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <limits.h>

typedef int DataType;

//对列节点结构体
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;

//对列结构体
typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _back;  // 队尾
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);


void QueuePush(Queue* pq, DataType x);
void QueuePop(Queue* pq);
DataType QueueFront(const Queue* pq);

int QueueEmpty(const Queue* pq);
int QueueSize(const Queue* pq);

void TestQueue();