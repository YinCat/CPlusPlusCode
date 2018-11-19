#include "SeqList.h"

//测试初始化、尾部插入、尾部删除、打印
void Test1()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
}

//测试头部插入、头部删除
void Test2()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PrintSeqList(&seq);
	PushFront(&seq,5);
	PrintSeqList(&seq);
	PushFront(&seq,6);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}

void Test03()
{
	SeqList seq;
	int pos = 0;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	pos = Find(&seq,3);
	if(pos == -1)
	{
		printf("未找到\n");
	}
	else
	{	
		Insert(&seq,pos,5);
	}
	PrintSeqList(&seq);
}

void Test04()
{
	SeqList seq;
	int pos = 0;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	pos = Find(&seq,3);
	if(pos == -1)
	{
		printf("未找到\n");
	}
	else
	{	
		Erase(&seq,pos);
	}
	PrintSeqList(&seq);
}
void Test05()
{
	SeqList seq;
	int pos = 0;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,5);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	PushBack(&seq,5);
	PushBack(&seq,9);
	PrintSeqList(&seq);
	Erase(&seq,2);
	PrintSeqList(&seq);
	Remove(&seq,5);
	PrintSeqList(&seq);
	RemoveAll(&seq,5);
	PrintSeqList(&seq);
}
void Test06()
{
	SeqList seq;
	int pos = 0;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,50);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	PushBack(&seq,54);
	PushBack(&seq,9);
	PrintSeqList(&seq);
	//BubbleSort(&seq);
	//SelectSort(&seq)
	SelectSortOP(&seq);
	PrintSeqList(&seq);	
}

void Test07()
{	
	SeqList seq;
	int pos = 0;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,50);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	PushBack(&seq,54);
	PushBack(&seq,9);
	SelectSortOP(&seq);
	PrintSeqList(&seq);

	//pos = BinarySearch(&seq,500);
	pos = BinarySearch_R(&seq,0,seq.sz-1,4);
	if(pos != -1)
	{
		printf("找到,索引为:%d\n",pos);
	}
	else
	{
		printf("未找到\n");
	}
}
int main()
{
	Test07( );
	system("pause");
	return 0;
}