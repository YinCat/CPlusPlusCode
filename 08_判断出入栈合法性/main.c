#include "Stack.h"

int IsLegal(int *in, int *out, int insize, int outsize)
{
	int i = 0;
	int j = 0;
	Stack st;
	//���ָ����Ч���߳��Ȳ�һ�����޷��жϵ�
	assert(in && out && insize == outsize);
	StackInit(&st);
	//��in�����е�Ԫ��ѹ��ջ������Ƚϣ����ջ��Ԫ����out�����е�һ�¾͵�����Ԫ��
	while(i<insize)
	{
		StackPush(&st, in[i++]);
		if (StackTop(&st) == out[j]) {
			StackPop(&st);
			j++; //ע��out�����бȽϹ���Ԫ��Ҫ�����������±�Ҫ+1
		}
	}

	//��ʱջ��ʣ�µ�Ԫ��Ҫ��out������ʣ�µ�Ԫ������Ƚϣ�������һ���ľͲ�ƥ��
	while (StackEmpty(&st) != 0)
	{
		if(StackTop(&st) != out[j++])
		{
			return 0;
		}
		StackPop(&st);
	}
	//��ʱΪ��ջ����˵��ƥ��
	return 1;
}

int main(void)
{
	int in[5] = {1, 2, 3, 4, 5};
	int out[5] = {2, 3, 4, 5, 1 };
	int ret = IsLegal(in, out, 5, 5);
	if (ret == 1)
		printf("ƥ��\n");
	else
		printf("��ƥ��\n");

	system("pause");
	return 0;
}