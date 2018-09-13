#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

typedef int BSTDataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTDataType _data;
}BSTreeNode;

int BSTreeInsert(BSTreeNode** tree, BSTDataType x);
int BSTreeRemove(BSTreeNode** tree, BSTDataType x);
BSTreeNode* BSTreeFind(BSTreeNode** tree, BSTDataType x);

int BSTreeInsert_R(BSTreeNode** tree, BSTDataType x);
int BSTreeRemove_R(BSTreeNode** tree, BSTDataType x);
BSTreeNode* BSTreeFind_R(BSTreeNode** tree, BSTDataType x);

void BSTreeInOrder(BSTreeNode** tree);

void TestBSTree();
