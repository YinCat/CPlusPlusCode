#include "LinkList.h"

# if 0
void test01(){
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 4);
	PrintList(plist);
	printf("len = %d\n", GetListLength(plist));
	pos = Find(plist,3);
	if (pos != NULL){
		//printf("find  = %d\n", pos->data);
		//Insert(&plist, pos, -2);//在3之前插入-2
		//PrintList(plist);
		//Erase(&plist, pos);
		//PrintList(plist);
		//RemoveAll(&plist, 4);
		EraseNotTailNode(pos);
		PrintList(plist);
	}
	else
	{
		printf("未找到\n");
	}
}

void test02()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	//PrintList(plist);
	PrintTailToHead_R(plist);
}

void test03()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	pos = Find(plist, 5);
	//EraseNotTail(pos);
	InsertNode(pos,-2);
	PrintList(plist);
}

void test04(){
	pList plist = NULL;
	pNode pos = NULL;
	int i = 0;
	InitList(&plist);
	for (i = 1; i <= 41; i++){
		PushBack(&plist, i);
	}
	//形成环
	pos = Find(plist, 41);
	pos->next = plist;

	//求出41个人中最后两名幸存者
	pos = JosephCycle(&plist, 3);
	printf("%d ", pos->data);//16
	printf("%d ", pos->next->data);//31
}

void test05()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintList(plist);
	//ReverseList_R(plist);
	PrintList(plist);

}

void test06()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 1);
	PushBack(&plist, 5);
	PushBack(&plist, 2);
	PrintList(plist);
	BubbleSort(&plist);
	PrintList(plist);
}
void fun01()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	int i = 0;
	int j = 0;
	int tmp = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	for (i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
}
void fun02()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	int *start = &arr[0];
	int *start_next = start + 1;
	int *end = &arr[4];
	int tmp = 0;
	while (&arr[0] <= end)
	{
		start = &arr[0];
		start_next = start + 1;
		while (start_next < end-1)
		{
			if (*start > *start_next)
			{
				tmp = *start;
				*start = *start_next;
				*start_next = tmp;
			}
			start++;
			start_next = start + 1;
		}
		end = start;
	}

	for (tmp = 0; tmp < 5; tmp++){
		printf("%d ", arr[tmp]);
	}
}

void test07()
{
	int i = 0;
	pNode pos = NULL;
	pList plist1 = NULL;
	pList plist2 = NULL;
	pList plist3 = NULL;
	InitList(&plist1);
	InitList(&plist2);
	for (i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
			PushBack(&plist1, i);
		else
		{
			PushBack(&plist2, i);
		}
	}
	PushBack(&plist1, 12);
	PushBack(&plist1, 13);
	PrintList(plist1);
	PrintList(plist2);

	plist3 = Merge_R(plist1, plist2);

	PrintList(plist3);
	pos =  FindMidNode(plist1);
	printf("查找结果：%d \n", pos->data);
	pos = FindLastKNode(&plist3, 5);
	printf("查找结果：%d \n", pos->data);
}

void test08()
{
	int i = 0;
	pList plist = NULL;
	pNode pos = NULL;
	pNode entrance = NULL;
	InitList(&plist);
	for (i = 1; i <= 5; i++)
	{
		PushBack(&plist, i);
	}
	
	//带环
	Find(plist, 5)->next = Find(plist, 3);

	pos = CheckCycle(plist);
	if (pos != NULL){
		printf("带环，相遇点为 = %d\n", pos->data);
		printf("环的长度是：%d\n", GetCircleLength(pos));
		entrance = GetCycleEntryNode(plist, pos);
		printf("环的入口点是：%d\n", entrance->data);
	}
	else
	{
		printf("不带环\n");
	}
}

void test09()
{
	int i = 0;
	pNode pos = NULL;
	pList plist1 = NULL;
	pList plist2 = NULL;
	InitList(&plist1);
	InitList(&plist2);
	for (i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
			PushBack(&plist1, i);
		else
		{
			PushBack(&plist2, i);
		}
	}
	//PrintList(plist1);
	//PrintList(plist2);
	Find(plist1, 10)->next = Find(plist2, 5);
	PrintList(plist1);
	PrintList(plist2);
	if (CheckCross(plist1, plist2))
	{
		printf("相交\n");
		//求交点
		pos = GetGrossNode(plist1, plist2);
		printf("交点:%d\n", pos->data);
	}
	else
	{
		printf("不相交\n");
	}
}
void test10()
{
	int i = 0;
	pNode pos = NULL;
	pList plist1 = NULL;
	pList plist2 = NULL;
	InitList(&plist1);
	InitList(&plist2);
	for (i = 0; i <= 5; i++)
	{
		PushBack(&plist1, i+1);
		PushBack(&plist2, i-1);
	}
	PrintList(plist1);
	PrintList(plist2);
	UnionSet(plist1, plist2);
}

void test11()
{
	ComplexNode* plist  = NULL;
	ComplexNode* newlist = NULL;

	ComplexNode* p1 = BuyComplexNode(5);
	ComplexNode* p2 = BuyComplexNode(4);
	ComplexNode* p3 = BuyComplexNode(3);
	ComplexNode* p4 = BuyComplexNode(2);
	ComplexNode* p5 = BuyComplexNode(1);
	plist = p1;
	p1->_next = p2;
	p2->_next = p3;
	p3->_next = p4;
	p4->_next = p5;
	p5->_next = NULL;

	p1->_random = p3;
	p2->_random = p1;
	p3->_random = NULL;
	p4->_random = p2;
	p5->_random = p4;

	printf("原表：");
	PrintComplexList(plist);
	newlist = CopyList(plist);

	printf("新表：");
	PrintComplexList(newlist);
	printf("原表：");
	PrintComplexList(plist);
}

# endif
void test12()
{
	pList plist1 = NULL;
	pList plist2 = NULL;
	pList newlist = NULL;

	pNode pos = NULL;

	InitList(&plist1);
	InitList(&plist2);

	//PushBack(&plist1, 2);
	//PushBack(&plist1, 4);
	//PushBack(&plist1, 3);
	//PushBack(&plist1, 5);

	PushBack(&plist1, 5);
	PushBack(&plist2, 5);
	//PushBack(&plist2, 9);

	//PushBack(&plist1, 9);
	//PushBack(&plist2, 1);
	//PushBack(&plist2, 8);

	//PushBack(&plist1, 1);
	//PushBack(&plist1, 8);
	//PushBack(&plist2, 0);

	//PushBack(&plist1, 9);
	//PushBack(&plist1, 8);
	//PushBack(&plist2, 1);

	PrintList(plist1);
	PrintList(plist2);
	newlist = addTwoNumbers(plist1, plist2);
	PrintList(newlist);
}
int main(){

	test12();
	
	system("pause");
	return 0;
}