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

	//ѡ���Ѷ�
	char game_difficulty = 0;

	printf("E:�� M:�е� D:���ѣ���ѡ���Ѷ�>\n");
	while (TRUE){
		fflush(stdin); //����֮ǰ������٣�����������������ˢ��

		scanf("%c", &game_difficulty);
		//��Сд����
		if (!(game_difficulty == 'E' || game_difficulty == 'M' || game_difficulty == 'D'||
			game_difficulty == 'e' || game_difficulty == 'm' || game_difficulty == 'd'
			)){
			printf("ѡ�����,����������!!!\n");
		}
		else{
			//��ֵ����ȥ
			get_diffiuct(&game_difficulty);
			break;
		}
	}


	//�����ά����
	char board[ROW][COL];
	//��ʼ������
	init_board(board, ROW, COL);

	//��ӡ����
	print_board(board, ROW, COL);

	//chang����ȷ��˭����,���������
	int change = 0;
	while (flag){
		//��ȡ���
		char my_ret = iswin(board, ROW, COL);

		switch (my_ret){
			case 'X':
				printf("���ʤ��\n");
				print_board(board, ROW, COL);
				flag = FALSE;
				break;
			case 'O':
				printf("����ʤ��\n");
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
					printf("��������>\n");
					computer_move(board, ROW, COL);
					print_board(board, ROW, COL);
					change = 0;
				}
				break;
			case 'P':
				printf("ƽ��\n");
				flag = FALSE;
				break;
			default:
				printf("����ֵ����\n");
				break;
		}
	}
}
int main(void)
{
	//�����������
	srand((unsigned int )time(NULL));
	int chose = 0;
	while (1){
		menu();
		printf("��ѡ��>");
		scanf("%d", &chose);
		switch (chose){
		case START:
			game();
			break;
		case EXIT:
			return 0;
			break;
		default:
			printf("�������\n");
			break;
		}
	}
	system("pause");
	return 0;
}