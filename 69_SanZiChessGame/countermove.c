#include "countermove.h"
#include "myscan.h"



//电脑随机生成合法坐标
Coordinate rand_create_coor(char board[ROW][COL], int row, int col){
	int flag = 1;//设置标记为true
	
	while (flag){
		//随机生成坐标
		int i = rand() % ROW;
		int j = rand() % COL;
		//判断坐标是否已经占用
		if (board[i][j] == 'X' || board[i][j] == 'O'){

		}
		else{
			//board[x][y] = 'O'; //电脑走的棋子是O
			flag = 0;//停止循环
			Coordinate c;
			c.x = i;
			c.y = j;
			return c;
		}
	}
}
//电脑对策一：不允许玩家成立任何行
Coordinate judge_row(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount*  my_count_row = my_scanf_row(board, row, col);
	
	for (i = 0; i < row; i++){
		//获取到了每一行的扫描结果
		if ((my_count_row[i].x_num == row - 1) && (my_count_row[i].space_num == 1)){//说明玩家快要赢了
			//找到空位，并将空位置返回
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
	
	//未出现此情况返回 -1,-1
	Coordinate c;
	c.x = -1;
	c.y = -1;
	return c;
}

//电脑对策二：不允许玩家成立任何列
Coordinate judge_col(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	MyClassCount*  my_count_col = my_scanf_col(board, row, col);

	for (i = 0; i < col; i++){
		//获取到了每一行的扫描结果
		if ((my_count_col[i].x_num == row - 1) && (my_count_col[i].space_num == 1)){//玩家快赢了
			//找到空位，并将空位置返回
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
	//未出现此情况返回 -1,-1
	Coordinate c;
	c.x = -1;
	c.y = -1;
	return c;
}
//电脑对策三：不允许玩家成立任何\斜行
Coordinate judeg_diagonal_left(char board[ROW][COL], int row, int col){

	//先拿到\斜行上的棋子分布情况
	MyClassCount  my_scanf_ret_left = my_scanf_diagonal_left(board, row, col);

	if (((row - 1) == my_scanf_ret_left.x_num) && my_scanf_ret_left.space_num == 1){ //玩家快赢了
		return  scanf__left_find_space(board, row, col);
	}
	//条件不成立的返回
	Coordinate coor;
	coor.x = -1;
	coor.y = -1;
	return coor;
}

//电脑对策四：不允许玩家成立任何/斜行
Coordinate judeg_diagonal_right(char board[ROW][COL], int row, int col){
	MyClassCount my_scanf_ret_right = my_scanf_diagonal_right(board, row, col);
	if (((row - 1) == my_scanf_ret_right.x_num) && my_scanf_ret_right.space_num == 1){ //玩家快赢了
		return scanf__right_find_space(board, row, col);
	}
	//条件不成立的返回
	Coordinate coor;
	coor.x = -1;
	coor.y = -1;
	return coor;
}

//获取到test.c中传来的难度
static int difficult = 0;
void get_diffiuct(int* p){
	difficult = *p;
}
//电脑落子的方法
void make_sure(char board[ROW][COL], int row, int col){
	Coordinate my_ret;

	//获取行扫描结果
	Coordinate my_ret_row = judge_row(board, row, col);

	//获取列扫描结果
	Coordinate my_ret_col = judge_col(board, row, col);

	//获取"\"扫描结果
	Coordinate my_ret_left = judeg_diagonal_left(board, row, col);

	//获取"/"扫描结果
	Coordinate my_ret_right = judeg_diagonal_right(board, row, col);

	//printf("-------行----%d-----%d\n", my_ret_row.x, my_ret_row.y);
	//printf("-------列----%d-----%d\n", my_ret_col.x, my_ret_col.y);

	//如果对方在行上、列上、左对角、右对角想连成一条线的话，就提前占用剩下的一个空格
	//简易的
	if (difficult == 'E' || difficult == 'e'){

		my_ret = rand_create_coor(board, row, col);
		board[my_ret.x][my_ret.y] = 'O';
		return;
	}
	//难度中等
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
	//高难度
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
		//若上述条件都不符合，则执行随机坐标
		my_ret = rand_create_coor(board, row, col);
		board[my_ret.x][my_ret.y] = 'O';
		return;
	}
}
