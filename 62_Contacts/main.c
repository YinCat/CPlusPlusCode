#include "address.h"

int main(void)
{
	int chose = 0; //选择菜单
	char input[NAME_MAX] = { 0 };//输入的姓名

	//初始化
	init_contacts();
	while (1)
	{
		menu();
		printf("请选择>");
		fflush(stdin);
		scanf("%d", &chose);
		switch (chose)
		{
		case 1: //添加联系人信息
		{
					char name[NAME_MAX] = { 0 };
					printf("请输入姓名>");
					fflush(stdin);
					scanf("%s", name);
					if (find_contacts(name) == -1)//说明原数据中没有此名称，即可添加
					{
						if (add_contacts(name))
						{
							printf("添加成功!!!\n\n");
						}
						else{
							printf("添加失败!!!\n\n");
						}
					}
					else{
						printf("该联系人已存在!!!\n\n");
					}
		}
			break;
		case 2: //删除指定联系人信息
		{
					printf("请输入姓名>");
					fflush(stdin);
					scanf("%s", input);
					int ret = 0;
					if ((ret = find_contacts(input)) != -1)//先查找是否存在此联系人
					{
						if (delete_contacts(ret))
						{
							printf("删除成功!!!\n\n");
						}
						else{
							printf("删除失败!!!\n\n");
						}
					}
					else{
						printf("未找到该联系人！\n\n");
					}
		}
			break;
		case 3: //查找指定联系人信息
		{
					printf("请输入姓名>");
					fflush(stdin);
					scanf("%s", input);
					int ret = 0;
					if ((ret = find_contacts(input)) != -1)
					{
						//找到就打印出来
						printf("\n");
						print_info(ret);
						printf("\n");
					}
					else{
						printf("未找到该联系人！\n\n");
					}
		}
			break;
		case 4:  //修改指定联系人信息
		{
					 printf("请输入姓名>");
					 fflush(stdin);
					 scanf("%s", input);
					 int ret = 0;
					 if ((ret = find_contacts(input)) != -1)
					 {
						 //更新联系人
						 if (update_contacts(ret))
						 {
							 printf("更新成功!!!\n\n");
						 }
						 else{
							 printf("更新失败!!!\n\n");
						 }
					 }
					 else{
						 printf("未找到该联系人！\n\n");
					 }
		}
			break;
		case 5: //显示所有联系人信息
			show_allcontacts();
			break;
		case 6: //清空所有联系人
			printf("确认清空？Y/N  >");
			int m_chose = 0;
			fflush(stdin);
			m_chose = getchar();
			if (m_chose == 'Y')
			{
				if (delete_allcontacts())
				{
					printf("清空成功!\n\n");
				}
				else{
					printf("清空失败，请检查是否有其他进程正在使用该文件!!!\n\n");
				}
			}
			break;
		case 7: //以名字排序所有联系人
			sort_contacts();
			break;
		case 8:
			//退出前也是执行释放内存
			destroy();
			exit(0);
			break;
		default:
			printf("选择错误!!!\n");
			break;
		}
	}
	return 0;
}

