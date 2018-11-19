#ifndef __STACK_H__
#define __STACK_H__

//#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

#define START_SIZE 3	//默认大小
#define ADD_SIZE 2		//增长因子

typedef struct Pos
{
	int _row;
	int _col;
}Pos;

typedef Pos DataType;

typedef struct Stack
{
	DataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;



void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);

DataType StackTop(const Stack* ps);
int StackEmpty(const Stack* ps);
int StackSize(const Stack* ps);

void TestStack();

#endif // !__STACK_H__

