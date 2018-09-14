#ifndef __NUMSTACK_H__
#define __NUMSTACK_H__


#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

#define START_SIZE 3
#define ADD_SIZE 2

typedef struct Statistics{
	int num;//数字
	int count;//出现次数
}Statistics;

typedef Statistics SDataType;

typedef struct NStack
{
	SDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}NStack;

void NStackInit(NStack* ps);
void NStackDestory(NStack* ps);

void NStackPush(NStack* ps, SDataType x);
void NStackPop(NStack* ps);

SDataType NStackTop(const NStack* ps);
int NStackEmpty(const NStack* ps);
int NStackSize(const NStack* ps);

#endif // !__NUMSTACK_H__

