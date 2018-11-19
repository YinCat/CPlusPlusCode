#ifndef __GAME_H__
#define __GAME_H__

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

//�к���
#define ROW 3
#define COL 3

//��ʼ�ͽ���
enum CHOSE{
	EXIT, //�˳�
	START, //��ʼ��Ϸ
};

//��Ϸ�Ѷ�
enum GAME_DIFFICULTY{
	EASY,  //��
	MEDIUM, //�е�
	DIFFICULTY, //����
};

//��ʼ������
void init_board(char board[ROW][COL], int row, int col);

//��ӡ����
void print_board(char board[ROW][COL], int row, int col);

//������Ӻ���
void player_move(char board[ROW][COL], int row, int col);

//�������Ӻ���
void computer_move(char board[ROW][COL], int row, int col);

//����״̬�ж�
char iswin(char board[ROW][COL], int row, int col);


#endif