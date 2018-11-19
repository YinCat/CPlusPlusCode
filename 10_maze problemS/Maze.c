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
	//判断越界的情况
	if(next._col >= 0 &&next._row>=0
		&& next._col<N && next._row<N)
	{ 
		//1才是表示通路
		if (maze[next._row][next._col] == 1) 
		{
			return 1;
		}
	}
	//return 0表示不可以通过
	return 0;
}

int MazeCheckIsAccess(Pos cur, Pos next)
{
	//判断越界的情况
	if ((next._col >= 0 && next._row >= 0 && next._col<N && next._row<N)
		&&(maze[next._row][next._col] == 1 || maze[next._row][next._col]>maze[cur._row][cur._col]+1))
	{
			return 1;
	}
	//return 0表示不可以通过
	return 0;
}

int pathsize = 0;

int MazeGetPath(Pos entry,Pos exit)
{
	Pos cur = entry;//cur记录起始位置
	
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//将起始坐标压栈

	maze[entry._row][entry._col] = 2;
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		maze[cur._row][cur._col] = 2;//标记上一次走过的位置
		//if ((cur._row == exit._row) && (cur._col == exit._col))
		if (cur._col == 5) 
		{
			//如果只找一条通路则返回
			//return 1;
			//StackDestory(&path);
			if (pathsize == 0||
				StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}
		}
		//探测下一次可以去的地方
		//上
		Pos next = cur;
		next._row -= 1;
		if (CheckAccess(next)) 
		{
			StackPush(&path, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		//回溯
		StackPop(&path);
	}
	return 0;
}


int MazeGetShortPath(Pos entry, Pos exit)
{
	Pos cur = entry;//cur记录起始位置

	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//将起始坐标压栈


	maze[entry._row][entry._col] = 2;
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if (cur._col == 5)
		{
			//如果只找一条通路则返回
			//return 1;
			//StackDestory(&path);
			if (pathsize == 0 ||
				StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}
		}
		//探测下一次可以去的地方
		//上
		Pos next = cur;
		next._row -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//回溯
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
	//printf("是否有出口？%d\n",MazeGetPath(entry,exit));
	MazeGetShortPath(entry, exit); 
	printf("最短路径：%d\n",pathsize);
	MazePrint();
}