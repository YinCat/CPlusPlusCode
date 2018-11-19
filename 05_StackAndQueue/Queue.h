#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <limits.h>

typedef int DataType;

//���нڵ�ṹ��
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;

//���нṹ��
typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _back;  // ��β
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);


void QueuePush(Queue* pq, DataType x);
void QueuePop(Queue* pq);
DataType QueueFront(const Queue* pq);

int QueueEmpty(const Queue* pq);
int QueueSize(const Queue* pq);

void TestQueue();