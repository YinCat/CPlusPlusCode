#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

#define START_SIZE 3
#define ADD_SIZE 2
typedef int IDataType;

typedef struct Stack
{
	IDataType* _a;
	int _top;		// Õ»¶¥
	int _capacity;  // ÈÝÁ¿ 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, IDataType x);
void StackPop(Stack* ps);

IDataType StackTop(const Stack* ps);
int StackEmpty(const Stack* ps);
int StackSize(const Stack* ps);

#endif // !__STACK_H__

