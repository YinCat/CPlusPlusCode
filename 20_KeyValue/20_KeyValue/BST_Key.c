#include "BST_Key.h"
#if 0
static BSTreeNode* BuyNode(BSTKeyType x)
{
	BSTreeNode* newNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (newNode == NULL)
		perror("BuyNode::malloc");

	newNode->_key = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}
int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType x)
{
	BSTreeNode *cur = *ppTree;
	BSTreeNode *parent = NULL;
	assert(ppTree);
	if (*ppTree == NULL)
	{
		*ppTree = BuyNode(x);
		return 1;
	}
	while (cur)
	{
		if (x < cur->_key)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (x > cur->_key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			return 0;
	}
	if (x < parent->_key)
		parent->_left = BuyNode(x);
	else
		parent->_right = BuyNode(x);
	return 1;
}
int BSTreeRemove(BSTreeNode** ppTree, BSTKeyType x)
{
	BSTreeNode *cur = *ppTree;
	BSTreeNode *parent = NULL;
	assert(ppTree);
	while (cur)
	{
		if (x < cur->_key)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (x>cur->_key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			if (cur->_left == NULL)
			{
				if (parent == NULL)
					*ppTree = cur->_right;
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
					*ppTree = cur->_left;
				else
				{
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
			}
			else
			{
				BSTreeNode *replace = cur->_right;
				while (replace->_left)
					replace = replace->_left;
				cur->_key = replace->_key;
				return BSTreeRemove(&cur->_right, replace->_key);
			}
			free(cur);
			return 1;
		}

	}
	return 0;
}
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType x)
{
	BSTreeNode *cur = *ppTree;
	assert(*ppTree);
	while (cur)
	{
		if (x < cur->_key)
			cur = cur->_left;
		else if (x > cur->_key)
			cur = cur->_right;
		else
			return cur;
	}
	return NULL;
}


void BSTreeInOrder(BSTreeNode** ppTree)
{
	assert(ppTree);
	if (*ppTree == NULL)
		return;
	BSTreeInOrder(&(*ppTree)->_left);
	printf("%d ",(*ppTree)->_key);
	BSTreeInOrder(&(*ppTree)->_right);
}

void TestBSTree()
{
	int i = 0;
	BSTreeNode* ptree = NULL;
	int a[] = {5,3,4,1,7,8,2,6,0,9};
	for ( i = 0; i < sizeof(a)/sizeof(int); ++i)
	{	
		BSTreeInsert(&ptree, a[i]);
	}
	BSTreeInOrder(&ptree);
	printf("\n");


	BSTreeRemove(&ptree, 1);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 2);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 3);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 4);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 5);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 6);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 7);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 8);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 9);
	BSTreeInOrder(&ptree);
	printf("\n");

	BSTreeRemove(&ptree, 0);
	BSTreeInOrder(&ptree);
	printf("\n");


	BSTreeInOrder(&ptree);
	printf("\n");
}

#endif