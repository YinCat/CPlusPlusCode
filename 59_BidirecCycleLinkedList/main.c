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
	printf("%d\n", pos->data);
	Insert(pos, -1);
	PrintList(list);
	printf("--------------------------------\n");
	pos = Find(list, 4);
	Erase(pos);
	PrintList(list);
	printf("长度为：%d\n",ListSize(list));
	if(ListEmpty(list))
	    printf("非空\n");
    DestroyList(&list);
}

int main()
{
	test();
	return 0;
}