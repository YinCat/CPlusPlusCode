#include "Stack.h"

int IsLegal(int *in, int *out, int insize, int outsize)
{
	int i = 0;
	int j = 0;
	Stack st;
	//如果指针无效或者长度不一样是无法判断的
	assert(in && out && insize == outsize);
	StackInit(&st);
	//将in数组中的元素压入栈中逐个比较，如果栈顶元素与out数组中的一致就弹出此元素
	while(i<insize)
	{
		StackPush(&st, in[i++]);
		if (StackTop(&st) == out[j]) {
			StackPop(&st);
			j++; //注意out数组中比较过的元素要跳过，所以下标要+1
		}
	}

	//此时栈中剩下的元素要与out数组中剩下的元素逐个比较，遇到不一样的就不匹配
	while (StackEmpty(&st) != 0)
	{
		if(StackTop(&st) != out[j++])
		{
			return 0;
		}
		StackPop(&st);
	}
	//此时为空栈，则说明匹配
	return 1;
}

int main(void)
{
	int in[5] = {1, 2, 3, 4, 5};
	int out[5] = {2, 3, 4, 5, 1 };
	int ret = IsLegal(in, out, 5, 5);
	if (ret == 1)
		printf("匹配\n");
	else
		printf("不匹配\n");

	system("pause");
	return 0;
}