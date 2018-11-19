#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;
#define MAX 100

//静态顺序表
typedef struct SeqList{
	DataType data[100];
	int sz;
}SeqList,*PSeqList;

//初始化
void InitSeqList(PSeqList pSeq);

//尾部插入 
void PushBack(PSeqList pSeq, DataType data); 

//打印 
void PrintSeqList(PSeqList pSeq);

//尾部删除 
void PopBack(PSeqList pSeq); 

//头部插入 
void PushFront(PSeqList pSeq, DataType data); 

//头部删除 
void PopFront(PSeqList pSeq); 

//查找指定元素 
int Find(PSeqList pSeq, DataType data);

//指定位置插入 
void Insert(PSeqList pSeq, int pos, DataType data); 

//删除指定位置元素 
void Erase(PSeqList pSeq, int pos);

//删除指定元素 
void Remove(PSeqList pSeq, DataType data); 

//删除所有的指定元素 
void RemoveAll(PSeqList pSeq, DataType data); 

//返回顺序表的大小 
int Size(PSeqList pSeq); 

//判断顺序表是否为空 
int Empty(PSeqList pSeq);

//冒泡排序 
void BubbleSort(PSeqList pSeq); 

//选择排序 
void SelectSort(PSeqList pSeq); 

//选择排序的优化 
void SelectSortOP( PSeqList pSeq); 

//二分查找 
int BinarySearch( PSeqList pSeq, DataType data);

//二分查找递归写法 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d); 
#endif //__SEQLIST_H__