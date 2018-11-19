#ifndef __ADDRESS_H__
#define __ADDRESS_H__

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<errno.h>

#define IS_DEBUG 1	 //调试模式
#define RorW  1		//写入模式


#define NAME_MAX 20		//名称最大长度
#define SEX_MAX 6		//性别最大长度
#define AGE_MAX 6		//年龄最大长度
#define TELL_MAX 12		//电话最大长度
#define ADD_MAX 30		//地址最大长度

#define ADD_CAPA 2		//一次增容两个

#define DB_PATH "C:\\Users\\NeverGiveUp\\Documents\\my.db" //本地文件存储的位置

//联系人结构体：姓名、性别、年龄、电话、住址
typedef struct Contact{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char age[AGE_MAX];
	char tell[TELL_MAX];
	char address[ADD_MAX];
}Contact,*pContact;

//程序运行时临时数据库结构体
typedef struct MyDB{
	pContact con_arr;
	int num;//已经存储的个数
	int capacity; //容量
}MyDB;


//初始化临时数据库
void init_contacts();

//菜单
void menu();

//添加联系人
int add_contacts(const char* name);

//删除联系人
int delete_contacts(int index);

//根据名字查找联系人
int find_contacts(const char *name);

//修改联系人
int update_contacts(int index);

//显示所有联系人
void show_allcontacts();

//删除所有联系人
int delete_allcontacts();

//根据名字排序
void sort_contacts();

//打印单个信息
void print_info(int index);

//写入文件
static int write_to_file();

//程序退出时的销毁方法
void destroy();

#endif //_ADDRESS_H__
