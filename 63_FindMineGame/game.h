#ifndef _GAME_H__
#define _GAME_H__

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#include<time.h>
#include<stdlib.h>
#include<stdio.h>

//初始化
void InitBoard(char board[ROWS][COLS], int rows, int clos,char set);

//打印数组
void PrintBoard(char board[ROWS][COLS], int row, int col);

//设置雷的坐标
void SetMine(char board[ROWS][COLS], int row, int col, int count);

//排雷
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y);

//返回周围雷数目
int GetMineCount(char mine[ROWS][COLS], int x, int y);

//展开的方法
//void Spread(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y);
void open_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y);

//判断是否排完
int iswin(char show[ROWS][COLS], int row, int col,int mine_count);

#endif