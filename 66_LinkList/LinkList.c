#include "LinkList.h"

//初始化
void InitList(pList *ppl)
{
	assert(ppl != NULL);
	*ppl = NULL;
}

//产生新节点
pNode BuyNode(DataType d)
{
	pNode tmp =(pNode)malloc(sizeof(Node));
	if(tmp == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	tmp->data = d;
	tmp->next = NULL;
	return tmp;
}

//尾部插入
void PushBack(pList *ppl,DataType d)
{
	pNode newNode = BuyNode(d);
	assert(ppl != NULL);
	if(newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if(*ppl == NULL) //这是一个空链表
	{
		*ppl = newNode;
	}
	else
	{
		//一直向后走
		pNode cur = *ppl;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//打印链表
void PrintList(pList pl)
{
	pNode cur = pl;
	while(cur != NULL)
	{
		printf("%d-->",cur->data);
		cur = cur->next;
	}
	printf("Over\n");
}

//销毁的函数
void Destroy(pList *ppl)
{
	pNode cur = *ppl;
	assert(ppl != NULL);
	while(cur != NULL)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
}

//头部删除
void PopFront(pList *ppl)
{
	pNode del = NULL;
	assert(ppl != NULL);
	if((*ppl) == NULL){
		return;
	}
	del = *ppl;
	*ppl = (*ppl)->next;
	free(del);
	del = NULL;
}

//头部插入
void PushFront(pList *ppl,DataType d)
{
	pNode newNode = NULL;
	assert(ppl != NULL);
	newNode = BuyNode(d);
	newNode->next = *ppl;
	*ppl = newNode;
}

//查找,返回该节点的地址
pNode Find(pList plist, DataType d)
{
	pNode cur = NULL;
	assert(plist != NULL);
	cur = plist;
	while(cur)
	{
		if(cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在指定位置之前插入一个值 
void Insert(pList* pplist, pNode pos, DataType d)
{
	pNode cur = NULL;
	pNode newNode = NULL;

	assert(pplist != NULL);//检查指针有效性
	assert(*pplist != NULL);//确保这不是空链表

	cur = *pplist;
	newNode = BuyNode(d);
	if(pos == cur)//
	{
		//插在头部位置
		newNode->next = *pplist;
		*pplist = newNode;
	}
	else
	{
		//插在中间位置
		while(cur)
		{
			if((cur->next) == pos)
			{
				newNode->next = cur->next;
				cur->next = newNode;
				return;
			}
			cur = cur->next;
		}
	}
}

//指定位置删除 
void Erase(pList* pplist, pNode pos)
{
	pNode del = NULL;
	pNode cur = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);

	
	//删除第一个节点
	if(pos == *pplist)
	{
		*pplist = pos->next;
		free(pos);
		pos = NULL;
		return;
	}
	
	//删除非第一个节点
	cur = *pplist;
	while(cur)
	{
		if(cur->next == pos)
		{
			del = cur->next;
			cur->next = del->next;
			free(del);
			del = NULL;
			return 0;
		}
		cur = cur->next;
	}
}

//删除第一个值为d的节点
void Remove(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode del = NULL;
	assert(pplist);
	assert(*pplist);
	
	cur = *pplist;
	if(cur->data == d)
	{
		del = *pplist;
		*pplist = cur->next;
		free(del);
		del = NULL;
		return;
	}

	while(cur)
	{
		if(cur->next->data == d)
		{
			del = cur->next;
			cur->next = del->next;
			free(del);
			del = NULL;
			return;
		}
		cur = cur->next;
	}
}

//删除所有值为d节点
void RemoveAll(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode del = NULL;
	assert(pplist);
	assert(*pplist);

	cur = *pplist;
	del = cur->next;
	
	if(((*pplist)->data) == d)
	{
		del = *pplist;
		*pplist = cur->next;
		free(del);
		del = NULL;
	}

	cur = *pplist;
	while(cur && cur->next)
	{	
		if((cur->next->data) == d)
		{
			del = cur->next;
			cur->next = del->next;
			free(del);
			del = NULL;
		}
		cur = cur->next;
	}	
}

//根据地址删除非尾节点（替换删除法）
void EraseNotTailNode(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	pos->data = pos->next->data;//先把数据复制到pos节点里面
	del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//得到链表长度
int GetListLength(pList plist)
{
	pNode cur = plist;
	int count = 0;
	while(cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}