#include "ShareStack.h"

void ShareStackInit(ShareStack* pss)
{
	assert(pss);
	pss->_top1 = 0;
	pss->_top2 = 1;
}

//which 1/2
void ShareStackPush(ShareStack* pss, SSDataType x, int which)
{
	assert(pss && (which == 1 || which == 2));
	if (pss->_top1 < N && pss->_top2 < N)
	{
		if (which == 1)
		{
			pss->_a[pss->_top1] = x;
			pss->_top1 += 2;
		}
		else
		{
			pss->_a[pss->_top2] = x;
			pss->_top2 += 2;
		}
	}
	else
		printf("¿Õ¼ä²»×ã\n");
}
void ShareStackPop(ShareStack* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1 && (pss->_top1 - 2 >= 0))
		pss->_top1 -= 2;
	else if (which == 2 && (pss->_top2 - 2 >= 0))
		pss->_top2 -= 2;
}
int error_flag = 0;
SSDataType ShareStackTop(ShareStack* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1 && pss->_top1-2 >= 0)
		return pss->_a[pss->_top1 -2];
	else if (which == 2 && pss->_top2- 2 >= 0)
		return pss->_a[pss->_top2 -2];
	error_flag = -1;
	return error_flag;
}

void TestShareStack()
{
	ShareStack ss;
	ShareStackInit(&ss);
	ShareStackPush(&ss,11, 1);
	ShareStackPush(&ss, 22, 1);
	ShareStackPush(&ss, 33, 2);
	ShareStackPush(&ss, 44, 1);

	printf("%d\n", ShareStackTop(&ss, 1));
	ShareStackPop(&ss, 1);

	printf("%d\n", ShareStackTop(&ss, 1));
	ShareStackPop(&ss, 1);

	printf("%d\n",ShareStackTop(&ss, 2));
	ShareStackPop(&ss, 2);

	printf("%d\n", ShareStackTop(&ss, 2));
	ShareStackPop(&ss, 2);
}