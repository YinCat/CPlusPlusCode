#include "BST_key.h"
#include "BST_KeyValue.h"

//ͳ�Ƶ���/IP��ַ����
void MyStatistics()
{
	BSTreeNode* pTree = NULL;
	BSTreeNode* node = NULL;
	FILE* in = fopen("my.txt", "r");
	char buf[15] = { 0 };
	int index = 0;
	char ch = 0;
	int flag = 1;
	if (in == NULL)
	{
		printf("Open File Filed!!!\n");
		system("pause");
	}

	while ((ch = getc(in)) != EOF)
	{
		if (ch == ' ' || ch == ',' || ch == '.' || ch == '\n')
		{
			if (flag == 0) //��ֹ�����ظ��ո�����
				continue;
			flag = 0;
			node = BSTreeFind(&pTree, buf);
			if (node != NULL)
				node->_value++;
			else
				BSTreeInsert(&pTree, buf, 1);
			//�±����
			memset(buf, 0, 15);
			index = 0;
		}
		else
		{
			flag = 1;
			buf[index++] = ch;
		}
	}
	BSTreeInOrder(&pTree);
}

int main()
{
	//TestBSTree();
	//TestBSTree2();
	system("pause");
	return 0;
}