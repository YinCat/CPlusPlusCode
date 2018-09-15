#ifndef __HASH_TABLE_BUCKET_H__
#define __HASH_TABLE_BUCKET_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>


// 使用素数表对齐做哈希表的容量，降低哈希冲突 
#define PRIME_LEN 28
/**
 * \brief 
 */
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

typedef struct HashNode
{
	struct HashNode* _next;
	HTBKeyType _key;
	HTBValueType _value;
}HashNode;

typedef struct HashTableBucket
{
	HashNode** _tables;
	int _size;
	int _len;
}HTB;

void HTBInit(HTB* htb, int len);
void HTBDestory(HTB* htb);

int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value);
int HTBRemove(HTB* htb, HTBKeyType key);
HashNode* HTBFind(HTB* htb, HTBKeyType key);

int HTBSize(HTB* htb);
int HTBEmpty(HTB* htb);

void TestHashTableBucket();

//控制负载
void HBTCheckCapacity(HTB *htb);
#endif //!__HASH_TABLE_BUCKET_H__