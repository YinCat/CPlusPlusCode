#include "HashTable.h"



void HTInit(HashTable* ht, int len)
{
	int i = 0;;
	assert(ht);
	assert(len > 0);
	ht->_tables = (HashData*)malloc(sizeof(HashData)*len);
	ht->_size = 0;
	ht->_len = len;
	for (i = 0; i < len; i++)
	{
		ht->_tables[i]._state = EMPTY;
	}
}
void HTDestroy(HashTable* ht)
{
	assert(ht);
	//释放空指针是不会出错的
	free(ht->_tables);
	ht->_tables = NULL;
	ht->_len = 0;
	ht->_size = 0;
}

size_t HashFunc(HashTable *ht, HTKeyType key)
{
	assert(ht);
	return key % (ht->_len);
}

//需要前置函数申明
int HTInsert(HashTable* ht, HTKeyType key, HTValueType value);
void CheckCapatity(HashTable *ht)
{
	if (ht->_size * 10 / ht->_len > 7)
	{
		HashTable newht;
		int i = 0;
		HTInit(&newht, ht->_len * 2);
		for (i = 0; i < ht->_len; i++)
		{
			if (ht->_tables[i]._state == EXIITS)
				HTInsert(&newht, ht->_tables[i]._key, ht->_tables[i]._value);
		}
		HTDestroy(ht);
		ht->_tables = newht._tables;
		ht->_size = newht._size;
		ht->_len = newht._len;
	}
}

int HTInsert(HashTable* ht, HTKeyType key, HTValueType value)
{
	size_t index = 0;;
	assert(ht);
	index = HashFunc(ht, key);
	CheckCapatity(ht);
	while (ht->_tables[index]._state == EXIITS)
	{
		if (ht->_tables[index]._key == key)
			return 0;
		return index;
	}
	ht->_tables[index]._state = EXIITS;
	ht->_tables[index]._key = key;
	ht->_tables[index]._value = value;

	ht->_size++;
	return 1;
}

HashData* HTFind(HashTable* ht, HTKeyType key)
{
	int index = HashFunc(ht, key);
	while (ht->_tables[index]._state == EXIITS)
	{
		if (ht->_tables[index]._key == key)//存在
			return &(ht->_tables[index]);
		index++;
	}
	return NULL;
}

int HTSize(HashTable* ht)
{
	assert(ht);
	return ht->_size;
}
int HTEmpty(HashTable* ht)
{
	assert(ht);
	return ht->_len == 0 ? 0 : 1;
}
void HTPrint(HashTable* ht)
{
	int index = 0;
	assert(ht);
	for (index = 0; index < ht->_len; index++)
	{
		if(ht->_tables[index]._state == EXIITS)
			printf("[%d,%d]->",ht->_tables[index]._key,ht->_tables[index]._value);
		else
			printf("[ ]->");
	}
	printf("END\n");
}
int HTRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);
	HashData* ret = HTFind(ht, key);
	ret->_state = DELETE;
	ht->_size--;
	return 0;
}
void TestHashTable()
{
	HashTable ht;
	HTInit(&ht, 10);
	HTInsert(&ht, 1, 0);
	HTInsert(&ht, 2, 0);
	HTInsert(&ht, 3, 0);
	HTInsert(&ht, 4, 0);
	HTInsert(&ht, 5, 0);

	HTInsert(&ht, 7, 0);
	HTInsert(&ht, 9, 0);

	HTPrint(&ht);
	HTRemove(&ht, 7);
	HTPrint(&ht);
}