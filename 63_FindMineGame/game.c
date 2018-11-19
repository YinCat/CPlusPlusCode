#include "game.h"

//初始化通过传的参数分贝初始化两个数组
void InitBoard(char board[ROWS][COLS], int rows, int clos,char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++){
		for (j = 0; j < clos; j++){
			board[i][j] = set;
		}
	}
}
//设置雷(开发者数组)
void SetMine(char board[ROWS][COLS], int row, int col, int count){
	int i = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < count; i++){
TRY_AGAIN:
		//设置count次雷
		x = rand() % ROW;
		y = rand() % COL;
		if (x == 0 || y == 0){
			goto TRY_AGAIN;
		}
		if (board[x][y] == '0'){
			board[x][y] = '1';//设置1的地方就是雷
		}
		else{
			goto TRY_AGAIN;
		}
	}
}

//打印show(玩家)数组
void PrintBoard(char board[ROWS][COLS], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS-1; i++){
		for (j = 0; j < COLS-1; j++){	
			if (i == 0){
				printf("%d ", j);
			}else if(j == 0){
				printf("%d ",i);
			}
			else{
				printf("%c ", board[i][j]);
			}
		}
		printf("\n");
	}
}

//排雷函数
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y){
	if (mine[x][y] == '1'){
		return -1;//return-1表示排雷失败
	}
	int mine_count = GetMineCount(mine, x, y);
	//show[x][y] = mine_count + '0';
	return mine_count;
}


//返回坐标周围雷的数量
int GetMineCount(char mine[ROWS][COLS], int x, int y){

	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}

//判断是否排完，排完返回1
int iswin(char show[ROWS][COLS],int row,int col,int mine_count){
	int i = 0;
	int j = 0;
	int count = 0;
	//逐个扫描统计*个数
	for (i = 1; i < ROW; i++){
		for (j = 1; j < COL; j++){
			if (show[i][j] == '*'){
				count++;
			}
		}
	}
	printf("count=%d\n", count);
	//如果剩下的*和雷的数量相等，那就说明排雷成功
	if (count==mine_count){
		return 1;
	}
	return 0;

}

//坐标展开的方法（但是只是展开周围8个坐标）
#if 1
void open_mine(char show[ROWS][COLS], char mine[ROWS][COLS],int x, int y)//坐标周围展开函数
{
	if (show[x][y] == '*' && ((x >= 1) && (x <= 9)) && ((y >= 1) && (y <= 9)))
	{
		if (GetMineCount(mine,x, y) != 0)
		{
			show[x][y] = GetMineCount(mine, x, y) + '0';
		}
		else 
		{
			show[x][y] = ' ';
			open_mine(show, mine,x - 1, y);
			open_mine(show, mine, x - 1, y - 1);
			open_mine(show, mine, x - 1, y + 1);
			open_mine(show, mine, x, y - 1);
			open_mine(show, mine, x, y + 1);
			open_mine(show, mine, x + 1, y - 1);
			open_mine(show, mine, x + 1, y);
			open_mine(show, mine, x + 1, y + 1);
		}
	}
	return;
}

#endif