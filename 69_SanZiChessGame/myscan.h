#ifndef __MYSCAN_H__
#define __MYSCAN_H__

#include "game.h"

//����ṹ��
typedef struct Coordinate{
	int x;
	int y;
}Coordinate;

//�����Ŀͳ�ƽṹ��
typedef struct MyClassCount{
	int x_num; //x�ַ�
	int o_num; //o�ַ�
	int space_num; //�ո��ַ�
}MyClassCount;

//ɨ��ÿһ��
MyClassCount* my_scanf_row(char board[ROW][COL], int row, int col);

//ɨ��ÿһ��
MyClassCount* my_scanf_col(char board[ROW][COL], int row, int col);

//ɨ��б�Խ�(\)
MyClassCount my_scanf_diagonal_left(char board[ROW][COL], int row, int col);

//ɨ��б�Խ�(/)
MyClassCount my_scanf_diagonal_right(char board[ROW][COL], int row, int col);

//ɨ����Խ�Ԫ�صĿո�(�ڵз���Ӯ������� \)
Coordinate scanf__left_find_space(char board[ROW][COL], int row, int col);

//ɨ����Խ�Ԫ�صĿո�(�ڵз���Ӯ������� )
Coordinate scanf__right_find_space(char board[ROW][COL], int row, int col);

#endif