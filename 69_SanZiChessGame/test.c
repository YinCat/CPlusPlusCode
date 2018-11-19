#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include "countermove.h"
void menu(){
	printf("----------------------------\n");
	printf("----- 1.play   0.exit-------\n");
	printf("----------------------------\n");
}



void game(){
	int flag = TRUE;

	//选择难度
	char game_difficulty = 0;

	printf("E:简单 M:中等 D:困难，请选择难度>\n");
	while (TRUE){
		fflush(stdin); //不管之前输入多少，输入流缓冲区都先刷掉

		scanf("%c", &game_difficulty);
		//大小写兼容
		if (!(game_difficulty == 'E' || game_difficulty == 'M' || game_difficulty == 'D'||
			game_difficulty == 'e' || game_difficulty == 'm' || game_difficulty == 'd'
			)){
			printf("选择错误,请重新输入!!!\n");
		}
		else{
			//将值传过去
			get_diffiuct(&game_difficulty);
			break;
		}
	}


	//定义二维数组
	char board[ROW][COL];
	//初始化数组
	init_board(board, ROW, COL);

	//打印数组
	print_board(board, ROW, COL);

	//chang用于确定谁走棋,玩家先走棋
	int change = 0;
	while (flag){
		//获取结果
		char my_ret = iswin(board, ROW, COL);

		switch (my_ret){
			case 'X':
				printf("玩家胜利\n");
				print_board(board, ROW, COL);
				flag = FALSE;
				break;
			case 'O':
				printf("电脑胜利\n");
				print_board(board, ROW, COL);
				flag = FALSE;
				break;
			case 'C':
				if (change == 0){
					player_move(board, ROW, COL);
					print_board(board, ROW, COL);
					change = 1;
				}
				else{
					printf("电脑走棋>\n");
					computer_move(board, ROW, COL);
					print_board(board, ROW, COL);
					change = 0;
				}
				break;
			case 'P':
				printf("平局\n");
				flag = FALSE;
				break;
			default:
				printf("返回值错误\n");
				break;
		}
	}
}
int main(void)
{
	//设置随机种子
	srand((unsigned int )time(NULL));
	int chose = 0;
	while (1){
		menu();
		printf("请选择>");
		scanf("%d", &chose);
		switch (chose){
		case START:
			game();
			break;
		case EXIT:
			return 0;
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}
	system("pause");
	return 0;
}