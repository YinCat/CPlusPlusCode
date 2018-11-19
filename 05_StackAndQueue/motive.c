#include "motive.h"

//��ʼ��
void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	QueueInit(&(stq->q1));
	QueueInit(&(stq->q2));
}

//����
void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	QueueDestory(&(stq->q1));
	QueueDestory(&(stq->q2));
}

//����ն�����ǿն���
static EmptyCmp(Queue** em, Queue** noem, StackByTwoQueue** pstq)
{
	QueueEmpty(&(*pstq)->q1) == 1 ? ((*noem = &(*pstq)->q1), *em = &((*pstq)->q2)) : ((*noem = &(*pstq)->q2), *em = &((*pstq)->q1));
}
//��ȡ��������
DataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	Queue *empty;
	Queue *noempty;
	DataType ret;
	//ͨ����Ԫ�����ȷ���ն�����ǿն���
	EmptyCmp(&empty, &noempty, &stq);

	//���ǿն��е�Ԫ��ת�Ƶ��ǿն��У�����һ��
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	//��ȡ�����������
	ret = QueueFront(noempty);
	//��ʣ�µ�һ������Ҳת��
	QueuePop(noempty);
	QueuePush(empty, ret);
	return ret;
}

//�ж�ģ��ջ�Ƿ�Ϊ�գ�Ϊ�շ���0����Ϊ�շ���1
int StackByTwoQueueEmpty(const StackByTwoQueue* stq)
{
	//ֻҪ��һ�����в�Ϊ����ôģ��ջ�Ͳ�Ϊ��
	return QueueEmpty(&(stq->q1)) | QueueEmpty(&(stq->q2));
}

//ģ��ջ�д����Ԫ�ظ���
int StackByTwoQueueSize(const StackByTwoQueue* stq)
{
	return QueueSize(&(stq->q1)) + QueueSize(&(stq->q2));
}

//Push����
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{
	Queue *empty;
	Queue *noempty;
	EmptyCmp(&empty, &noempty, &stq);

	//��Զ��Ϊ�յĶ��в�������
	QueuePush(noempty,x);
}

//Pop����
void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	Queue *empty;
	Queue *noempty;
	EmptyCmp(&empty, &noempty, &stq);

	//��StackByTwoQueueTop()һ���Ĺ��̣�ֻ��������µ�Ԫ��ֱ�ӳ�����
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	printf("Pop:%d\n", noempty->_front->_data);
	QueuePop(noempty);
}

//���Ժ���
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
