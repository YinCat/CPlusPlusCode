#include "LinkList.h"

//��ʼ��
void InitList(pList *ppl)
{
	assert(ppl != NULL);
	*ppl = NULL;
}

pNode BuyNode(DataType data)
{
	pNode newNode = NULL;
	newNode = (pNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//β������
void PushBack(pList *ppl, DataType d)
{
	pNode newNode = NULL;
	pNode pCur = NULL;
	assert(ppl != NULL);
	newNode = BuyNode(d);
	if (newNode == NULL)
	{
		printf("�ռ䲻��\n");
		return;
	}
	if (*ppl == NULL)
	{
		*ppl = newNode;
		newNode->next = NULL;
	}
	else
	{
		pCur = *ppl;
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = newNode;
		newNode->next = NULL;
	}
}

//��ӡ����
void PrintList(pList pl)
{
	pNode pCur = pl;
	if (pl == NULL){
		printf("������\n");
		return;
	}
	while (pCur)
	{
		printf("%d---->", pCur->data);
		pCur = pCur->next;
	}
	printf("Over\n");
}

//��������
void Destroy(pList *ppl)
{
	pNode tmp = NULL;
	pNode del = NULL;
	assert(ppl != NULL);
	if (*ppl == NULL){
		return;
	}
	del = *ppl;
	tmp = del->next;
	while (del != NULL)
	{
		printf("�ͷŽڵ�: %d \n", del->data);
		free(del);
		del = tmp;
		if (tmp != NULL){
			tmp = tmp->next;
		}
	}
}

//ɾ��β��Ԫ��
void PopBack(pList* pplist)
{
	pNode pCur = NULL;
	assert(pplist != NULL);
	if (*pplist == NULL){
		return;
	}
	pCur = *pplist;
	if (pCur->next == NULL){
		free(pCur);
		*pplist = NULL;
		return;
	}
	while (pCur->next->next){
		pCur = pCur->next;
	}
	free(pCur->next);
	pCur->next = NULL;
}

//ͷ������
void PushFront(pList* pplist, DataType d)
{
	pNode pCur = NULL;
	pNode newNode = NULL;
	assert(pplist != NULL);
	newNode = BuyNode(d);
	if (newNode == NULL)
	{
		printf("�洢�ռ�����\n");
		return;
	}
	//�������ʱ���ͷ������
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		pCur = *pplist;
		*pplist = newNode;
		newNode->next = pCur;
	}
}

//ͷ��ɾ��
void PopFront(pList* pplist)
{
	pNode pCur = NULL;
	assert(pplist != NULL);
	if (*pplist == NULL)
		return;
	//ֻ��һ��Ԫ�ص����
	if ((*pplist)->next == NULL){
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		pCur = (*pplist)->next;
		free(*pplist);
		*pplist = pCur;
	}
}

//���ҵ�һ�γ���ֵΪd��λ��
pNode Find(pList plist, DataType d)
{
	pNode pCur = NULL;
	if (plist == NULL)
		return NULL;
	pCur = plist;
	while (pCur)
	{
		if (pCur->data == d)
			return pCur;
		pCur = pCur->next;
	}
	//δ�ҵ�����NULL
	return NULL;
}

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d)
{
	pNode newNode = NULL;
	pNode pCur = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);

	newNode = BuyNode(pos->data);
	if (newNode == NULL)
	{
		printf("�ռ�����\n");
		return;
	}
	pCur = pos->next;
	pos->next = newNode;
	newNode->next = pCur;
	pos->data = d;
}

//ɾ��ָ��Ԫ��,ָ��λ��
void Erase(pList* pplist, pNode pos)
{
	pNode pCur = NULL;
	pNode del = NULL;
	assert(pos != NULL);
	assert(pplist != NULL);
	assert(*pplist != NULL);
	
	pCur = *pplist;
	if (pCur == pos)
	{
		//ɾ��ͷ���
		PopFront(pplist);
		return;
	}
	while (pCur)
	{
		if (pCur->next == pos)
		{
			del = pos->next;
			free(pos);
			pos = NULL;
			pCur->next = del;
			return;
		}
		pCur = pCur->next;
	}
}

