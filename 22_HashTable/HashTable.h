#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HTKeyType;
typedef int HTValueType;

enum State
{
	EMPTY,	//��
	EXIITS, //����
	DELETE, //ɾ��
};

typedef struct HashData
{
	enum State		_state;
	HTKeyType	_key;
	HTValueType _value;
}HashData;

typedef struct HashTable
{
	HashData* _tables;
	int _len;   // ����
	int _size;  // ��Ч���ݸ���
}HashTable;

void HTInit(HashTable* ht, int len);
void HTDestroy(HashTable* ht);

int HTInsert(HashTable* ht, HTKeyType key, HTValueType value);
int HTRemove(HashTable* ht, HTKeyType key);
HashData* HTFind(HashTable* ht, HTKeyType key);
void HTPrint(HashTable* ht);

int HTSize(HashTable* ht);
int HTEmpty(HashTable* ht);
void TestHashTable();
