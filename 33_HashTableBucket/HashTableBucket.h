//
// Created by Tim on 2018/9/15.
//

#ifndef _HASHTABLEBUCKET_H__
#define _HASHTABLEBUCKET_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <assert.h>

// 使用素数表对齐做哈希表的容量，降低哈希冲突
#define PRIME_LEN 28

static const unsigned long _PrimeList[PRIME_LEN] =
        {
                53ul,         97ul,         193ul,       389ul,       769ul,
                1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
                49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
                1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
                50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
                1610612741ul, 3221225473ul, 4294967291ul
        };

typedef int HTBKeyType;
typedef int HTBValueType;

typedef struct HashNode{
    struct HashNode *next;
    HTBKeyType key;
    HTBValueType value;
}HashNode;

typedef struct HashTableBucket{
    HashNode **tables;
    int size;
    int len;
}HashTableBucket;

void HTBInit(HashTableBucket* htb, int len);
void HTBDestory(HashTableBucket* htb);

int HTBInsert(HashTableBucket* htb, HTBKeyType key, HTBValueType value);
int HTBRemove(HashTableBucket* htb, HTBKeyType key);
HashNode* HTBFind(HashTableBucket* htb, HTBKeyType key);

int HTBSize(HashTableBucket* htb);
int HTBEmpty(HashTableBucket* htb);

void HTBPrint(HashTableBucket* htb);

void TestHashTableBucket();

#endif //_HASHTABLEBUCKET_H__
