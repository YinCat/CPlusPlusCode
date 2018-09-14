#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_back = NULL;
}

//销毁
void QueueDestory(Queue* pq)
{
	QueueNode *cur = NULL;
	QueueNode *del = NULL;
	assert(pq);
	if (pq->_front == NULL)
		return;
	del = pq->_front;
	cur = pq->_front->_next;
	while (cur)
	{
		free(del);
		del = cur;
		cur = cur->_next;
	}
}

//获得新节点
static QueueNode* BuyQueueNode(DataType x)
{
	QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

//Push函数，等同于链表的尾插
void QueuePush(Queue* pq, DataType x)
{
	QueueNode *newNode = NULL;
	assert(pq);
	newNode = BuyQueueNode(x);
	if (pq->_front == NULL) 
	{
		pq->_front = newNode;
		pq->_back = newNode;
	}
	else
	{
		pq->_back->_next = newNode;
		pq->_back = pq->_back->_next;
	}
}

//Pop函数
void QueuePop(Queue* pq)
{
	QueueNode *cur = NULL;
	assert(pq);
	if (pq->_front == NULL)
	{
		//注意在头指针都指向NULL的时候将尾指针也置为NULL
		pq->_back = NULL;
		return;
	}
	cur = pq->_front->_next;
	free(pq->_front);
	pq->_front = cur;
}

//return INT_MAX表示队列为空
DataType QueueFront(const Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
		return INT_MAX;
	return pq->_front->_data;
}

//空返回0、非空返回1
int QueueEmpty(const Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 0 : 1;
}

//获取对列中元素个数
int QueueSize(const Queue* pq)
{
	int count = 0;
	QueueNode *cur = pq->_front;
	assert(pq);
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

//测试函数
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 11);
	QueuePush(&q, 22);
	QueuePush(&q, 33);
	QueuePush(&q, 44);

	QueuePop(&q);
	 
	QueueDestory(&q);
}