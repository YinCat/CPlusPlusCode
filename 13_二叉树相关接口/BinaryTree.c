#include "BinaryTree.h"

//��ȡ�½ڵ�
static pBTNode BuyBTNode(BTDataType x)
{
	pBTNode newNode = (pBTNode)malloc(sizeof(BTNode));
	assert(newNode != NULL);

	newNode->_left = NULL;
	newNode->_right = NULL;
	newNode->_data = x;

	return newNode;
}

// ���������� 
pBTNode BinaryTreeCreate(BTDataType* a, int n, int *pi)
{
	assert(a != NULL);
	if ('#' != a[*pi] && (*pi)<n)//���ﻹҪҪ��������±��ǺϷ���
	{
		pBTNode root = BuyBTNode(a[*pi]);
		(*pi)++;
		root->_left = BinaryTreeCreate(a, n, pi);

		(*pi)++; 
		root->_right = BinaryTreeCreate(a, n, pi);

		return root;
	}
	else
		return NULL;
}

//ǰ������Ĺ���
//��1�����ʸ��ڵ�
//��2��ǰ�����������
//��3��ǰ�����������
void BinaryTreePrevOrder(pBTNode root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//��������Ĺ���
//��1���������������
//��2�����ʸ��ڵ�
//��3���������������
void BinaryTreeInOrder(pBTNode root)
{
	if (root->_left != NULL)
		BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	if (root->_right != NULL)
		BinaryTreeInOrder(root->_right);
}

//��������Ĺ���:
//��1���������������
//��2���������������
//��3�����ʸ��ڵ�
void BinaryTreePostOrder(pBTNode root)
{
	if (root->_left != NULL)
		BinaryTreePostOrder(root->_left);
	if (root->_right != NULL)
		BinaryTreePostOrder(root->_right);
	printf("%c ",root->_data);
}

//���ؽڵ����
size_t BTreeSize(pBTNode root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->_left) + BTreeSize(root->_right) +1;
}

//����Ҷ�ӽڵ�ĸ���
size_t BTreeLeafSize(pBTNode root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BTreeLeafSize(root->_left) + BTreeLeafSize(root->_right);
}

//���ص�K��ڵ����
size_t BTreeKLevelSize(pBTNode root, size_t k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return k;
	return BTreeKLevelSize(root->_left, k - 1) + BTreeKLevelSize(root->_right, k - 1);
}

//�����������
size_t BTreeDepth(pBTNode root)
{
	int leftDeph = 0;
	int rightDeph = 0;
	if (root == NULL)
		return 0;
	leftDeph = BTreeDepth(root->_left)+1;
	rightDeph = BTreeDepth(root->_right)+1;

	return leftDeph > rightDeph ? leftDeph : rightDeph;
}

//����ֵΪx�Ľڵ��ַ
pBTNode BTreeFind(pBTNode root, BTDataType x)
{
	pBTNode ret = NULL;
	if (root == NULL||root->_data == x)
		return root;
	ret = BTreeFind(root->_left, x);
	if (ret != NULL)
		return ret;
	return BTreeFind(root->_right, x);
}

//�����������Ҫʹ�ö���
void BTreeLevelOrder(pBTNode root)
{
	Queue qu;
	QueueInit(&qu);
	if (root != NULL)
		QueuePush(&qu, root);
	while (QueueEmpty(&qu) != 0)
	{
		DataType ret = QueueFront(&qu);

		printf("%c ", ret->_data);
		QueuePop(&qu);
		if (ret->_left != NULL)
			QueuePush(&qu, ret->_left);
		if (ret->_right != NULL)
			QueuePush(&qu, ret->_right);
	}
	printf("\n");
	QueueDestory(&qu);
}

// �ж���ȫ������ ���Ǿͷ���1�����Ƿ���0
int IsCompleteBTree(pBTNode root)
{
	Queue qu;
	QueueInit(&qu);
	if (root != NULL)
		QueuePush(&qu, root);
	while (QueueEmpty(&qu) != 0)
	{
		DataType ret = QueueFront(&qu);
		QueuePop(&qu);
		if (ret != NULL)
		{
			QueuePush(&qu, ret->_left);
			QueuePush(&qu, ret->_right);
		}
		else
			break;
	}

	while (QueueEmpty(&qu) != 0)
	{
		DataType ret = QueueFront(&qu);
		if (ret != NULL)
			return 0;
		else
			QueuePop(&qu);
	}
	//QueueDestory(&qu);
	return 1;
}

