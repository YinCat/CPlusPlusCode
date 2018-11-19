#include "Maze.h"

int main()
{
	int ret = 0;
	Pos entry;
	Pos exit;
	entry._row = 5;
	entry._col = 2;

	exit._row = 4;
	exit._col = 5;
	ret = MazeGetPath(entry,exit);
	if (ret == 1) 
	{
		printf("找到出口\n");
	}
	else {
		printf("未找到出口\n");
	}
	return 0;
}