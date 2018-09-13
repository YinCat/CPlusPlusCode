#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
	struct Node* prev;
}Node, *pNode;

pNode InitList();
pNode BuyNode(DataType data);
void PushBack(pNode* plist, DataType data);
void PrintList(pNode plist);
void DestoryList(pNode* plist);
void PushFront(pNode* plist, DataType x);
void PopBack(pNode* plist);
void PopFront(pNode* plist);
pNode Find(pNode list, DataType x);
void Insert(pNode pos, DataType x);
void Erase(pNode pos);
int ListSize(pNode list);
void test();
#endif // !__DOUBLELIST_H__
