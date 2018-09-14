#include "Maze.h"

void MazePrint()
{
	size_t i = 0;
	size_t j = 0;
	for(i = 0;i<N;i++)
	{
		for (j = 0; j < N; j++) 
		{
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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

int MazeCheckIsAccess(Pos cur, Pos next)
{
	//�ж�Խ������
	if ((next._col >= 0 && next._row >= 0 && next._col<N && next._row<N)
		&&(maze[next._row][next._col] == 1 || maze[next._row][next._col]>maze[cur._row][cur._col]+1))
	{
			return 1;
	}
	//return 0��ʾ������ͨ��
	return 0;
}

int pathsize = 0;

int MazeGetPath(Pos entry,Pos exit)
{
	Pos cur = entry;//cur��¼��ʼλ��
	
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//����ʼ����ѹջ

	maze[entry._row][entry._col] = 2;
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		maze[cur._row][cur._col] = 2;//�����һ���߹���λ��
		//if ((cur._row == exit._row) && (cur._col == exit._col))
		if (cur._col == 5) 
		{
			//���ֻ��һ��ͨ·�򷵻�
			//return 1;
			//StackDestory(&path);
			if (pathsize == 0||
				StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}
		}
		//̽����һ�ο���ȥ�ĵط�
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


int MazeGetShortPath(Pos entry, Pos exit)
{
	Pos cur = entry;//cur��¼��ʼλ��

	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//����ʼ����ѹջ


	maze[entry._row][entry._col] = 2;
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if (cur._col == 5)
		{
			//���ֻ��һ��ͨ·�򷵻�
			//return 1;
			//StackDestory(&path);
			if (pathsize == 0 ||
				StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}
		}
		//̽����һ�ο���ȥ�ĵط�
		//��
		Pos next = cur;
		next._row -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//����
		StackPop(&path);
	}
	return 0;
}



void TestMaze()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;

	Pos exit;
	exit._row = 4;
	exit._col = 5;
	MazePrint();
	//printf("�Ƿ��г��ڣ�%d\n",MazeGetPath(entry,exit));
	MazeGetShortPath(entry, exit); 
	printf("���·����%d\n",pathsize);
	MazePrint();
}