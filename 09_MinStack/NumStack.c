#include "NumStack.h"

//初始化
void NStackInit(NStack* ps)
{
	ps->_a = (SDataType*)malloc(sizeof(SDataType)*START_SIZE);
	ps->_capacity = START_SIZE;
	ps->_top = 0;
}

//销毁函数
void NStackDestory(NStack* ps)
{
	assert(ps);
	if (ps->_a == NULL)
		return;
	free(ps->_a);
	ps->_a = NULL;
}

//Push函数
void NStackPush(NStack* ps, SDataType x)
{
	assert(ps);
	//需要扩容
	if (ps->_capacity == ps->_top)
	{
		ps->_a = realloc(ps->_a, sizeof(SDataType)*(ps->_capacity + ADD_SIZE));
		ps->_capacity += ADD_SIZE;
		assert(ps->_a);
	}
	ps->_a[ps->_top++] = x;
}

//Pop函数
void NStackPop(NStack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return;
	ps->_top--;
}

SDataType NStackTop(const NStack* ps)
{
	//非法结果
	Statistics s;
	s.count = -1;
	s.num = -1;
	assert(ps);
	assert(ps->_top != 0);
	if (ps->_top == 0)
		return s;
	return ps->_a[ps->_top - 1];
}

//判断空栈，0表示空、1表示非空
int NStackEmpty(const NStack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

//获取栈中元素个数
int NStackSize(const NStack* ps)
{
	assert(ps);
	return ps->_top;
}