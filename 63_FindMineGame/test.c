#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "game.h"

#define TRUE 1 
#define FALSE 0
#define MINE_COUNT 4

void game(){
	//�����ά����
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };

	//��ʼ����ʾ��������
	InitBoard(show, ROWS, COLS,'*');
	InitBoard(mine, ROWS, COLS, '0');

	//����
	SetMine(mine,ROWS,COLS,MINE_COUNT);

	//��ӡ����
	PrintBoard(show, ROWS, COLS);
	printf("------------------------------\n");
	PrintBoard(mine, ROWS, COLS);

	int isFirstInput = TRUE;
	while (1){
		if (iswin(show,ROW,COL,MINE_COUNT)){
			printf("��ϲ�㣬������ϣ�\n");
			break;
		}
		int x = 0;
		int y = 0;
		printf("������Ҫ�ų�������>\n");
	TRY_AGRGIN:
		fflush(stdin);
		scanf("%d%d", &x, &y);
		if (isFirstInput){
			if (mine[x][y] == '1'){
				//���²���
				InitBoard(mine, ROWS, COLS, '0');
				SetMine(mine, ROWS, COLS, MINE_COUNT);
			}
			isFirstInput = FALSE;
		}
		
		//�Ų���
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL)){
			int ret = FindMine(mine, show, x , y);
			if (ret == -1){
				printf("����ʧ��!!!\n");
				break;
			}
			//���׳ɹ���չ��
			open_mine(show, mine, x, y);

			PrintBoard(show, ROWS, COLS);
			printf("------------------------------\n");
			PrintBoard(mine, ROWS, COLS);
			
		}
		else{
			printf("������������������>\n");
			goto TRY_AGRGIN;
		}
	}
}
void menu(){
	printf("--------------ɨ��------------\n");
	printf("-------1��play    0��exit-----\n");
	printf("------------------------------\n");
}
int main(void){

	//�����������
	srand((unsigned)time(NULL));

	while (1){
		int your_chosr = 0;
		menu();
		printf("��ѡ��>");
		fflush(stdin); //������֮ǰ��ˢ�ջ�����
		scanf("%c", &your_chosr);
		switch (your_chosr){
			case '1':
				game();
				break;
			case '0':
				return 0;
			default:
				printf("��������,����������>\n");
				break;
		}
	}
	system("pause");
	return 0;
}