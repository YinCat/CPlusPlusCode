#include<stdio.h>
#include<stdlib.h>
int main()
{

	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		j = 0;
4		while (j < 10)
		{
			j++;
			printf("%d_%d\n", i, j);
		}
	}
	system("pause");
	return 0;
}