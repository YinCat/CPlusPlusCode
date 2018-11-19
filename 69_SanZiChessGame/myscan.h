#ifndef __MYSCAN_H__
#define __MYSCAN_H__

#include "game.h"

//坐标结构体
typedef struct Coordinate{
	int x;
	int y;
}Coordinate;

//类别数目统计结构体
typedef struct MyClassCount{
	int x_num; //x字符
	int o_num; //o字符
	int space_num; //空格字符
}MyClassCount;

//扫描每一行
MyClassCount* my_scanf_row(char board[ROW][COL], int row, int col);

//扫描每一列
MyClassCount* my_scanf_col(char board[ROW][COL], int row, int col);

//扫描斜对角(\)
MyClassCount my_scanf_diagonal_left(char board[ROW][COL], int row, int col);

//扫描斜对角(/)
MyClassCount my_scanf_diagonal_right(char board[ROW][COL], int row, int col);

//扫描出对角元素的空格(在敌方快赢的情况下 \)
Coordinate scanf__left_find_space(char board[ROW][COL], int row, int col);

//扫描出对角元素的空格(在敌方快赢的情况下 )
Coordinate scanf__right_find_space(char board[ROW][COL], int row, int col);

#endif