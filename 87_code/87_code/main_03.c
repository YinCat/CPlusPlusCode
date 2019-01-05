#if 0
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int n, m, k = 0;
	int count;
	scanf("%d %d", &n, &m);
	int a[10][10] = { 0 };
	int i = 0, j = 0;
	count = n*m;
	//printf("这是一个%d行%d列的矩阵", n, m);*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	//int t = 0;//用于记录圈数


	//while (count) {
	//	while (i<n - t && count)
	//	{
	//		if (i == 0 && j == 0)
	//		{
	//			printf("%d", a[0][0]);
	//			i++;
	//		}
	//		else
	//		{
	//			printf("%d", a[i++][j]);
	//		}
	//		count--;
	//	}
	//	i--;
	//	j++;

	//	while (i >= t && count)
	//	{
	//		printf("%d", a[i--][j]);
	//		count--;
	//	}
	//	i--;
	//	j++;

	//	while (j > t && count)
	//	{
	//		printf("%d", a[i][j--]);
	//		count--;
	//	}
	//	j++;
	//	i++;
	//	t++;

	//}

	return 0;
}
#endif