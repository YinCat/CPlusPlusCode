#include "Maze.h"

//打印迷宫
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
int MazeGetPath(Pos entry,Pos exit)
{
	Pos cur = entry;//cur记录起始位置
	
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//将起始坐标压栈
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if ((cur._row == exit._row) && (cur._col == exit._col))
			return 1;
		//探测下一次可以去的地方
		maze[cur._row][cur._col] = 2;//标记上一次走过的位置
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

int MazeCheckIsAccess(Pos pos)
{
	return 0;
}



void MazeGetShortPath(Pos entry, Stack* path)
{

}