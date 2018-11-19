#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;
#define MAX 100

//��̬˳���
typedef struct SeqList{
	DataType data[100];
	int sz;
}SeqList,*PSeqList;

//��ʼ��
void InitSeqList(PSeqList pSeq);

//β������ 
void PushBack(PSeqList pSeq, DataType data); 

//��ӡ 
void PrintSeqList(PSeqList pSeq);

//β��ɾ�� 
void PopBack(PSeqList pSeq); 

//ͷ������ 
void PushFront(PSeqList pSeq, DataType data); 

//ͷ��ɾ�� 
void PopFront(PSeqList pSeq); 

//����ָ��Ԫ�� 
int Find(PSeqList pSeq, DataType data);

//ָ��λ�ò��� 
void Insert(PSeqList pSeq, int pos, DataType data); 

//ɾ��ָ��λ��Ԫ�� 
void Erase(PSeqList pSeq, int pos);

//ɾ��ָ��Ԫ�� 
void Remove(PSeqList pSeq, DataType data); 

//ɾ�����е�ָ��Ԫ�� 
void RemoveAll(PSeqList pSeq, DataType data); 

//����˳���Ĵ�С 
int Size(PSeqList pSeq); 

//�ж�˳����Ƿ�Ϊ�� 
int Empty(PSeqList pSeq);

//ð������ 
void BubbleSort(PSeqList pSeq); 

//ѡ������ 
void SelectSort(PSeqList pSeq); 

//ѡ��������Ż� 
void SelectSortOP( PSeqList pSeq); 

//���ֲ��� 
int BinarySearch( PSeqList pSeq, DataType data);

//���ֲ��ҵݹ�д�� 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d); 
#endif //__SEQLIST_H__