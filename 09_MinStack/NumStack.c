#include "NumStack.h"

//��ʼ��
void NStackInit(NStack* ps)
{
	ps->_a = (SDataType*)malloc(sizeof(SDataType)*START_SIZE);
	ps->_capacity = START_SIZE;
	ps->_top = 0;
}

//���ٺ���
void NStackDestory(NStack* ps)
{
	assert(ps);
	if (ps->_a == NULL)
		return;
	free(ps->_a);
	ps->_a = NULL;
}

//Push����
void NStackPush(NStack* ps, SDataType x)
{
	assert(ps);
	//��Ҫ����
	if (ps->_capacity == ps->_top)
	{
		ps->_a = realloc(ps->_a, sizeof(SDataType)*(ps->_capacity + ADD_SIZE));
		ps->_capacity += ADD_SIZE;
		assert(ps->_a);
	}
	ps->_a[ps->_top++] = x;
}

//Pop����
void NStackPop(NStack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return;
	ps->_top--;
}

SDataType NStackTop(const NStack* ps)
{
	//�Ƿ����
	Statistics s;
	s.count = -1;
	s.num = -1;
	assert(ps);
	assert(ps->_top != 0);
	if (ps->_top == 0)
		return s;
	return ps->_a[ps->_top - 1];
}

//�жϿ�ջ��0��ʾ�ա�1��ʾ�ǿ�
int NStackEmpty(const NStack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

//��ȡջ��Ԫ�ظ���
int NStackSize(const NStack* ps)
{
	assert(ps);
	return ps->_top;
}