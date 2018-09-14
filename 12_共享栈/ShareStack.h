#ifndef __SHARESTACK_H__
#define __SHARESTACK_H__

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define N 100
typedef int SSDataType;
typedef struct ShareStack
{
	SSDataType _a[N];
	int _top1;
	int _top2;
}ShareStack;

void ShareStackInit(ShareStack* pss);
void ShareStackPush(ShareStack* pss, SSDataType x, int which);
void ShareStackPop(ShareStack* pss, int which);
SSDataType ShareStackTop(ShareStack* pss, int which);

void TestShareStack();

#endif // !__SHARESTACK_H__