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

// ���������� 
pBTNode BinaryTreeCreate(BTDataType* a, int n, int* pi);

void BinaryTreePrevOrder(pBTNode root);//ǰ�����
void BinaryTreeInOrder(pBTNode root);//�������
void BinaryTreePostOrder(pBTNode root);//�������

//���ؽڵ����
size_t BTreeSize(pBTNode root);

//����Ҷ�ӽڵ�ĸ���
size_t BTreeLeafSize(pBTNode root);

//���ص�K��ڵ����
size_t BTreeKLevelSize(pBTNode root, size_t k);

//�����������
size_t BTreeDepth(pBTNode root);

//����ֵΪx�Ľڵ��ַ
pBTNode BTreeFind(pBTNode root, BTDataType x);

//�����������Ҫʹ�ö���
void BTreeLevelOrder(pBTNode root);

// �ж���ȫ������ 
int IsCompleteBTree(pBTNode root);
int IsCompleteBTree1(pBTNode root);

// �ǵݹ���� 
void BTreePrevOrderNonR(pBTNode root);//ǰ�����
void BTreeInOrderNonR(pBTNode root);//�������
void BTreePostOrderNonR(pBTNode root);//���������ʽһ
void BTreePostOrderNonR_02(pBTNode root);//���������ʽ��

//���ٺ���
void BinaryTreeDestory(pBTNode* proot);

//����
void GetMirror_R(pBTNode root);
void GetMirror(pBTNode root);

//���Ժ���
void TestBinaryTree();

#endif // !__BINARY_TREE_H__
