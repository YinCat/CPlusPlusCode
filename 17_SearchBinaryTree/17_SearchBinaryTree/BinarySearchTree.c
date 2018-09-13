#include "BinarySearchTree.h"

static BSTreeNode* BuyNode(BSTDataType x)
{
	BSTreeNode* ret = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (ret == NULL)
	{
		perror("BSTreeInsert::BuyNode");
		return NULL;
	}
	ret->_data = x;
	ret->_left = NULL;
	ret->_right = NULL;

	return ret;
}
int BSTreeInsert(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode* cur = *tree;
	BSTreeNode* parent = NULL;
	assert(tree);
	if (*tree == NULL)
	{
		*tree = BuyNode(x);
		return 1;
	}

	while (cur)
	{
		if (x < cur->_data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (x > cur->_data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			return 0;
	}
	if (x < parent->_data)
		parent->_left = BuyNode(x);
	else
		parent->_right = BuyNode(x);
	return 1;
}

int BSTreeRemove(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode *cur = *tree;
	BSTreeNode *parent = NULL;
	assert(tree);
	if (*tree == NULL)
		return 0;
	while (cur)
	{
		if (x < cur->_data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (x>cur->_data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			//表示找到了该节点
			//1、左为空、右为空
			//2、左右都不为空
			if (cur->_left == NULL)
			{
				//有可能存在父节点为空的情况
				if (parent == NULL)
				{
					*tree = cur->_right;
				}
				else
				{
					if (cur == parent->_left)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
			}
			else if (cur->_right == NULL)
			{
				if (parent == NULL)
					*tree = cur->_left;
				else
				{
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
			}
			else //左右都不为空
			{
				BSTreeNode *replace = cur->_right;

				while (replace->_left)
					replace = replace->_left;

				cur->_data = replace->_data;
				return BSTreeRemove(&cur->_right, replace->_data);
			}
			free(cur);
			return 1;
		}
	}
	return 0;
}

BSTreeNode* BSTreeFind(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode *cur = *tree;
	assert(tree);
	if (*tree == NULL)
		return NULL;
	while (cur)
	{
		if (x < cur->_data)
			cur = cur->_left;
		else if (x > cur->_data)
			cur = cur->_right;
		return cur;
	}
	return NULL;
}


int BSTreeInsert_R(BSTreeNode** tree, BSTDataType x)
{
	if (*tree == NULL)
	{
		*tree = BuyNode(x);
		return 1;
	}

	if (x < (*tree)->_data)
		return BSTreeInsert_R(&(*tree)->_left, x);
	else if (x >(*tree)->_data)
		return BSTreeInsert_R(&(*tree)->_right, x);
	else
		return 0;
}
int BSTreeRemove_R(BSTreeNode** tree, BSTDataType x)
{
	if (*tree == NULL)
		return 0;
	if (x < ((*tree)->_data))
		return BSTreeRemove_R(&((*tree)->_left), x);
	else if (x >((*tree)->_data))
		return BSTreeRemove_R(&((*tree)->_right), x);
	else
	{
		BSTreeNode *del = *tree;
		if ((*tree)->_left == NULL)
		{
			*tree = (*tree)->_right;
			free(del);
		}
		else if ((*tree)->_right == NULL)
		{
			*tree = (*tree)->_left;
			free(del);
		}
		else
		{
			BSTreeNode *replace = (*tree)->_right;
			while (replace->_left)
			{
				replace = replace->_left;
			}
			(*tree)->_data = replace->_data;
			return BSTreeRemove_R(&(*tree)->_right, replace->_data);
		}
	}
	return 1;
}

BSTreeNode* BSTreeFind_R(BSTreeNode** tree, BSTDataType x)
{
	if (*tree == NULL)
		return NULL;
	if (x < (*tree)->_data)
		return BSTreeFind_R(&(*tree)->_left, x);
	else if (x>(*tree)->_data) 
		return BSTreeFind_R(&(*tree)->_right, x);
	else
		return *tree;
}

//中序遍历二叉搜索树
void BSTreeInOrder(BSTreeNode** tree)
{
	BSTreeNode* cur = *tree;
	assert(tree);
	if (cur == NULL)
		return;
	if (cur->_left != NULL)
		BSTreeInOrder(&(cur->_left));
	printf("%d ",cur->_data);
	if (cur->_right != NULL)
		BSTreeInOrder(&(cur->_right));
}



void TestBSTree()
{
	BSTreeNode  *tree = NULL;
	int i = 0;
	int a[] = {5,3,4,1,7,8,2,6,0,9};
	for (i = 0; i < sizeof(a)/sizeof(int); ++i)
	{	
		//BSTreeInsert(&tree, a[i]);
		BSTreeInsert_R(&tree, a[i]);
	}
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 8);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 9);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 0);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove_R(&tree, 2);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove_R(&tree, 5);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 6);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove_R(&tree, 3);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 4);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 7);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 1);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 1);
	BSTreeInOrder(&tree);
	printf("\n");
}