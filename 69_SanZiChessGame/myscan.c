#include "myscan.h"
#include "game.h"
/*
 * ������������ɨ����
 */

//��ȡÿһ�е�ɨ����������洢��������
MyClassCount* my_scanf_row(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount* my_count_row = (MyClassCount*)malloc(sizeof(MyClassCount)*row);
	//����ɨ��
	for (i = 0; i < row; i++){
		//ͳ��ÿһ�е��������
		int ch_X_num = 0;
		int ch_O_num = 0;
		int ch_space_num = 0;

		for (j = 0; j < col; j++){
			if (board[i][j] == 'X'){
				ch_X_num++;
			}
			else if (board[i][j] == 'O'){
				ch_O_num++;
			}
			else{
				ch_space_num++;
			}
		}
		my_count_row[i].x_num = ch_X_num;
		my_count_row[i].o_num = ch_O_num;
		my_count_row[i].space_num = ch_space_num;
	}
	
	return my_count_row;
}

//��ȡÿһ�е�ɨ����������洢��������
MyClassCount* my_scanf_col(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount* my_count_col = (MyClassCount*)malloc(sizeof(MyClassCount)*row);
	//����ɨ��
	for (i = 0; i < col; i++){

		//ͳ��ÿһ�е����ӷֲ����
		int ch_X_num = 0;
		int ch_O_num = 0;
		int ch_space_num = 0;

		for (j = 0; j < row; j++){
			if (board[j][i] == 'X'){
				ch_X_num++;
			}
			else if (board[j][i] == 'O'){
				ch_O_num++;
			}
			else{
				ch_space_num++;
			}
		}
		my_count_col[i].x_num = ch_X_num;
		my_count_col[i].o_num = ch_O_num;
		my_count_col[i].space_num = ch_space_num;
	}

	return my_count_col;
}
//"\"�ֱ�ɨ��X��O���ո����
MyClassCount my_scanf_diagonal_left(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount my_count_diagonal_left;
	int ch_X_num = 0;
	int ch_O_num = 0;
	int ch_space_num = 0;

	//����б�����
	//������̲���N * N�ľͲ�����
	if (row == col){
		for (i = 0; i < row; i++){
			

			if (board[i][i] == 'X'){
				ch_X_num++;
			}
			else if (board[i][i] == 'O'){
				ch_O_num++;
			}
			else{
				ch_space_num++;
			}
		}
		my_count_diagonal_left.o_num = ch_O_num;
		my_count_diagonal_left.x_num = ch_X_num;
		my_count_diagonal_left.space_num = ch_space_num;
	}
	//printf("\\ count----> O:%d X:%d space:%d\n", ch_O_num, ch_X_num, ch_space_num);
	return my_count_diagonal_left;
}
//"/" �ֱ�ɨ��X��O���ո����
MyClassCount my_scanf_diagonal_right(char board[ROW][COL], int row, int col){
		int i = 0;
		int j = 0;

		MyClassCount my_count_diagonal_right;
		int ch_X_num = 0;
		int ch_O_num = 0;
		int ch_space_num = 0;

		//������̲���N*N�͵��͵ľͲ�����
		if (row == col){
			//"/"�Ķ��뷽ʽ
			for (i = row - 1, j = 0; i >= 0; i--, j++){
				
				if (board[i][j] == 'X'){
					ch_X_num++;
				}
				else if (board[i][j] == 'O'){
					ch_O_num++;
				}
				else{
					ch_space_num++;
				}
			}
			my_count_diagonal_right.o_num = ch_O_num;
			my_count_diagonal_right.x_num = ch_X_num;
			my_count_diagonal_right.space_num = ch_space_num;
		}
		//printf("/count----> O:%d X:%d space:%d\n", ch_O_num, ch_X_num,ch_space_num);
		return my_count_diagonal_right;
}
//����б�Խ���"\"�ϵ�Ψһ�ո�����
Coordinate scanf__left_find_space(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	
	//����Ҫ���ص�����
	Coordinate my_coor; 

	if (row == col){
		for (i = 0; i < row; i++){
			if (' ' == board[i][i]){
				my_coor.x = i;
				my_coor.y = i;
			}
		}
	}
	//printf("б�Խ���\\�ϵ�Ψһ�ո�����:%d,%d\n", i, i);
	return my_coor;
}
//����б�Խ���"/"�ϵ�Ψһ�ո�����
Coordinate scanf__right_find_space(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	Coordinate my_coor;

	if (row == col){
		//"/"�Ķ��뷽ʽ
		for (i = row - 1, j = 0; i >= 0; i--, j++){
			if (board[i][j] == ' '){
				my_coor.x = i;
				my_coor.y = j;
			}
		}
	}
	return my_coor;
}