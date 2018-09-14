#include "NumStack.h"
#include "Stack.h"

typedef struct DoubleStack {
	Stack st;
	NStack nst;
}DoubleStack;

void DoubleStackInit(DoubleStack* ds);
void DoubleStackDestory(DoubleStack* ds);

void DoubleStackPush(DoubleStack* ds, IDataType x);
void DoubleStackPop(DoubleStack* ds);

IDataType DoubleStackTop(const DoubleStack* ds);
int DoubleStackEmpty(const DoubleStack* ds);
int DoubleStackSize(const DoubleStack* ds);

int GetMinNum(const DoubleStack* ds);

void TestDoubleStack();