#include "HashTableBucket.h"

//根据长度返回素数表中的数字
unsigned long GetNextPrime(int len)
{
	int i = 0;
	for (i = 0; i < PRIME_LEN; i++)
	{
		if (len < _PrimeList[i])
		{
			return _PrimeList[i];
		}
	}
	return _PrimeList[PRIME_LEN - 1];
}

//哈希函数
int MyHashFunc(HTBKeyType key,int len)
{
	return key % len;
}

void HTBInit(HTB* htb, int len)
{
	assert(htb);
	htb->_len = GetNextPrime(len);
	htb->_tables = (HashNode**)malloc((htb->_len) * sizeof(HashNode*));
	htb->_size = 0;
	memset(htb->_tables, 0, sizeof(HashNode*) * (htb->_len));
}

void HTBDestory(HTB* htb)
{
	int i = 0;
	assert(htb);
	for (i = 0; i < htb->_len; i++)
	{
		HashNode* cur = htb->_tables[i];
		HashNode* next = NULL;
		while (cur)
		{
			next = cur->_next;
			free(cur);
			cur = next;
		}
		htb->_tables[i] = NULL;
	}
	free(htb->_tables);
	htb->_tables = NULL;
	htb->_size = 0;
	htb->_len = 0;
}
//typedef struct HashNode
//{
//	struct HashNode* _next;
//	HTBKeyType _key;
//	HTBValueType _value;
//}HashNode;

HashNode* BuyHashNode(HTBKeyType key, HTBValueType value)
{
	HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));
	if (newNode == NULL)
		perror("BuyHashNode::malloc");
	newNode->_key = key;
	newNode->_value = value;
	newNode->_next = NULL;

	return newNode;
}

//控制负载
void HBTCheckCapacity(HTB *htb)
{
	assert(htb);
	int i = 0;
	if (htb->_size == htb->_len)
	{
		HTB newHTB;
		newHTB._len = GetNextPrime(htb->_len);
		HTBInit(&newHTB, newHTB._len);
		for (i = 0; i < htb->_len; i++)
		{
			//拿到所有的链表节点
			HashNode *cur = htb->_tables[i];
			while (cur)
			{
				HashNode *next = cur->_next;
				int index = MyHashFunc(cur->_key, newHTB._len);
				//头插
				cur->_next = newHTB._tables[index];
				newHTB._tables[index] = cur;
				cur = next;
			}
			htb->_tables[i] = NULL;
		}
		HTBDestory(htb);
		htb->_tables = newHTB._tables;
		htb->_len = newHTB._len;
		htb->_size = newHTB._size;
	}
}
int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value)
{
	int index = MyHashFunc(key, htb->_len);
	HashNode* cur = NULL;
	HashNode* newNode = NULL;
	HBTCheckCapacity(htb);
	assert(htb);
	//key是否存在
	cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return -1;
		}
		cur = cur->_next;
	}

	newNode = BuyHashNode(key,value);
	//头插
	newNode->_next = htb->_tables[index];
	htb->_tables[index] = newNode;
	htb->_size++;

	return 0;
}

int HTBRemove(HTB* htb, HTBKeyType key)
{
	int index = 0;
	HashNode* cur = NULL;
	HashNode* prev = NULL;
	assert(htb);
	index = MyHashFunc(key, htb->_len);
	cur = htb->_tables[index];

	while (cur)
	{
		if (cur->_key == key)
		{
			if (prev == NULL)
				htb->_tables[index] = cur->_next;
			else
				prev->_next = cur->_next;

			free(cur);
			htb->_size--;
			return 0;
		}
		prev = cur;
		cur = cur->_next;
	}
	return -1;
}

void HTBPrint(HTB *htb)
{
	int i = 0;
	assert(htb);
	for (i = 0; i < htb->_len; i++)
	{
		int count = 0;
		HashNode *cur = htb->_tables[i];
		printf("Table[%d]->",i);
		while (cur)
		{
			//printf("[%d:%d]->", cur->_key, cur->_value);
			cur = cur->_next;
			count++;
		}
		printf("count = %d\n",count);
		//printf("NULL\n");
	}
	printf("\n");
}

HashNode* HTBFind(HTB* htb, HTBKeyType key)
{
	int index = 0;
	HashNode* cur = NULL;
	HashNode* prev = NULL;
	assert(htb);
	index = MyHashFunc(key, htb->_len);
	cur = htb->_tables[index];

	while (cur)
	{
		if (cur->_key == key)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

int HTBSize(HTB* htb)
{
	assert(htb);
	return htb->_size;
}

//空返回1 非空返回0
int HTBEmpty(HTB* htb)
{
	assert(htb);
	return htb->_len == 0 ? 1 : 0;
}

void TestHashTableBucket()
{
	int i = 0;
	HTB htb;
	HTBInit(&htb, 10);
	HTBInsert(&htb, 106, 0);
	HTBInsert(&htb, 53, 0);
	HTBInsert(&htb, 20, 0);

	//srand(time(0));
	//for (i = 0; i < 1000; i++)
	//{
	//	HTBInsert(&htb, rand(), 0);
	//}
	HTBPrint(&htb);
	HTBRemove(&htb, 106);
	HTBPrint(&htb);
	HTBDestory(&htb);
}