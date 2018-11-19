#include "LinkList.h"

//��ʼ��
void InitList(pList *ppl)
{
	assert(ppl != NULL);
	*ppl = NULL;
}

//�����½ڵ�
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

//β������
void PushBack(pList *ppl,DataType d)
{
	pNode newNode = BuyNode(d);
	assert(ppl != NULL);
	if(newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if(*ppl == NULL) //����һ��������
	{
		*ppl = newNode;
	}
	else
	{
		//һֱ�����
		pNode cur = *ppl;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//��ӡ����
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

//���ٵĺ���
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

//ͷ��ɾ��
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

//ͷ������
void PushFront(pList *ppl,DataType d)
{
	pNode newNode = NULL;
	assert(ppl != NULL);
	newNode = BuyNode(d);
	newNode->next = *ppl;
	*ppl = newNode;
}

//����,���ظýڵ�ĵ�ַ
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

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d)
{
	pNode cur = NULL;
	pNode newNode = NULL;

	assert(pplist != NULL);//���ָ����Ч��
	assert(*pplist != NULL);//ȷ���ⲻ�ǿ�����

	cur = *pplist;
	newNode = BuyNode(d);
	if(pos == cur)//
	{
		//����ͷ��λ��
		newNode->next = *pplist;
		*pplist = newNode;
	}
	else
	{
		//�����м�λ��
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

//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos)
{
	pNode del = NULL;
	pNode cur = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);

	
	//ɾ����һ���ڵ�
	if(pos == *pplist)
	{
		*pplist = pos->next;
		free(pos);
		pos = NULL;
		return;
	}
	
	//ɾ���ǵ�һ���ڵ�
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

//ɾ����һ��ֵΪd�Ľڵ�
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

//ɾ������ֵΪd�ڵ�
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

//���ݵ�ַɾ����β�ڵ㣨�滻ɾ������
void EraseNotTailNode(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	pos->data = pos->next->data;//�Ȱ����ݸ��Ƶ�pos�ڵ�����
	del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//�õ�������
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