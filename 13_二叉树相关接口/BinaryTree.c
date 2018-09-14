#include "BinaryTree.h"

//获取新节点
static pBTNode BuyBTNode(BTDataType x)
{
	pBTNode newNode = (pBTNode)malloc(sizeof(BTNode));
	assert(newNode != NULL);

	newNode->_left = NULL;
	newNode->_right = NULL;
	newNode->_data = x;

	return newNode;
}

// 创建二叉树 
pBTNode BinaryTreeCreate(BTDataType* a, int n, int *pi)
{
	assert(a != NULL);
	if ('#' != a[*pi] && (*pi)<n)//这里还要要求数组的下标是合法的
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

//前序遍历的规则：
//（1）访问根节点
//（2）前序遍历左子树
//（3）前序遍历右子树
void BinaryTreePrevOrder(pBTNode root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//中序遍历的规则：
//（1）中序遍历左子树
//（2）访问根节点
//（3）中序遍历右子树
void BinaryTreeInOrder(pBTNode root)
{
	if (root->_left != NULL)
		BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	if (root->_right != NULL)
		BinaryTreeInOrder(root->_right);
}

//后序遍历的规则:
//（1）后序遍历左子树
//（2）后序遍历右子树
//（3）访问根节点
void BinaryTreePostOrder(pBTNode root)
{
	if (root->_left != NULL)
		BinaryTreePostOrder(root->_left);
	if (root->_right != NULL)
		BinaryTreePostOrder(root->_right);
	printf("%c ",root->_data);
}

//返回节点个数
size_t BTreeSize(pBTNode root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->_left) + BTreeSize(root->_right) +1;
}

//返回叶子节点的个数
size_t BTreeLeafSize(pBTNode root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BTreeLeafSize(root->_left) + BTreeLeafSize(root->_right);
}

//返回第K层节点个数
size_t BTreeKLevelSize(pBTNode root, size_t k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return k;
	return BTreeKLevelSize(root->_left, k - 1) + BTreeKLevelSize(root->_right, k - 1);
}

//返回树的深度
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

//返回值为x的节点地址
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

//层序遍历，需要使用队列
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

// 判断完全二叉树 ，是就返回1，不是返回0
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

// 前序遍历-非递归遍历 
void BTreePrevOrderNonR(pBTNode root)
{
	pBTNode cur = root;
	pBTNode top = NULL;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		//访问左路节点，左路节点进栈
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//栈里面出来节点，表示左树已经访问过
		top = StackTop(&s);
		StackPop(&s);
		//子问题访问右树
		cur = top->_right;
	}
	printf("\n");
	StackDestory(&s);
}
//中序遍历-非递归遍历
void BTreeInOrderNonR(pBTNode root)
{
	pBTNode cur = root;
	pBTNode top = NULL;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		//访问左路节点，左路节点进栈
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//栈里面出来节点，表示左树已经访问过
		top = StackTop(&s);
		StackPop(&s);
		printf("%c ", top->_data);
		//子问题访问右树
		cur = top->_right;
	}
	printf("\n");
	StackDestory(&s);
}
//后序遍历-非递归遍历
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

//销毁函数
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

//求镜像
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
	
	printf("树的深度为:%d\n", BTreeDepth(root));
	printf("查找测试：%c\n", BTreeFind(root, 'E')->_data);
	printf("树的节点个数：%d\n",BTreeSize(root));
	printf("树的叶子节点个数：%d\n", BTreeLeafSize(root));
	printf("树的第3层节点个数：%d\n", BTreeKLevelSize(root, 3));
	printf("层序遍历：");
	BTreeLevelOrder(root);//层序遍历


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
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");

	//求二叉树的镜像
	GetMirror_R(root);
	BinaryTreePrevOrder(root);
	printf("\n");
	GetMirror(root);
	BinaryTreePrevOrder(root);
	printf("\n");




	BinaryTreeDestory(&root);
}
