#include "BST_KeyValue.h"

void InitMyDict(BSTreeNode **pdict)
{
	assert(pdict);
	BSTreeInsert(pdict, "China", "�й�");
	BSTreeInsert(pdict, "USA", "����");
	BSTreeInsert(pdict, "UK", "Ӣ��");
	BSTreeInsert(pdict, "Russia", "����˹");
}
InitMyDict_zh(BSTreeNode **pdict_zh)
{
	assert(pdict_zh);
	BSTreeInsert(pdict_zh, "�й�", "China" );
	BSTreeInsert(pdict_zh, "����", "USA");
	BSTreeInsert(pdict_zh, "Ӣ��", "UK");
	BSTreeInsert(pdict_zh, "����˹", "Russia");
}
int main()
{
	int i= 0;
	char buf[20] = { 0 };
	BSTreeNode *mydict = NULL;
	BSTreeNode *mydict_zh = NULL;
	BSTreeNode *ret = NULL;
	InitMyDict(&mydict);
	InitMyDict_zh(&mydict_zh);
	BSTreeInOrder(&mydict);

	printf("������Ҫ��ѯ�ĵ���(Please input what's your find word)>\n");
	scanf("%s",buf);
	printf("����������(����:0  Ӣ��:1)\n");
	scanf("%d", &i);

	if (i == 0)
	{
		ret = BSTreeFind(&mydict_zh, buf);
		if (ret != NULL)
			printf("%s\n", ret->_value);
		else
			printf("�ʿ���û�������!\n");
	}
	else
	{
		ret = BSTreeFind(&mydict, buf);
		if (ret != NULL)
			printf("%s\n", ret->_value);
		else
			printf("There is no word in the vocabulary!\n");
	}



	system("pause");
}