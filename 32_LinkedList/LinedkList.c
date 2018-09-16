//
// Created by Tim on 2018/9/14.
//

#include "LinedkList.h"

void InitList(pNodeList *pplist)
{
    assert(pplist);
    *pplist = NULL;
}

void Destory(pNodeList *pplist)
{
    pNodeList cur = *pplist;
    pNodeList next = NULL;
    assert(pplist);
    if(*pplist == NULL)
        return;
    while(cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *pplist = NULL;
}

static pNodeList BuyNode(DataType data)
{
    pNodeList newNode = NULL;
    newNode = (pNodeList)malloc(sizeof(ListNode));
    if(newNode == NULL)
    {
        perror("BuyNode::malloc");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void PushBack(pNodeList *pplist,DataType data)
{
    pNodeList cur = NULL;
    assert(pplist);
    if(*pplist == NULL)
    {
        *pplist = BuyNode(data);
    }
    else
    {
        cur = *pplist;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = BuyNode(data);
    }
}

//void PrintList(const pListNode *plist)与void PrintList(struct ListNode *const plist)等价
void PrintList(const struct ListNode *plist)
{
    if(plist == NULL)
    {
        printf("空链表\n");
        return;
    }
    while(plist)
    {
        printf("%d-->",plist->data);
        plist = plist->next;
    }
    printf("END\n");
}

void PushFront(pNodeList *pplist,DataType data)
{
    ListNode *newNode = NULL;
    assert(pplist);
    newNode = BuyNode(data);
    newNode->next = *pplist;
    (*pplist) = newNode;
}
void PopFront(pNodeList *pplist)
{
    ListNode *cur = NULL;
    assert(pplist);
    if((*pplist) == NULL)
        return;
    cur = (*pplist);
    *pplist = (*pplist)->next;
    free(cur);
    cur = NULL;
}
void PopBack(pNodeList *pplist)
{
    ListNode *cur = NULL;
    ListNode *prev = NULL;
    if(*pplist == NULL)
        return;

    cur = *pplist;
    while(cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    if(prev != NULL)
        prev->next = NULL;
    else
    {
        free(*pplist);
        *pplist = NULL;
    }
}
ListNode const* Find(struct ListNode const * plist,DataType data)
{
    assert(plist);
    while(plist)
    {
        if(plist->data == data)
            return plist;
        plist = plist->next;
    }
    return NULL;
}

void Remove(pNodeList *pplist,DataType data)
{}

void RemoveAll(pNodeList *pplist,DataType data);