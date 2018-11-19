#include "address.h"

//1.	添加联系人信息
//2.	删除指定联系人信息
//3.	查找指定联系人信息
//4.	修改指定联系人信息
//5.	显示所有联系人信息
//6.	清空所有联系人
//7.	以名字排序所有联系人
//8、   结构体:姓名、性别、年龄、电话、住址

//程序临时模拟数据库
static MyDB myDB;

//程序临时模拟数据库的初始化
void init_contacts()
{
	//先获取到本地文件的指针
	FILE* fp = fopen(DB_PATH, "a+");
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
#if !RorW  //这里是测试数据，仅仅是用于初始化数据文件！！！
	Contact arr[] = {
		{ "LHL", "女", "19", "13720619020", "陕西省汉中市" },
		{ "ZCL", "男", "20", "15291418231", "陕西省汉中市" },
		{ "DDD", "女", "29", "14291418290", "北京市海淀区" },
		{ "FFF", "男", "11", "11010102811", "北京市朝阳区" },
		
	};
	int len = sizeof(arr)/sizeof(arr[0]);

	//把存储数据的个数写入
	fwrite(&len, sizeof(int), 1, fp);
	
	while (len--)
	{
		//逐个写入数据
		fwrite(&arr[len], sizeof(Contact), 1, fp);
	}
	fclose(fp);
	fp = fopen(DB_PATH, "a+");
#endif //写入数据

#if RorW //读取数据
	int index = 0;
	int num = 0;

	fread(&num, sizeof(int), 1, fp); //先读取文件中元素个数
	
	myDB.con_arr = (pContact)calloc((num + ADD_CAPA),sizeof(Contact));//多申请了2个元素的空间
	myDB.capacity = num + ADD_CAPA;

	index = 0;
	//读本地文件操作
	while (fread(&(myDB.con_arr[index]), sizeof(Contact), 1, fp))
	{
		index++;
		myDB.num++;
	}
	fclose(fp);
#endif //读取数据
}


void menu()
{
	printf("===================================================\n");
	printf("   1、添加联系人   2、删除联系人    3、查找联系人  \n");
	printf("   4、修改联系人   5、显示所有      6、清空所有    \n");
	printf("   7、排序所有联系人                8、退出        \n");
	printf("===================================================\n");
}

//内存不够时自动扩容
static void get_new_memeory()
{
	if (myDB.capacity == myDB.num)
	{
		//重新分配内存
		pContact ptr = realloc(myDB.con_arr, sizeof(Contact)*(myDB.capacity += ADD_CAPA));
		if (ptr != NULL)
		{
			myDB.con_arr = ptr;
		}
		else{
			printf("%s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		printf("扩容成功\n");
	}
}

//添加联系人
int add_contacts(const char* name)
{	
	//判断是否需要扩容
	get_new_memeory();

	printf("请输入联系人性别、年龄、电话、地址，以空格隔开>\n");
	scanf("%s %s %s %s", 
		myDB.con_arr[myDB.num].sex, 
		myDB.con_arr[myDB.num].age,
		myDB.con_arr[myDB.num].tell,
		myDB.con_arr[myDB.num].address);

	strcpy(myDB.con_arr[myDB.num].name, name);
	myDB.num++;

	return write_to_file();
}

//根据查找函数返回的索引值进行删除
int delete_contacts(int index)
{
	int i = 0;
	//逐个前移<但是在不考虑相对顺序的情况下也可以直接把最后一个元素拿到别删除的位置>
	for (i = index; i < myDB.num-1; i++)
	{
		myDB.con_arr[i] = myDB.con_arr[i + 1];
	}
	--myDB.num;
	//更新本地文件
	return write_to_file();
}

//传入姓名，找到返回则索引，没找到返回-1
int find_contacts(const char *name)
{
	int i = 0;
	for (i = 0; i < myDB.num; i++)
	{
		if (strcmp(name, myDB.con_arr[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//返回1表示更新成功，0表示更新失败
int update_contacts(int index)
{
	printf("原信息如下>\n");
	print_info(index);
	printf("请输入修改后的信息，以空格隔开>\n");

	fflush(stdin);
	scanf("%s %s %s %s %s",
		myDB.con_arr[index].name, 
		myDB.con_arr[index].sex,
		myDB.con_arr[index].age,
		myDB.con_arr[index].tell, 
		myDB.con_arr[index].address);
	//更新本地文件
	return write_to_file();
}

//打印所有人的信息
void show_allcontacts()
{
	int i = 0;
	printf("\n\n");
	printf("%-4s\t%-4s\t%-4s\t%-10s\t%-10s\t\n\n",
		"姓名","性别","年龄","电话","地址");
	for (i = 0; i < myDB.num; i++)
	{
		print_info(i);
	}
	printf("\n");
}

//返回1表示清除成功，清除失败则退出
int delete_allcontacts()
{
	myDB.num = 0;
	FILE* fp = fopen(DB_PATH, "wb+");
	if (fp == NULL){
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else{
		fclose(fp);
	}
	return 1;
}

//自定义的排序规则
static int name_cmp(const void *e1, const void *e2)
{
	return strcmp((char*)e1,(char*)e2);
}

//根据名字排序
void sort_contacts()
{
	int i = 0;

#if IS_DEBUG	//不修改本地文件中的存储顺序
	MyDB show_db = myDB;
	qsort(show_db.con_arr, show_db.num, sizeof(Contact), name_cmp);
	for (i = 0; i < show_db.num; i++)
	{
		printf("%-4s\t%-4s\t%-4s\t%-10s\t%-10s\t\n\n", 
			show_db.con_arr[i].name,
			show_db.con_arr[i].sex,
			show_db.con_arr[i].age,
			show_db.con_arr[i].tell, 
			show_db.con_arr[i].address);
	}
#endif
	qsort(myDB.con_arr, myDB.num, sizeof(Contact), name_cmp);
	write_to_file();
}

//打印单个人的信息
void print_info(int index)
{
	printf("%-4s\t%-4s\t%-4s\t%-10s\t%-10s\t\n\n",
		myDB.con_arr[index].name,
		myDB.con_arr[index].sex,
		myDB.con_arr[index].age,
		myDB.con_arr[index].tell,
		myDB.con_arr[index].address);
}

//退出时释放内存
void destroy()
{
	free(myDB.con_arr);
	myDB.con_arr = NULL;
	myDB.capacity = 0;
	myDB.num = 0;
}

//返回1表示成功，0表示失败
static int write_to_file()
{
	FILE* fp = fopen(DB_PATH, "wb+");
	if (fp == NULL)
	{
		printf("%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	//写入文件中(注意把元素数目也写入)
	fwrite(&myDB.num, sizeof(int), 1, fp);

	int i = 0;
	for (i = 0; i < myDB.num; i++)
	{
		fwrite(&(myDB.con_arr[i]), sizeof(Contact), 1, fp);
	}
	fclose(fp);
	return 1;
}
