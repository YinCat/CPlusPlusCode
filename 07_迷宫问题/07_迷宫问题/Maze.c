#include "Maze.h"

//��ӡ�Թ�
void MazePrint()
{
	int i = 0;
	int j = 0;
	for(i = 0;i<N;i++)
	{
		for (j = 0; j < N; j++) 
		{
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
}

int CheckAccess(Pos next)
{
	//�ж�Խ������
	if(next._col >= 0 &&next._row>=0
		&& next._col<N && next._row<N)
	{ 
		//1���Ǳ�ʾͨ·
		if (maze[next._row][next._col] == 1) 
		{
			return 1;
		}
	}
	//return 0��ʾ������ͨ��
	return 0;
}
int MazeGetPath(Pos entry,Pos exit)
{
	Pos cur = entry;//cur��¼��ʼλ��
	
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//����ʼ����ѹջ
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if ((cur._row == exit._row) && (cur._col == exit._col))
			return 1;
		//̽����һ�ο���ȥ�ĵط�
		maze[cur._row][cur._col] = 2;//�����һ���߹���λ��
		//��
		Pos next = cur;
		next._row -= 1;
		if (CheckAccess(next)) 
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		//����
		StackPop(&path);
	}
	return 0;
}