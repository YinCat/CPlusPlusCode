#include "doublelist.h"

pNode BuyNode(DataType data)
{
	pNode ptr = (pNode)malloc(sizeof(Node));
	if (ptr == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	ptr->data = data;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}

pNode InitList()
{
	DataType d = 0;
	pNode head = NULL;
	head = BuyNode(d);
	head->next = head;
	head->prev = head;
	return head;
}

void PushBack(pNode* plist, DataType data)
{
	pNode head = *plist;
	pNode tail = head->prev;
	pNode newNode = BuyNode(data);
	tail->next = newNode;
	newNode->prev = tail;

	newNode->next = head;
	head->prev = newNode;
}
void PrintList(pNode list)
{
	pNode cur = list->next;
	while (cur != list)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("Over\n");
}

void PushFront(pNode* plist, DataType x)
{
	PushBack(&(*plist)->next, x);
}

void PopBack(pNode* plist)
{
	pNode cur = NULL;
	assert(plist);
	cur = (*plist)->prev->prev;
	free((*plist)->prev);
	cur->next = *plist;
	(*plist)->prev = cur;
}

void PopFront(pNode* plist)
{
	pNode nextNode = (*plist)->next;
	pNode prevNode = (*plist)->prev;
	free(*plist);
	*plist = nextNode;
	nextNode->prev = prevNode;
	prevNode->next = nextNode;
}

pNode Find(pNode list, DataType x)
{
	assert(list != NULL);
	pNode cur = list->next;
	while (cur != list)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void Insert(pNode pos, DataType x)
{
	pNode nextNode = pos->next;
	pNode newNode = BuyNode(pos->data);
	pos->next = newNode;
	newNode->next = nextNode;
	nextNode->prev = newNode;
	newNode->prev = pos;
	pos->data = x;
}

void Erase(pNode pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

int ListSize(pNode list)
{

}

void DestoryList(pNode* plist)
{
	pNode del = NULL;
	pNode cur = NULL;
	assert(plist);
	if (*plist == NULL)
		return;
	del = (*plist)->next;
	while (del != (*plist))
	{
		cur = del->next;
		free(del);
		del = cur;
	}
	*plist = NULL;
}