//ɾ��ָ��Ԫ��,ָ��ֵ����һ�γ��֣�
void Remove(pList* pplist, DataType d)
{
	pNode pCur = NULL;
	pNode del = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);

	pCur = *pplist;
	while (pCur)
	{
		if (pCur->next->data == d)
		{
			del = pCur->next->next;
			free(pCur->next);
			pCur->next = del;
			return;
		}
		pCur = pCur->next;
	}
}

//ɾ��ָ��Ԫ��,ָ��ֵ��ɾ������ƥ���Ԫ�أ�
void RemoveAll(pList* pplist, DataType d)
{
	//Removeȥ��return����
	pNode pCur = NULL;
	pNode del = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);

	pCur = *pplist;
	while (pCur)
	{
		if (pCur->next->data == d)
		{
			del = pCur->next->next;
			free(pCur->next);
			pCur->next = del;
		}
		pCur = pCur->next;
	}
}

//����λ��ɾ����β�ڵ�
void EraseNotTailNode(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	pos->data = pos->next->data;
	del = pos->next->next;
	free(pos->next);
	pos->next = del;
}

//��ȡ������
int GetListLength(pList plist)
{
	pNode pCur = NULL;
	int len = 0;
	if (plist == NULL)
		return 0;
	pCur = plist;
	while (pCur)
	{
		len++;
		pCur = pCur->next;
	}
	return len;
}

//--------------------------------������--------------------------
//1. �����ӡ�������� 
void PrintTailToHead(pList plist)
{
	pNode pCur = NULL;
	pNode tail = NULL;
	assert(plist != NULL);

	pCur = plist;
	while (tail != plist)
	{
		while (pCur->next != tail)
		{
			pCur = pCur->next;
		}
		printf("%d ", pCur->data);
		tail = pCur;
		pCur = plist;
	}
}

//�ݹ�ķ�ʽ��ӡ
void PrintTailToHead_R(pList plist)
{
	if (plist == NULL)
		return;
	PrintTailToHead_R(plist->next);
	printf("%d ",plist->data);
}

//3. ɾ��һ����ͷ������ķ�β�ڵ� 
void EraseNotTail(pNode pos)
{
	pNode pCur = NULL;
	assert(pos != NULL);
	pCur = pos->next->next;
	pos->data = pos->next->data;
	free(pos->next);
	pos->next = pCur;
}

//4. ����ͷ�������һ���ڵ�ǰ����һ���ڵ� 
void InsertNode(pNode pos, DataType data)
{
	pNode pCur = NULL;
	pNode newNode = NULL;
	assert(pos != NULL);

	newNode = BuyNode(pos->data);
	if (newNode == NULL)
	{
		printf("�ռ䲻��\n");
		return;
	}
	pCur = pos->next;
	pos->next = newNode;
	pos->data = data;
	newNode->next = pCur;
}
//5. ������ʵ��Լɪ�� 
pNode JosephCycle(pList * pplist, int num)
{
	pNode pCur = NULL;
	pNode del = NULL;
	int count = 0;

	assert(pplist != NULL);
	assert(num >= 2);

	pCur = *pplist;

	while (pCur->next->next != pCur)
	{
		count = num;
		while (--count)
		{
			pCur = pCur->next;
		}
		EraseNotTail(pCur);
	}
	return pCur;
}

//6. ����/��ת������ 
void ReverseList(pList* pplist)
{
	pNode pCur = NULL;
	pNode tmp = NULL;
	pNode tmp2 = NULL;

	assert(pplist != NULL);
	assert(*pplist != NULL);
	//������ָ�븳ֵ
	pCur = *pplist;
	tmp = pCur->next;
	tmp2 = tmp->next;

	//ԭͷ�ڵ��ȸ�ֵΪNULL
	pCur->next = NULL;

	while (tmp2 != NULL)
	{
		//�ı�ָ��
		tmp->next = pCur;

		//3��ָ�����
		pCur = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
	}

	//ѭ��������һ���Ĵ���
	*pplist = tmp;
	tmp->next = pCur;
}

//�ݹ�д��
pNode ReverseList_R(pNode p)
{
	pNode newNode = NULL;
	if ((p == NULL) || (p->next == NULL))
		return p;

	newNode = ReverseList_R(p->next);
	p->next->next = p;
	p->next = NULL;
	return newNode;
}

