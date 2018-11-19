#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include "countermove.h"
#include "myscan.h"


//数组（棋盘）初始化
void init_board(char board[ROW][COL], int row, int col){
	int i = 0; 
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}
//玩家走棋
void player_move(char board[ROW][COL], int row, int col){
	int flag = TRUE;
	int x = 0;
	int y = 0;
	printf("玩家走棋,请输入坐标>\n");
	while (flag){
		scanf("%d%d", &x, &y);
		//判断坐标是否越界
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL){
			//判断坐标是否已经占用
			if (board[x - 1][y - 1] == 'X' || board[x - 1][y - 1] == 'O'){
				printf("坐标已占用\n");
			}
			else{
				board[x - 1][y - 1] = 'X'; //玩家走的棋子是X
				flag = FALSE;//停止循环
			}
		}
		else{
			printf("坐标非法\n");
		}
	}
}
//电脑走棋
void computer_move(char board[ROW][COL], int row, int col){
	make_sure(board, row, col);
}
//判断结果
char iswin(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount* my_ret_row = my_scanf_row(board, row, col);
	for (i = 0; i < row; i++){
		if (row == my_ret_row[i].o_num){
			return 'O'; //电脑赢
		}
		else if (row == my_ret_row[i].x_num){
			return 'X';  //玩家赢
		}
		
	}
	//释放结果集的内存
	free(my_ret_row);
	
	MyClassCount* my_ret_col = my_scanf_col(board, row, col);
	for (i = 0; i < row; i++){
		if (row == my_ret_row[i].o_num){
			return 'O'; //电脑赢
		}
		else if (row == my_ret_row[i].x_num){
			return 'X';  //玩家赢
		}
	}
	//释放结果集的内存
	free(my_ret_col);

	
	//出现斜着相等
	//如果棋盘不是N*N型的型的就不适用
	if (COL == ROW){
			MyClassCount my_ret_left = my_scanf_diagonal_left(board, row, col);
			if (row == my_ret_left.o_num){
				return 'O';
			}
			else if (row == my_ret_left.x_num){
				return 'X';
			}
	}

	//判断是否是平局
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			if (board[i][j] == ' '){
				//说明还有位置
				return 'C';//continue
			}
		}
	}
	return 'P';//平局 
}
//打印棋盘
void print_board(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;

	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			if (j < COL - 1){
				printf(" %c |", board[i][j]);
			}
			else{
				printf(" %c\n", board[i][j]);
			}	
		}
		if (i < ROW - 1){
			for (j = 0; j < COL; j++){
				if (j < COL - 1){
					printf("---|");
				}
				else{
					printf("---\n");
				}
				
			}
		}
		
	}
}