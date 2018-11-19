#include "myscan.h"
#include "game.h"
/*
 * 数组各个方向的扫描器
 */

//获取每一行的扫描结果，结果存储在数组中
MyClassCount* my_scanf_row(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount* my_count_row = (MyClassCount*)malloc(sizeof(MyClassCount)*row);
	//逐行扫描
	for (i = 0; i < row; i++){
		//统计每一行的落子情况
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

//获取每一列的扫描结果，结果存储在数组中
MyClassCount* my_scanf_col(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount* my_count_col = (MyClassCount*)malloc(sizeof(MyClassCount)*row);
	//逐行扫描
	for (i = 0; i < col; i++){

		//统计每一行的棋子分布情况
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
//"\"分别扫描X、O、空格个数
MyClassCount my_scanf_diagonal_left(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount my_count_diagonal_left;
	int ch_X_num = 0;
	int ch_O_num = 0;
	int ch_space_num = 0;

	//出现斜着相等
	//如果棋盘不是N * N的就不适用
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
//"/" 分别扫描X、O、空格个数
MyClassCount my_scanf_diagonal_right(char board[ROW][COL], int row, int col){
		int i = 0;
		int j = 0;

		MyClassCount my_count_diagonal_right;
		int ch_X_num = 0;
		int ch_O_num = 0;
		int ch_space_num = 0;

		//如果棋盘不是N*N型的型的就不适用
		if (row == col){
			//"/"的对齐方式
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
//返回斜对角线"\"上的唯一空格坐标
Coordinate scanf__left_find_space(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	
	//定义要返回的坐标
	Coordinate my_coor; 

	if (row == col){
		for (i = 0; i < row; i++){
			if (' ' == board[i][i]){
				my_coor.x = i;
				my_coor.y = i;
			}
		}
	}
	//printf("斜对角线\\上的唯一空格坐标:%d,%d\n", i, i);
	return my_coor;
}
//返回斜对角线"/"上的唯一空格坐标
Coordinate scanf__right_find_space(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	Coordinate my_coor;

	if (row == col){
		//"/"的对齐方式
		for (i = row - 1, j = 0; i >= 0; i--, j++){
			if (board[i][j] == ' '){
				my_coor.x = i;
				my_coor.y = j;
			}
		}
	}
	return my_coor;
}