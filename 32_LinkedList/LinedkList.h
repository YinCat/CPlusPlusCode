//
// Created by Tim on 2018/9/14.
//

#ifndef INC_32_LINKEDLIST_LINEDKLIST_H
#define INC_32_LINKEDLIST_LINEDKLIST_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int DataType;
typedef struct ListNode{
    DataType data;
    struct ListNode *next;
}ListNode,*pNodeList;

void InitList(pNodeList *pplist);
void Destory(pNodeList *pplist);
void PushBack(pNodeList *pplist,DataType data);
void PushFront(pNodeList *pplist,DataType data);
void PrintList(const struct ListNode *plist);
void PopFront(pNodeList *pplist);
void PopBack(pNodeList *pplist);
ListNode const* Find(struct ListNode const* plist,DataType data);
void Remove(pNodeList *pplist,DataType data);
void RemoveAll(pNodeList *pplist,DataType data);
#endif //INC_32_LINKEDLIST_LINEDKLIST_H
