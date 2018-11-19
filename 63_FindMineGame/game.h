#ifndef _GAME_H__
#define _GAME_H__

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#include<time.h>
#include<stdlib.h>
#include<stdio.h>

//��ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int clos,char set);

//��ӡ����
void PrintBoard(char board[ROWS][COLS], int row, int col);

//�����׵�����
void SetMine(char board[ROWS][COLS], int row, int col, int count);

//����
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y);

//������Χ����Ŀ
int GetMineCount(char mine[ROWS][COLS], int x, int y);

//չ���ķ���
//void Spread(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y);
void open_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y);

//�ж��Ƿ�����
int iswin(char show[ROWS][COLS], int row, int col,int mine_count);

#endif