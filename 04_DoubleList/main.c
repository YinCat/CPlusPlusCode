#include "doublelist.h"

void test()
{
	pNode pos = NULL;
	pNode list = NULL;
	list = InitList();
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PrintList(list);
	PushFront(&list, 6);
	PrintList(list);
	PopBack(&list);
	PrintList(list);
	PopFront(&list);
	PrintList(list);
	pos = Find(list, 4);
	printf("²éÕÒ½á¹û£º%d\n", pos->data);
	Insert(pos, -1);
	PrintList(list);
	printf("--------------------------------\n");
	pos = Find(list, 4);
	Erase(pos);
	PrintList(list);
	DestoryList(&list);
}

int main()
{
	test();
	system("pause");
	return 0;
}