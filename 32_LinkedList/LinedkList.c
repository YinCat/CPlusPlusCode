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
    pNodeList list = *pplist;
    pNodeList cur = NULL;
    assert(pplist);
    if(*pplist == NULL)
        return;
    while

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

void PrintList(pNodeList plist)
{
    pNodeList cur = NULL;
    if(plist == NULL)
        return;
    while(cur)
    {
        printf("%d--->",cur->data);
        cur = cur->next;
    }
    printf("END\n");
}

