#ifndef __COUNTERMOVE_H__
#define __COUNTERMOVE_H__

#include "game.h"
#include "myscan.h"


//��������ҳ����κ���
Coordinate judge_row(char board[ROW][COL], int row, int col);

//��������ҳ����κ���
Coordinate judge_col(char board[ROW][COL], int row, int col);

//��������ҳ����κ�\б��
Coordinate judeg_diagonal_left(char board[ROW][COL], int row, int col);

//��������ҳ����κ�/б��
Coordinate judeg_diagonal_right(char board[ROW][COL], int row, int col);

//������ɺϷ�����
Coordinate  rand_create_coor(char board[ROW][COL], int row, int col);

//�������ӵĺ���
void make_sure(char board[ROW][COL], int row, int col);

//�����Ѷ�
void get_diffiuct(int* p);

#endif