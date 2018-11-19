#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include "countermove.h"
#include "myscan.h"


//���飨���̣���ʼ��
void init_board(char board[ROW][COL], int row, int col){
	int i = 0; 
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}
//�������
void player_move(char board[ROW][COL], int row, int col){
	int flag = TRUE;
	int x = 0;
	int y = 0;
	printf("�������,����������>\n");
	while (flag){
		scanf("%d%d", &x, &y);
		//�ж������Ƿ�Խ��
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL){
			//�ж������Ƿ��Ѿ�ռ��
			if (board[x - 1][y - 1] == 'X' || board[x - 1][y - 1] == 'O'){
				printf("������ռ��\n");
			}
			else{
				board[x - 1][y - 1] = 'X'; //����ߵ�������X
				flag = FALSE;//ֹͣѭ��
			}
		}
		else{
			printf("����Ƿ�\n");
		}
	}
}
//��������
void computer_move(char board[ROW][COL], int row, int col){
	make_sure(board, row, col);
}
//�жϽ��
char iswin(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount* my_ret_row = my_scanf_row(board, row, col);
	for (i = 0; i < row; i++){
		if (row == my_ret_row[i].o_num){
			return 'O'; //����Ӯ
		}
		else if (row == my_ret_row[i].x_num){
			return 'X';  //���Ӯ
		}
		
	}
	//�ͷŽ�������ڴ�
	free(my_ret_row);
	
	MyClassCount* my_ret_col = my_scanf_col(board, row, col);
	for (i = 0; i < row; i++){
		if (row == my_ret_row[i].o_num){
			return 'O'; //����Ӯ
		}
		else if (row == my_ret_row[i].x_num){
			return 'X';  //���Ӯ
		}
	}
	//�ͷŽ�������ڴ�
	free(my_ret_col);

	
	//����б�����
	//������̲���N*N�͵��͵ľͲ�����
	if (COL == ROW){
			MyClassCount my_ret_left = my_scanf_diagonal_left(board, row, col);
			if (row == my_ret_left.o_num){
				return 'O';
			}
			else if (row == my_ret_left.x_num){
				return 'X';
			}
	}

	//�ж��Ƿ���ƽ��
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			if (board[i][j] == ' '){
				//˵������λ��
				return 'C';//continue
			}
		}
	}
	return 'P';//ƽ�� 
}
//��ӡ����
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