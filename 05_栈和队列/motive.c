#include "motive.h"

//初始化
void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	QueueInit(&(stq->q1));
	QueueInit(&(stq->q2));
}

//销毁
void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	QueueDestory(&(stq->q1));
	QueueDestory(&(stq->q2));
}

//分配空队列与非空队列
static EmptyCmp(Queue** em, Queue** noem, StackByTwoQueue** pstq)
{
	QueueEmpty(&(*pstq)->q1) == 1 ? ((*noem = &(*pstq)->q1), *em = &((*pstq)->q2)) : ((*noem = &(*pstq)->q2), *em = &((*pstq)->q1));
}
//获取顶部数据
DataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	Queue *empty;
	Queue *noempty;
	DataType ret;
	//通过三元运算符确定空队列与非空队列
	EmptyCmp(&empty, &noempty, &stq);

	//将非空队列的元素转移到非空队列，保留一个
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	//获取保留结果数据
	ret = QueueFront(noempty);
	//将剩下的一个数据也转移
	QueuePop(noempty);
	QueuePush(empty, ret);
	return ret;
}

//判断模拟栈是否为空，为空返回0，不为空返回1
int StackByTwoQueueEmpty(const StackByTwoQueue* stq)
{
	//只要有一个队列不为空那么模拟栈就不为空
	return QueueEmpty(&(stq->q1)) | QueueEmpty(&(stq->q2));
}

//模拟栈中存入的元素个数
int StackByTwoQueueSize(const StackByTwoQueue* stq)
{
	return QueueSize(&(stq->q1)) + QueueSize(&(stq->q2));
}

//Push数据
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{
	Queue *empty;
	Queue *noempty;
	EmptyCmp(&empty, &noempty, &stq);

	//永远向不为空的队列插入数据
	QueuePush(noempty,x);
}

//Pop数据
void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	Queue *empty;
	Queue *noempty;
	EmptyCmp(&empty, &noempty, &stq);

	//与StackByTwoQueueTop()一样的过程，只是最后余下的元素直接出队列
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	printf("Pop:%d\n", noempty->_front->_data);
	QueuePop(noempty);
}

//测试函数
void TestStackByTwoQueue()
{
	StackByTwoQueue sq;
	StackByTwoQueueInit(&sq);
	StackByTwoQueuePush(&sq, 11);
	StackByTwoQueuePush(&sq, 22);
	StackByTwoQueuePush(&sq, 33);
	StackByTwoQueuePush(&sq, 44);
	StackByTwoQueuePop(&sq);
	StackByTwoQueuePop(&sq);
	StackByTwoQueuePush(&sq, 55);
	StackByTwoQueuePop(&sq);
	StackByTwoQueuePop(&sq);
	StackByTwoQueuePop(&sq);
	StackByTwoQueueDestory(&sq);
}
