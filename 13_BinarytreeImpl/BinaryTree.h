#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "queue.h"
#include "Stack.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType _data;
}BTNode, *pBTNode;

// 创建二叉树 
pBTNode BinaryTreeCreate(BTDataType* a, int n, int* pi);

void BinaryTreePrevOrder(pBTNode root);//前序遍历
void BinaryTreeInOrder(pBTNode root);//中序遍历
void BinaryTreePostOrder(pBTNode root);//后序遍历

//返回节点个数
size_t BTreeSize(pBTNode root);

//返回叶子节点的个数
size_t BTreeLeafSize(pBTNode root);

//返回第K层节点个数
size_t BTreeKLevelSize(pBTNode root, size_t k);

//返回树的深度
size_t BTreeDepth(pBTNode root);

//返回值为x的节点地址
pBTNode BTreeFind(pBTNode root, BTDataType x);

//层序遍历，需要使用队列
void BTreeLevelOrder(pBTNode root);

// 判断完全二叉树 
int IsCompleteBTree(pBTNode root);
int IsCompleteBTree1(pBTNode root);

// 非递归遍历 
void BTreePrevOrderNonR(pBTNode root);//前序遍历
void BTreeInOrderNonR(pBTNode root);//中序遍历
void BTreePostOrderNonR(pBTNode root);//后序遍历方式一
void BTreePostOrderNonR_02(pBTNode root);//后序遍历方式二

//销毁函数
void BinaryTreeDestory(pBTNode* proot);

//求镜像
void GetMirror_R(pBTNode root);
void GetMirror(pBTNode root);

//测试函数
void TestBinaryTree();

#endif // !__BINARY_TREE_H__
