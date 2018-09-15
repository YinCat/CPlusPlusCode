//
// Created by Tim on 2018/9/15.
//
#include "HashTableBucket.h"
int HashFunc(HTBKeyType key, HashTableBucket *htb)
{
    return key%htb->len;
}

int GetNextPrime(int len) {
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
    }
    free(htb->tables);
    htb->tables = NULL;
    htb->len = 0;
    htb->size = 0;
}

int HTBInsert(HashTableBucket* htb, HTBKeyType key, HTBValueType value)
{
    int index = HashFunc(key, htb);


}
int HTBRemove(HashTableBucket* htb, HTBKeyType key);
HashNode* HTBFind(HashTableBucket* htb, HTBKeyType key);

int HTBSize(HashTableBucket* htb);
int HTBEmpty(HashTableBucket* htb);

void TestHashTableBucket();

//控制负载
void HBTCheckCapacity(HashTableBucket *htb);

