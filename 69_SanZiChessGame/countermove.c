#include "countermove.h"
#include "myscan.h"



//����������ɺϷ�����
Coordinate rand_create_coor(char board[ROW][COL], int row, int col){
	int flag = 1;//���ñ��Ϊtrue
	
	while (flag){
		//�����������
		int i = rand() % ROW;
		int j = rand() % COL;
		//�ж������Ƿ��Ѿ�ռ��
		if (board[i][j] == 'X' || board[i][j] == 'O'){

		}
		else{
			//board[x][y] = 'O'; //�����ߵ�������O
			flag = 0;//ֹͣѭ��
			Coordinate c;
			c.x = i;
			c.y = j;
			return c;
		}
	}
}
//���ԶԲ�һ����������ҳ����κ���
Coordinate judge_row(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount*  my_count_row = my_scanf_row(board, row, col);
	
	for (i = 0; i < row; i++){
		//��ȡ����ÿһ�е�ɨ����
		if ((my_count_row[i].x_num == row - 1) && (my_count_row[i].space_num == 1)){//˵����ҿ�ҪӮ��
			//�ҵ���λ��������λ�÷���
			for (j = 0; j < col; j++){
				if (board[i][j] == ' '){
					Coordinate c;
					c.x = i;
					c.y = j;
					return c;
				}
			}
		}
	}
	
	//δ���ִ�������� -1,-1
	Coordinate c;
	c.x = -1;
	c.y = -1;
	return c;
}

//���ԶԲ߶�����������ҳ����κ���
Coordinate judge_col(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount*  my_count_col = my_scanf_col(board, row, col);

	for (i = 0; i < col; i++){
		//��ȡ����ÿһ�е�ɨ����
		if ((my_count_col[i].x_num == row - 1) && (my_count_col[i].space_num == 1)){//��ҿ�Ӯ��
			//�ҵ���λ��������λ�÷���
			for (j = 0; j < col; j++){
				if (board[j][i] == ' '){
					Coordinate c;
					c.x = j;
					c.y = i;
					return c;
				}
			}
		}
	}
	//δ���ִ�������� -1,-1
	Coordinate c;
	c.x = -1;
	c.y = -1;
	return c;
}
//���ԶԲ�������������ҳ����κ�\б��
Coordinate judeg_diagonal_left(char board[ROW][COL], int row, int col){

	//���õ�\б���ϵ����ӷֲ����
	MyClassCount  my_scanf_ret_left = my_scanf_diagonal_left(board, row, col);

	if (((row - 1) == my_scanf_ret_left.x_num) && my_scanf_ret_left.space_num == 1){ //��ҿ�Ӯ��
		return  scanf__left_find_space(board, row, col);
	}
	//�����������ķ���
	Coordinate coor;
	coor.x = -1;
	coor.y = -1;
	return coor;
}

//���ԶԲ��ģ���������ҳ����κ�/б��
Coordinate judeg_diagonal_right(char board[ROW][COL], int row, int col){
	MyClassCount my_scanf_ret_right = my_scanf_diagonal_right(board, row, col);
	if (((row - 1) == my_scanf_ret_right.x_num) && my_scanf_ret_right.space_num == 1){ //��ҿ�Ӯ��
		return scanf__right_find_space(board, row, col);
	}
	//�����������ķ���
	Coordinate coor;
	coor.x = -1;
	coor.y = -1;
	return coor;
}

//��ȡ��test.c�д������Ѷ�
static int difficult = 0;
void get_diffiuct(int* p){
	difficult = *p;
}
//�������ӵķ���
void make_sure(char board[ROW][COL], int row, int col){
	Coordinate my_ret;

	//��ȡ��ɨ����
	Coordinate my_ret_row = judge_row(board, row, col);

	//��ȡ��ɨ����
	Coordinate my_ret_col = judge_col(board, row, col);

	//��ȡ"\"ɨ����
	Coordinate my_ret_left = judeg_diagonal_left(board, row, col);

	//��ȡ"/"ɨ����
	Coordinate my_ret_right = judeg_diagonal_right(board, row, col);

	//printf("-------��----%d-----%d\n", my_ret_row.x, my_ret_row.y);
	//printf("-------��----%d-----%d\n", my_ret_col.x, my_ret_col.y);

	//����Է������ϡ����ϡ���Խǡ��ҶԽ�������һ���ߵĻ�������ǰռ��ʣ�µ�һ���ո�
	//���׵�
	if (difficult == 'E' || difficult == 'e'){

		my_ret = rand_create_coor(board, row, col);
		board[my_ret.x][my_ret.y] = 'O';
		return;
	}
	//�Ѷ��е�
	else if (difficult == 'M' || difficult == 'm'){
		if ((my_ret_row.x != -1) && (my_ret_row.y != -1)){
			board[my_ret_row.x][my_ret_row.y] = 'O';
			return;
		}
		if ((my_ret_col.x != -1) && (my_ret_col.y != -1)){
			board[my_ret_col.x][my_ret_col.y] = 'O';
			return;
		}
	
	}
	//���Ѷ�
	else{
		if ((my_ret_row.x != -1) && (my_ret_row.y != -1)){
			board[my_ret_row.x][my_ret_row.y] = 'O';
			return;
		}
		if ((my_ret_col.x != -1) && (my_ret_col.y != -1)){
			board[my_ret_col.x][my_ret_col.y] = 'O';
			return;
		}
		if ((my_ret_left.x != -1) && (my_ret_left.y != -1)){
			board[my_ret_left.x][my_ret_left.y] = 'O';
		}
		if ((my_ret_right.x != -1) && (my_ret_right.y != -1)){
			board[my_ret_right.x][my_ret_right.y] = 'O';
		}
		//�����������������ϣ���ִ���������
		my_ret = rand_create_coor(board, row, col);
		board[my_ret.x][my_ret.y] = 'O';
		return;
	}
}
