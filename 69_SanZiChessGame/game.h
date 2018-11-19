#ifndef __GAME_H__
#define __GAME_H__

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

//行和列
#define ROW 3
#define COL 3

//开始和结束
enum CHOSE{
	EXIT, //退出
	START, //开始游戏
};

//游戏难度
enum GAME_DIFFICULTY{
	EASY,  //简单
	MEDIUM, //中等
	DIFFICULTY, //困难
};

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col);

//打印棋盘
void print_board(char board[ROW][COL], int row, int col);

//玩家落子函数
void player_move(char board[ROW][COL], int row, int col);

//电脑落子函数
void computer_move(char board[ROW][COL], int row, int col);

//棋盘状态判断
char iswin(char board[ROW][COL], int row, int col);


#endif