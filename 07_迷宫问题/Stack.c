#include "Stack.h"

//��ʼ��
void StackInit(Stack* ps)
{
	ps->_a = (DataType*)malloc(sizeof(DataType)*START_SIZE);
	ps->_capacity = START_SIZE;
	ps->_top = 0;
}

//���ٺ���
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a == NULL)
		return;
	free(ps->_a);
	ps->_a = NULL;
}

//Push����
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	//��Ҫ����
	if (ps->_capacity == ps->_top) 
	{
		ps->_a = realloc(ps->_a, sizeof(DataType)*(ps->_capacity + ADD_SIZE));
		ps->_capacity += ADD_SIZE;
		if (ps->_a == NULL)
		{
			perror("���ݳ���\n");
			return;
		}
	}
	ps->_a[ps->_top++] = x;
}

//Pop����
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return;
	ps->_top--;
}

//����INT_MAX�ͱ�ʾû��Ԫ����
DataType StackTop(const Stack* ps)
{
	Pos s;
	s._col = -1;
	s._row = -1;
	assert(ps);
	assert(ps);
	if (ps->_top == 0)
		return s;
	return ps->_a[ps->_top-1];
}

//�жϿ�ջ��0��ʾ�ա�1��ʾ�ǿ�
int StackEmpty(const Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

//��ȡջ��Ԫ�ظ���
int StackSize(const Stack* ps)
{
	assert(ps);
	return ps->_top;
}