//
// Created by Tim on 2018/9/15.
//
#include <time.h>
#include "HashTableBucket.h"
int HashFunc(HTBKeyType key, HashTableBucket *htb)
{
    return key%htb->len;
}

static int GetNextPrime(int len) {
    int i = 0;
    for(i=0;i<PRIME_LEN;i++)
    {
        if(len<_PrimeList[i])
        {
            return _PrimeList[i];
        }
    }
    return _PrimeList[PRIME_LEN-1];
}
void HTBInit(HashTableBucket* htb, int len)
{
    int _len = GetNextPrime(len);
    assert(htb);
    htb->tables = (HashNode**)malloc(sizeof(HashNode*) * _len);
    htb->size = 0;
    htb->len = _len;
    memset(htb->tables,0,sizeof(HashNode*)*_len);
}

void HTBDestory(HashTableBucket* htb)
{
    int i = 0;
    assert(htb);
    for(i = 0;i<htb->size;i++)
    {
        HashNode *pNode = htb->tables[i];
        HashNode *cur = NULL;
        while(pNode)
        {
            cur = pNode->next;
            free(pNode);
            pNode = cur;
        }
        htb->tables[i] = NULL;
    }
    free(htb->tables);
    htb->tables = NULL;
    htb->len = 0;
    htb->size = 0;
}

int HTBInsert(HashTableBucket* htb, HTBKeyType key, HTBValueType value);
//控制负载
void HTBCheckCapacity(HashTableBucket *htb)
{
    int i = 0;
    assert(htb);
    if(htb->size == htb->len)
    {
        HashTableBucket newHtb;
        newHtb.len = GetNextPrime(htb->len);
        HTBInit(&newHtb,newHtb.len);
        for(i=0;i<htb->len;i++)
        {
            HashNode *next = NULL;
            HashNode *cur = htb->tables[i];
            int index = HashFunc(cur->key,&newHtb);
            while(cur)
            {
                next = cur->next;
                //头插法
                cur->next = newHtb.tables[index];
                newHtb.tables[index] = cur;
                cur = next;
            }
            htb->tables[i] = NULL;
        }
        HTBDestory(htb);
        htb->tables = newHtb.tables;
        htb->len = newHtb.len;
        htb->size = newHtb.size;
    }

}
HashNode* BuyNode(HTBKeyType key,HTBValueType value)
{
    HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));
    if(newNode == NULL)
    {
        perror("BuyNode::malloc");
        return NULL;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
int HTBInsert(HashTableBucket* htb, HTBKeyType key, HTBValueType value)
{
    int index = HashFunc(key, htb);
    HashNode *cur = NULL;
    HashNode *newNode = NULL;
    HTBCheckCapacity(htb);
    newNode = BuyNode(key,value);
    cur = htb->tables[index];
    while(cur)
    {
        if(cur->key == key)
            return -1;
        cur = cur->next;
    }
    //头插法
    newNode->next = htb->tables[index];
    htb->tables[index] = newNode;
    htb->size++;
}

int HTBRemove(HashTableBucket* htb, HTBKeyType key)
{
    int index = HashFunc(key,htb);
    HashNode *cur = NULL;
    HashNode *prev = NULL;
    assert(htb);
    cur = htb->tables[index];
    while(NULL != cur)
    {
        if(cur->key == key)
        {
            if(prev == NULL)
                htb->tables[index] = cur->next;
            else
                prev->next = cur->next;
            free(cur);
            htb->size--;
            return 0;
        }
        prev = cur;
        cur = cur->next;
    }
    return -1;
}

HashNode* HTBFind(HashTableBucket* htb, HTBKeyType key)
{
    int index = HashFunc(key, htb);
    assert(htb);
    HashNode *cur = htb->tables[index];
    while(NULL != cur)
    {
        if(key == cur->key)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

int HTBSize(HashTableBucket* htb)
{
    assert(htb);
    return htb->size;
}
//空返回1，非空返回0
int HTBEmpty(HashTableBucket* htb)
{
    assert(htb);
    return htb->size == 0 ? 1 : 0;
}

void HTBPrint(HashTableBucket* htb)
{
    int i = 0;
    assert(htb);
    for(i=0;i<htb->len;i++)
    {
        HashNode *cur = htb->tables[i];
        if(cur !=NULL)
        {
            while (cur)
            {
                printf("[%d:%d]-->", cur->key, cur->value);
                cur = cur->next;
            }
            printf("END\n");
        }
    }
    printf("\n");
}

void TestHashTableBucket()
{
    int i = 0;
    HashTableBucket htb;
    HTBInit(&htb, 1000);

    srand((unsigned int) time(0));
    for (i = 0; i < 1000; i++)
    {
        HTBInsert(&htb, rand(), 0);
    }
    HTBPrint(&htb);
    HTBDestory(&htb);
}



