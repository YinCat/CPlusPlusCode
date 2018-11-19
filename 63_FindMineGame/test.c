#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "game.h"

#define TRUE 1 
#define FALSE 0
#define MINE_COUNT 4

void game(){
	//定义二维数组
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };

	//初始化显示界面数组
	InitBoard(show, ROWS, COLS,'*');
	InitBoard(mine, ROWS, COLS, '0');

	//布雷
	SetMine(mine,ROWS,COLS,MINE_COUNT);

	//打印数组
	PrintBoard(show, ROWS, COLS);
	printf("------------------------------\n");
	PrintBoard(mine, ROWS, COLS);

	int isFirstInput = TRUE;
	while (1){
		if (iswin(show,ROW,COL,MINE_COUNT)){
			printf("恭喜你，排雷完毕！\n");
			break;
		}
		int x = 0;
		int y = 0;
		printf("请输入要排除的坐标>\n");
	TRY_AGRGIN:
		fflush(stdin);
		scanf("%d%d", &x, &y);
		if (isFirstInput){
			if (mine[x][y] == '1'){
				//重新布雷
				InitBoard(mine, ROWS, COLS, '0');
				SetMine(mine, ROWS, COLS, MINE_COUNT);
			}
			isFirstInput = FALSE;
		}
		
		//排查雷
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL)){
			int ret = FindMine(mine, show, x , y);
			if (ret == -1){
				printf("排雷失败!!!\n");
				break;
			}
			//排雷成功则展开
			open_mine(show, mine, x, y);

			PrintBoard(show, ROWS, COLS);
			printf("------------------------------\n");
			PrintBoard(mine, ROWS, COLS);
			
		}
		else{
			printf("输入有误，请重新输入>\n");
			goto TRY_AGRGIN;
		}
	}
}
void menu(){
	printf("--------------扫雷------------\n");
	printf("-------1、play    0、exit-----\n");
	printf("------------------------------\n");
}
int main(void){

	//设置随机种子
	srand((unsigned)time(NULL));

	while (1){
		int your_chosr = 0;
		menu();
		printf("请选择>");
		fflush(stdin); //在输入之前先刷空缓冲区
		scanf("%c", &your_chosr);
		switch (your_chosr){
			case '1':
				game();
				break;
			case '0':
				return 0;
			default:
				printf("输入有误,请重新输入>\n");
				break;
		}
	}
	system("pause");
	return 0;
}