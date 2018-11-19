#include "game.h"

//��ʼ��ͨ�����Ĳ����ֱ���ʼ����������
void InitBoard(char board[ROWS][COLS], int rows, int clos,char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++){
		for (j = 0; j < clos; j++){
			board[i][j] = set;
		}
	}
}
//������(����������)
void SetMine(char board[ROWS][COLS], int row, int col, int count){
	int i = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < count; i++){
TRY_AGAIN:
		//����count����
		x = rand() % ROW;
		y = rand() % COL;
		if (x == 0 || y == 0){
			goto TRY_AGAIN;
		}
		if (board[x][y] == '0'){
			board[x][y] = '1';//����1�ĵط�������
		}
		else{
			goto TRY_AGAIN;
		}
	}
}

//��ӡshow(���)����
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

//���׺���
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y){
	if (mine[x][y] == '1'){
		return -1;//return-1��ʾ����ʧ��
	}
	int mine_count = GetMineCount(mine, x, y);
	//show[x][y] = mine_count + '0';
	return mine_count;
}


//����������Χ�׵�����
int GetMineCount(char mine[ROWS][COLS], int x, int y){

	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}

//�ж��Ƿ����꣬���귵��1
int iswin(char show[ROWS][COLS],int row,int col,int mine_count){
	int i = 0;
	int j = 0;
	int count = 0;
	//���ɨ��ͳ��*����
	for (i = 1; i < ROW; i++){
		for (j = 1; j < COL; j++){
			if (show[i][j] == '*'){
				count++;
			}
		}
	}
	printf("count=%d\n", count);
	//���ʣ�µ�*���׵�������ȣ��Ǿ�˵�����׳ɹ�
	if (count==mine_count){
		return 1;
	}
	return 0;

}

//����չ���ķ���������ֻ��չ����Χ8�����꣩
#if 1
void open_mine(char show[ROWS][COLS], char mine[ROWS][COLS],int x, int y)//������Χչ������
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