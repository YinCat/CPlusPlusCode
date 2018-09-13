#include "DoubeStack.h"

void DoubleStackInit(DoubleStack* ds)
{
	assert(ds);
	StackInit(&(ds->st));
	NStackInit(&(ds->nst));
}

void DoubleStackDestory(DoubleStack* ds)
{
	assert(ds);
	StackDestory(&(ds->st));
	NStackDestory(&(ds->nst));
}

IDataType DoubleStackTop(const DoubleStack* ds)
{
	assert(ds);
	if ((ds->st)._top == 0)
	{
		printf("��ջ\n");
		return -1;
	}
	return StackTop(&ds->st);
}

void DoubleStackPush(DoubleStack* ds, IDataType x)
{
	SDataType s;
	SDataType ret;
	assert(ds);

	//����ṹ��ջΪ��
	if(NStackEmpty(&ds->nst) == 0)
	{
		s.count = 1;
		s.num = x;
		StackPush(&ds->st,x);
		NStackPush(&ds->nst, s);
	}
	else
	{
		
		StackPush(&ds->st, x);
		//�����ջ��Ԫ��С����Сֵ��¼ջ��ջ��
		if(x < NStackTop(&ds->nst).num)
		{
			s.num = x;
			s.count = 1;
			//����Ԫ�صĶ�Ӧ�ṹ����ջ
			NStackPush(&ds->nst, s);
		}
		else if (x == NStackTop(&ds->nst).num) 
		{
			//��ȵ����
			ret = NStackTop(&ds->nst);
			NStackPop(&ds->nst);
			ret.count += 1;
			NStackPush(&ds->nst, ret);
		}
	}
}
void DoubleStackPop(DoubleStack* ds)
{
	SDataType ret;
	assert(ds);
	//�Ȼ�ȡ�ṹ��ջ��ջ��Ԫ��
	ret = NStackTop(&ds->nst);

	//��������Ⱦ����ṹ�����-1���߳�ջ����
	if(ret.num == StackTop(&ds->st))
	{
		if(ret.count == 1)
		{
			NStackPop(&ds->nst);
		}
		else 
		{
			ret.count--;
			NStackPop(&ds->nst);
			NStackPush(&ds->nst, ret);
		}
	}
	//��ԭ�������ֳ�ջ
	StackPop(&ds->st);
}

int DoubleStackEmpty(const DoubleStack* ds)
{
	assert(ds);
	return StackEmpty(&ds->st);
}

int DoubleStackSize(const DoubleStack* ds)
{
	assert(ds);
	return StackSize(&ds->st);
}

//��ȡ��Сֵ
int GetMinNum(const DoubleStack* ds)
{
	assert(ds);
	return (NStackTop(&ds->nst)).num;
}

void TestDoubleStack()
{
	int ret = INT_MIN;
	DoubleStack ds;
	DoubleStackInit(&ds);
	DoubleStackPush(&ds, 1);
	DoubleStackPush(&ds, 2);
	DoubleStackPush(&ds, -1);
	DoubleStackPush(&ds, 1);
	DoubleStackPush(&ds, 0);
	DoubleStackPush(&ds, 0);
	DoubleStackPush(&ds, -1);
	DoubleStackPush(&ds, 1);

	DoubleStackPop(&ds);
	DoubleStackPop(&ds);
	DoubleStackPop(&ds);
	DoubleStackPop(&ds);

	ret = GetMinNum(&ds);
	printf("��СֵΪ��%d\n",ret);
	DoubleStackDestory(&ds);
}