// ǰ�����-�ǵݹ���� 
void BTreePrevOrderNonR(pBTNode root)
{
	pBTNode cur = root;
	pBTNode top = NULL;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		//������·�ڵ㣬��·�ڵ��ջ
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//ջ��������ڵ㣬��ʾ�����Ѿ����ʹ�
		top = StackTop(&s);
		StackPop(&s);
		//�������������
		cur = top->_right;
	}
	printf("\n");
	StackDestory(&s);
}
//�������-�ǵݹ����
void BTreeInOrderNonR(pBTNode root)
{
	pBTNode cur = root;
	pBTNode top = NULL;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		//������·�ڵ㣬��·�ڵ��ջ
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//ջ��������ڵ㣬��ʾ�����Ѿ����ʹ�
		top = StackTop(&s);
		StackPop(&s);
		printf("%c ", top->_data);
		//�������������
		cur = top->_right;
	}
	printf("\n");
	StackDestory(&s);
}
//�������-�ǵݹ����
void BTreePostOrderNonR(pBTNode root)
{
	pBTNode cur = root;
	pBTNode top = NULL;
	pBTNode prev = NULL;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur != NULL)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->_right;
		}
	}
}
void BTreePostOrderNonR_02(pBTNode root)
{
	pBTNode cur = root;
	pBTNode top = NULL;
	pBTNode prev = NULL;
	Stack s;
	StackInit(&s);
	StackPush(&s,root);
	while (StackEmpty(&s) != 0)
	{
		cur = StackTop(&s);
		if ((cur->_left == NULL && cur->_right == NULL) ||
			(prev != NULL && (prev == cur->_left || prev == cur->_right)))
		{
			printf("%c ", cur->_data);
			prev = cur;
			cur = StackTop(&s);
			StackPop(&s);
		}
		else
		{
			if (cur->_right != NULL)
				StackPush(&s, cur->_right);
			if (cur->_left != NULL)
				StackPush(&s, cur->_left);
		}
	}
	printf("\n");
	StackDestory(&s);
}

//���ٺ���
void BinaryTreeDestory(pBTNode* proot)
{
	if (proot == NULL || *proot == NULL)
		return;
	if ((*proot)->_left != NULL)
		BinaryTreeDestory(&((*proot)->_left));
	if ((*proot)->_right != NULL)
		BinaryTreeDestory(&((*proot)->_right));
	free(*proot);
	*proot = NULL;
}

//����
void GetMirror_R(pBTNode root)
{
	pBTNode tmp = NULL;
	if (root == NULL)
		return;
	GetMirror(root->_left);
	GetMirror(root->_right);
	tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
}

void GetMirror(pBTNode root)
{
	pBTNode tmp = NULL;
	Queue qu;
	QueueInit(&qu);
	if (root != NULL)
		QueuePush(&qu, root);
	while (QueueEmpty(&qu) != 0)
	{
		DataType ret = QueueFront(&qu);

		QueuePop(&qu);
		if (ret->_left != NULL)
			QueuePush(&qu, ret->_left);
		if (ret->_right != NULL)
			QueuePush(&qu, ret->_right);
		tmp = ret->_left;
		ret->_left = ret->_right;
		ret->_right = tmp;

	}
}

void TestBinaryTree()
{
	char arr[] = { 'A','B','#','C','#','#','D','E','#','F','#','G','#','#','H','#','#' };
	int len = sizeof(arr) / sizeof(arr[0]);
	pBTNode root;
	int i = 0;
	root = BinaryTreeCreate(arr, len, &i);
	
	printf("�������Ϊ:%d\n", BTreeDepth(root));
	printf("���Ҳ��ԣ�%c\n", BTreeFind(root, 'E')->_data);
	printf("���Ľڵ������%d\n",BTreeSize(root));
	printf("����Ҷ�ӽڵ������%d\n", BTreeLeafSize(root));
	printf("���ĵ�3��ڵ������%d\n", BTreeKLevelSize(root, 3));
	printf("���������");
	BTreeLevelOrder(root);//�������


	BinaryTreePrevOrder(root);
	printf("\n");
	BTreePrevOrderNonR(root);

	BinaryTreeInOrder(root);
	printf("\n");
	BTreeInOrderNonR(root);

	BinaryTreePostOrder(root);
	printf("\n");
	BTreePostOrderNonR(root);
	printf("\n");
	BTreePostOrderNonR_02(root);

	if (IsCompleteBTree(root))
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");

	//��������ľ���
	GetMirror_R(root);
	BinaryTreePrevOrder(root);
	printf("\n");
	GetMirror(root);
	BinaryTreePrevOrder(root);
	printf("\n");




	BinaryTreeDestory(&root);
}
