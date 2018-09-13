#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef char* BSTKeyType;
typedef char* BSTValueType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTKeyType _key;
	BSTValueType _value;

}BSTreeNode;

int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value);
int BSTreeRemove(BSTreeNode** ppTree, BSTKeyType key);
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key);

BSTreeNode* BSTreeDictFind(BSTreeNode** ppTree, BSTKeyType key);

void BSTreeInOrder(BSTreeNode** ppTree);