//7. ����������ð������ 
void BubbleSort(pList * pplist)
{
	pNode pCur = NULL;
	pNode pnext = NULL;
	pNode tail = NULL;
	DataType tmp = 0;

	//ð�������㷨�Ż��������־λ
	int flag = 0;

	assert(pplist != NULL);
	//ֻ��һ��Ԫ�ػ����ǿ�����ʱ�򲻽�������
	if (*pplist == NULL || (*pplist)->next == NULL)
		return;

	//���ѭ��
	while (tail != (*pplist))
	{
		pCur = *pplist;
		pnext = pCur->next;
		while (pnext != tail)
		{
			if (pCur->data > pnext->data)
			{
				//������֮���޸ı�־λ
				flag = 1;
				tmp = pCur->data;
				pCur->data = pnext->data;
				pnext->data = tmp;
			}
			pCur = pnext;
			pnext = pnext->next;
		}
		//tailָ��ǰ��
		tail = pCur;

		if (flag == 0) //δ���ı��ʱ��ֱ������ѭ��
			break;
	}
}

//8. �ϲ�������������,�ϲ�����Ȼ���� 
pList Merge(pList list1, pList list2)
{
	pList newlist = NULL;
	//tail��ʾ�����β��
	pNode tail = NULL;

	//�ȿ����������
	if (list1 == list2)
		return NULL;
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	//ȷ��ͷ�ڵ�
	if (list1->data < list2->data)
	{
		newlist = list1;
		list1 = list1->next;
	}
	else{
		newlist = list2;
		list2 = list2->next;
	}

	//�����������ҽ�С��Ԫ��β��
	tail = newlist;
	while ((list1 != NULL) && (list2 != NULL))
	{
		if (list1->data < list2->data){
			tail->next = list1;
			list1 = list1->next;
		}
		else{
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	//���ߵ�����˵������һ�������Ѿ�������
	if (list1 == NULL)
	{
		tail->next = list2;
	}
	else{
		tail->next = list1;
	}
	return newlist;
}

//�ݹ�д��
pNode Merge_R(pList list1, pList list2)
{
	pList newlist = NULL;

	//�ȿ����������
	if (list1 == list2)
		return NULL;
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	//ȷ��ͷ���
	if (list1->data < list2->data)
	{
		newlist = list1;
		list1->next = Merge_R(list1->next, list2);
	}
	else
	{
		newlist = list2;
		list2->next = Merge_R(list2->next, list1);
	}
	return newlist;
}

//9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
pNode FindMidNode(pList head){
	pNode fast = head;
	pNode slow = head;
	if (head == NULL || head->next == NULL)
		return head;
	
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
pNode FindLastKNode(pList *pplist, int k)
{
	pNode first = *pplist;
	pNode catch = *pplist;
	int num = 0;

	assert(pplist != NULL);
	if (*pplist == NULL)
		return NULL;
	while (first != NULL)
	{
		first = first->next;
		if (num++ >= k)
		{
			catch = catch->next;
		}
	}
	return catch;	
}
//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ� 
//������
pNode CheckCycle(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
		return NULL;
	while ((fast != NULL) && (((fast->next) != NULL)))
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}
//�󻷵ĳ��ȣ�����Ϊ������
int GetCircleLength(pNode meet)
{

	pNode cur = NULL;
	int len = 1;

	assert(meet != NULL);
	assert(meet->next != NULL);

	cur = meet->next;

	while (cur != meet)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
//����ڵ㣬����Ϊ������
pNode GetCycleEntryNode(pList list, pNode meetNode)
{
	pList cur = list;
	if (list == NULL)
		return NULL;
	if (meetNode == NULL)
		return NULL;

	while (cur != meetNode)
	{
		cur = cur->next;
		meetNode = meetNode->next;
	}
	return cur;	
}

//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
int CheckCross(pList list1, pList list2)
{
	pNode end1 = NULL;
	pNode end2 = NULL;
	//����һ��Ϊ��ָ��Ͳ������ཻ
	if (list1 == NULL || list2 == NULL)
		return 0;
	end1 = list1;
	end2 = list2;

	while (end1->next != NULL)
		end1 = end1->next;

	while (end2->next != NULL)
		end2 = end2->next;
	
	return end1 == end2;
}
//�ཻ�Ļ����ؽ���
pNode GetGrossNode(pList list1, pList list2)
{
	int len1 = 0;
	int len2 = 0; 
	//����֮��
	int gap = 0;

	pNode p1 = list1;
	pNode p2 = list2;

	//�������������ĳ���
	while (p1 != NULL)
	{
		len1++;
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		len2++;
		p2 = p2->next;
	}
	gap = abs(len1 - len2);

	//�ýϳ�����������gap��
	if (len1 > len2){
		while (gap--)
			list1 = list1->next;
	}
	else
	{
		while (gap--)
			list2 = list2->next;
	}

	//��������ͬʱ���ߣ�ֻҪ������ַһ���Ľڵ���ô�����ཻ�ĵ�
	while (list1 != NULL)
	{
		list1 = list1->next;
		list2 = list2->next;
		if (list1 == list2)
			return list1;
	}
	return NULL;
}

//15. ����������������(�)
void UnionSet(pList list1, pList list2)
{
	if (list1 == NULL || list2 == NULL)
		return;
	while (list1 && list2)
	{
		if (list1->data < list2->data)
		{
			list1 = list1->next;
		}
		else if (list1->data > list2->data)
		{
			list2 = list2->next;
		}
		else
		{
			printf("%d ", list1->data);
			list1 = list1->next;
			list2 = list2->next;
		}
	}
}

// 14. ��������ĸ��ơ�
ComplexNode* BuyComplexNode(DataType x)
{
	ComplexNode* node = (ComplexNode*)malloc(sizeof(ComplexNode));
	assert(node);
	node->_next = NULL;
	node->_random = NULL;
	node->_data = x;
	return node;
}

//��ӡ�����������
void PrintComplexList(ComplexNode* plist)
{
	ComplexNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d:", cur->_data);
		if (cur->_random != NULL)
			printf("(%d)-->", cur->_random->_data);
		else
		{
			printf("(NULL)-->");
		}
		cur = cur->_next;
	}
	printf("Over\n");
}
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬 
//����һ��randomָ��ָ����������е�һ������ڵ����NULL�� 
//����Ҫ��ʵ�ָ�������������ظ��ƺ��������
ComplexNode* CopyList(ComplexNode* list)
{
	//1���ڵ�ǰ�ڵ�ĺ������һ����ǰ�ڵ������
	ComplexNode* cur = list;
	ComplexNode* newlist = NULL;
	ComplexNode* cp = NULL;
	ComplexNode* next = list->_next;

	assert(list != NULL);

	while (cur != NULL)
	{
		ComplexNode* newNode = BuyComplexNode(cur->_data);
		newNode->_next = next;
		cur->_next = newNode;
		cur = next;
		if (next != NULL)
			next = cur->_next;
	}
	//2����������ڵ��randomָ��
	cur = list;
	cp = cur->_next;
	while (cur != NULL)
	{
		if (cur->_random != NULL)
			cp->_random = cur->_random->_next;
		cur = cp->_next;
		if (cur != NULL)
			cp = cur->_next;
	}
	//3���������
	cur = list;
	cp = cur->_next;

	//ȷ�����������ʼλ��
	newlist = cp;

	while (cur != NULL)
	{
		cur->_next = cp->_next;
		if (cur->_next != NULL)
			cp->_next = cur->_next->_next;
		cur = cur->_next;
		cp = cp->_next;
	}

	return newlist;
}
#if 0
//LeetCode������Ŀһ
pList addTwoNumbers2(pList list1, pList list2)
{
	pList newlist = NULL;
	pNode newNode = NULL;

	int flag = 0;//�Ƿ��λ
	int sum = 0;//����data��֮��
	pNode tail = newlist;//ά��β���ָ��
	pNode cur = NULL;//Ѱ��β�ڵ�ǰһ���ڵ��ָ��
	
	//����һ������Ϊ�վ�ֱ�ӷ���NULL
	if (list1 == NULL || list2 == NULL)
		return NULL;

	while (list1 != NULL && list2 != NULL)
	{
		sum = list1->data + list2->data;
		if (flag)
			 sum++; //֮ǰ�н�λ��Ҫ��1

		//����֮���Ƿ���Ҫ��λ���ж�
		if (sum >= 10)
			flag = 1;
		else
			flag = 0;
		//�����½ڵ�
		newNode = BuyNode(sum % 10);
		//β������
		if (newlist == NULL)
		{
			newlist = newNode;
			tail = newlist;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
		//ָ��ͬʱ�����
		list1 = list1->next;
		list2 = list2->next;
	}
	
	tail->data = sum % 10;
	printf("sum = %d\n", sum);

	while (list1 != NULL && flag)
	{
			if (1 + list1->data < 10)
			{
				PushBack(&newlist, 1 + list1->data);
				tail = tail->next;
				flag = 0;
			}
			else
			{
				PushBack(&newlist, (1 + list1->data) % 10);
				tail = tail->next;
				flag = 1;
			}
		list1 = list1->next;
	}
	printf("flag = %d\n",flag);
	tail->next = list1;
	return newlist;
}
#endif
//LeetCode������Ŀһ
pList addTwoNumbers(pList list1, pList list2)
{
	pList newlist = NULL;
	pNode newNode = NULL;
	pNode tail = NULL;
	int flag = 0;//�Ƿ��λ
	//����һ������Ϊ�վ�ֱ�ӷ���NULL
	if (list1 == NULL || list2 == NULL)
		return NULL;

	while (list1 != NULL && list2 != NULL)
	{
		if ((list1->data + list2->data + flag) >= 10)
		{

			//PushBack(&newlist, (list1->data + list2->data + flag) % 10);
			newNode = (pNode)malloc(sizeof(Node));
			newNode->data = (list1->data + list2->data + flag) % 10;
			newNode->next = NULL;

			tail = newlist;
			if (newlist == NULL)
				newlist = newNode;
			else
			{
				while (tail->next)
					tail = tail->next;
				tail->next = newNode;
			}
			flag = 1;
		}
		else{
			//PushBack(&newlist, list1->data + list2->data+ flag);
			newNode = (pNode)malloc(sizeof(Node));
			newNode->data = list1->data + list2->data + flag;
			newNode->next = NULL;

			tail = newlist;
			if (newlist == NULL)
				newlist = newNode;
			else
			{
				while (tail->next)
					tail = tail->next;
				tail->next = newNode;
			}
			flag = 0;
		}
		list1 = list1->next;
		list2 = list2->next;
	}
	//if (flag)
	//{
	//	//PushBack(&newlist, 1);
	//	newNode = (pNode)malloc(sizeof(Node));
	//	newNode->data = 1;
	//	newNode->next = NULL;

	//	tail = newlist;
	//	if (newlist == NULL)
	//		newlist = newNode;
	//	else
	//	{
	//		while (tail->next)
	//			tail = tail->next;
	//		tail->next = newNode;
	//	}
	//}
		
	//��ʼ������ಿ��
	//printf("lis1t1 %d\n",list1->data);
	while (list1 != NULL)
	{
		//ʹ��ָ���ҵ������ĩβ
		tail = newlist;
		while (tail->next != NULL)
			tail = tail->next;

		//���֮ǰû�н�λ
		if (flag == 0)
		{
			tail->next = list1;
			return newlist;
		}
		//flag == 1
		if (list1->data + 1 >= 10)
		{
			PushBack(&newlist, (list1->data + 1) % 10);
			flag = 1;
		}
		else
		{
			PushBack(&newlist, list1->data + 1);
			flag = 0;
		}
		list1 = list1->next;
	}
	while (list2 != NULL)
	{
		//ʹ��ָ���ҵ������ĩβ
		tail = newlist;
		while (tail->next != NULL)
			tail = tail->next;

		//���֮ǰû�н�λ
		if (flag == 0)
		{
			tail->next = list2;
			return newlist;
		}
		//flag == 1
		if (list2->data + 1 >= 10)
		{
			PushBack(&newlist, (list2->data + 1) % 10);
			flag = 1;
		}
		else
		{
			PushBack(&newlist, list2->data + 1);
			flag = 0;
		}
		list2 = list2->next;
	}

	//���׷��
	if (flag)
	{
		//PushBack(&newlist, 1);
		newNode = (pNode)malloc(sizeof(Node));
		newNode->data = 1;
		newNode->next = NULL;

		tail = newlist;
		if (newlist == NULL)
			newlist = newNode;
		else
		{
			while (tail->next)
				tail = tail->next;
			tail->next = newNode;
		}
	}
	
	return newlist;
}