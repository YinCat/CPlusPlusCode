#include"queue.h"
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = NULL;
	q->_tail= NULL;

}
QueueNode *BuyNode(DataType x)
{
	QueueNode  *temp;
	temp = (QueueNode*)malloc(sizeof(QueueNode));
	 if(!temp)
    {
        printf("temp malloc error!\n");
        return NULL;
    }
	temp->_data = x;
	temp->_next = NULL;

	return temp;

}
void QueuePush(Queue* q, DataType x)
{
	
	   QueueNode  *temp = BuyNode(x);
	   if(q->_head == NULL)
	   {
		   q->_head = temp;
		   q->_tail = temp;
		   return;
	   }
	   else
	   {
	   q->_tail->_next = temp ;
        q->_tail = temp;   
	   }

    return; 
}
void QueuePop(Queue* q)
{
	QueueNode* cur = q->_head;
	if(q->_head== NULL)
		return;

	q->_head = q->_head->_next;
	free(cur);

}

int QueueEmpty(Queue* q)
{
	if(q->_head == NULL )
	{
			return 0;
	}
	else
		return 1;
}
void DestroyQueue(Queue *q)
{
	QueueNode *cur = NULL;
	while( q->_head != NULL)
	{
		cur = q->_head;
		q->_head = q->_head->_next;
		free(cur);	
	}
}

void PrintQueue( Queue *q)
{
	while(q->_head != NULL)
	{
		printf("%d ",q->_head->_data);
		q->_head = q->_head->_next;
	}
}

DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->_data;
}

//Ïú»Ù
void QueueDestory(Queue* pq)
{
	QueueNode *cur = NULL;
	QueueNode *del = NULL;
	assert(pq);
	if (pq->_head == NULL)
		return;
	del = pq->_head;
	cur = pq->_head->_next;
	while (cur)
	{
		free(del);
		del = cur;
		cur = cur->_next;
	}
}