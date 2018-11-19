#include "LinkList.h"


void test01()
{
	pList plist = NULL;
	InitList(&plist);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	PopFront(&plist);
	PrintList(plist);
	Destroy(&plist);
}

void test02()
{
	pList plist = NULL;
	InitList(&plist);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PrintList(plist);
	PushFront(&plist,5);
	PushFront(&plist,6);
	PushFront(&plist,7);
	PrintList(plist);//7 6 5 1 2 3 4
	PopFront(&plist);
	PopFront(&plist);
	PopFront(&plist);
	PrintList(plist);
	Destroy(&plist);
}

void test03()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PrintList(plist);
	//查找3并在他的前面插入0
	pos = Find(plist,3);
	if(pos != NULL)
	{
		printf("ret = %d\n",pos->data);
	}
	else
	{
		printf("未找到\n");
	}
	Insert(&plist,pos,0);
	PrintList(plist);
	Destroy(&plist);
}

void test04()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PrintList(plist);

	pos = Find(plist,4);
	Erase(&plist,pos);
	PrintList(plist);
	Destroy(&plist);
}

void test05()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PrintList(plist);

	Remove(&plist,1);
	PrintList(plist);
	Destroy(&plist);
}

void test06()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PrintList(plist);

	RemoveAll(&plist,1);
	PrintList(plist);
	RemoveAll(&plist,4);
	PrintList(plist);
	Destroy(&plist);
}

void test07()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);
	PrintList(plist);

	pos = Find(plist,1);//记住只能传递非尾节点
	EraseNotTailNode(pos);
	PrintList(plist);
	printf("链表长度：%d\n",GetListLength(plist));
	Destroy(&plist);
}

int main()
{
	test07();
	system("pause");
	return 0;
}