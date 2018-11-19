#ifndef __COUNTERMOVE_H__
#define __COUNTERMOVE_H__

#include "game.h"
#include "myscan.h"


//不允许玩家成立任何行
Coordinate judge_row(char board[ROW][COL], int row, int col);

//不允许玩家成立任何列
Coordinate judge_col(char board[ROW][COL], int row, int col);

//不允许玩家成立任何\斜行
Coordinate judeg_diagonal_left(char board[ROW][COL], int row, int col);

//不允许玩家成立任何/斜行
Coordinate judeg_diagonal_right(char board[ROW][COL], int row, int col);

//随机生成合法坐标
Coordinate  rand_create_coor(char board[ROW][COL], int row, int col);

//电脑落子的函数
void make_sure(char board[ROW][COL], int row, int col);

//设置难度
void get_diffiuct(int* p);

#endif