#ifndef __BST_KEY_H__
#define __BST_KEY_H__

#if 0
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int BSTKeyType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTKeyType _key;
}BSTreeNode;

int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType x);
int BSTreeRemove(BSTreeNode** ppTree, BSTKeyType x);
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType x);

void BSTreeInOrder(BSTreeNode** ppTree);
void TestBSTree();


#endif

#endif //!__BST_KEY_H__