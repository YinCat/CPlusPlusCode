#pragma once
#include "Queue.h"


//��������ʵ��һ��ջ
typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;


void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);
DataType StackByTwoQueueTop(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(const StackByTwoQueue* stq);
int StackByTwoQueueSize(const StackByTwoQueue* stq);

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x);
void StackByTwoQueuePop(StackByTwoQueue* stq);

void TestStackByTwoQueue();
