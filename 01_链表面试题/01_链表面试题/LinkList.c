#include "LinkList.h"

//初始化
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

//尾部插入
void PushBack(pList *ppl, DataType d)
{
	pNode newNode = NULL;
	pNode pCur = NULL;
	assert(ppl != NULL);
	newNode = BuyNode(d);
	if (newNode == NULL)
	{
		printf("空间不足\n");
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

//打印链表
void PrintList(pList pl)
{
	pNode pCur = pl;
	if (pl == NULL){
		printf("空链表\n");
		return;
	}
	while (pCur)
	{
		printf("%d---->", pCur->data);
		pCur = pCur->next;
	}
	printf("Over\n");
}

//销毁链表
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
		printf("释放节点: %d \n", del->data);
		free(del);
		del = tmp;
		if (tmp != NULL){
			tmp = tmp->next;
		}
	}
}

//删除尾部元素
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

//头部插入
void PushFront(pList* pplist, DataType d)
{
	pNode pCur = NULL;
	pNode newNode = NULL;
	assert(pplist != NULL);
	newNode = BuyNode(d);
	if (newNode == NULL)
	{
		printf("存储空间已满\n");
		return;
	}
	//空链表的时候的头部插入
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

//头部删除
void PopFront(pList* pplist)
{
	pNode pCur = NULL;
	assert(pplist != NULL);
	if (*pplist == NULL)
		return;
	//只有一个元素的情况
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

//查找第一次出现值为d的位置
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
	//未找到返回NULL
	return NULL;
}

//在指定位置之前插入一个值 
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
		printf("空间已满\n");
		return;
	}
	pCur = pos->next;
	pos->next = newNode;
	newNode->next = pCur;
	pos->data = d;
}

//删除指定元素,指定位置
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
		//删除头结点
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

//删除指定元素,指定值（第一次出现）
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

//删除指定元素,指定值（删除所有匹配的元素）
void RemoveAll(pList* pplist, DataType d)
{
	//Remove去掉return即可
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

//根据位置删除非尾节点
void EraseNotTailNode(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	pos->data = pos->next->data;
	del = pos->next->next;
	free(pos->next);
	pos->next = del;
}

//获取链表长度
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

//--------------------------------面试题--------------------------
//1. 逆序打印单向链表 
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

//递归的方式打印
void PrintTailToHead_R(pList plist)
{
	if (plist == NULL)
		return;
	PrintTailToHead_R(plist->next);
	printf("%d ",plist->data);
}

//3. 删除一个无头单链表的非尾节点 
void EraseNotTail(pNode pos)
{
	pNode pCur = NULL;
	assert(pos != NULL);
	pCur = pos->next->next;
	pos->data = pos->next->data;
	free(pos->next);
	pos->next = pCur;
}

//4. 在无头单链表的一个节点前插入一个节点 
void InsertNode(pNode pos, DataType data)
{
	pNode pCur = NULL;
	pNode newNode = NULL;
	assert(pos != NULL);

	newNode = BuyNode(pos->data);
	if (newNode == NULL)
	{
		printf("空间不足\n");
		return;
	}
	pCur = pos->next;
	pos->next = newNode;
	pos->data = data;
	newNode->next = pCur;
}
//5. 单链表实现约瑟夫环 
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

//6. 逆置/反转单链表 
void ReverseList(pList* pplist)
{
	pNode pCur = NULL;
	pNode tmp = NULL;
	pNode tmp2 = NULL;

	assert(pplist != NULL);
	assert(*pplist != NULL);
	//将三个指针赋值
	pCur = *pplist;
	tmp = pCur->next;
	tmp2 = tmp->next;

	//原头节点先赋值为NULL
	pCur->next = NULL;

	while (tmp2 != NULL)
	{
		//改变指向
		tmp->next = pCur;

		//3个指针后移
		pCur = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
	}

	//循环完毕最后一步的处理
	*pplist = tmp;
	tmp->next = pCur;
}

//递归写法
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

//7. 单链表排序（冒泡排序） 
void BubbleSort(pList * pplist)
{
	pNode pCur = NULL;
	pNode pnext = NULL;
	pNode tail = NULL;
	DataType tmp = 0;

	//冒泡排序算法优化，定义标志位
	int flag = 0;

	assert(pplist != NULL);
	//只有一个元素或者是空链表时候不进行排序
	if (*pplist == NULL || (*pplist)->next == NULL)
		return;

	//外层循环
	while (tail != (*pplist))
	{
		pCur = *pplist;
		pnext = pCur->next;
		while (pnext != tail)
		{
			if (pCur->data > pnext->data)
			{
				//交换了之后修改标志位
				flag = 1;
				tmp = pCur->data;
				pCur->data = pnext->data;
				pnext->data = tmp;
			}
			pCur = pnext;
			pnext = pnext->next;
		}
		//tail指针前移
		tail = pCur;

		if (flag == 0) //未经改变的时候直接跳出循环
			break;
	}
}

//8. 合并两个有序链表,合并后依然有序 
pList Merge(pList list1, pList list2)
{
	pList newlist = NULL;
	//tail表示链表的尾部
	pNode tail = NULL;

	//先考虑特殊情况
	if (list1 == list2)
		return NULL;
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	//确定头节点
	if (list1->data < list2->data)
	{
		newlist = list1;
		list1 = list1->next;
	}
	else{
		newlist = list2;
		list2 = list2->next;
	}

	//两条链表中找较小的元素尾插
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
	//能走到这里说明其中一条链表已经结束了
	if (list1 == NULL)
	{
		tail->next = list2;
	}
	else{
		tail->next = list1;
	}
	return newlist;
}

//递归写法
pNode Merge_R(pList list1, pList list2)
{
	pList newlist = NULL;

	//先考虑特殊情况
	if (list1 == list2)
		return NULL;
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	//确定头结点
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

//9. 查找单链表的中间节点，要求只能遍历一次链表 
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

//10. 查找单链表的倒数第k个节点，要求只能遍历一次链表 
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
//11. 判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。 
//相遇点
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
//求环的长度，参数为相遇点
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
//求入口点，参数为相遇点
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

//12. 判断两个链表是否相交，若相交，求交点。（假设链表不带环） 
int CheckCross(pList list1, pList list2)
{
	pNode end1 = NULL;
	pNode end2 = NULL;
	//任意一个为空指针就不可能相交
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
//相交的话返回交点
pNode GetGrossNode(pList list1, pList list2)
{
	int len1 = 0;
	int len2 = 0; 
	//长度之差
	int gap = 0;

	pNode p1 = list1;
	pNode p2 = list2;

	//先求出两条链表的长度
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

	//让较长的链表先走gap步
	if (len1 > len2){
		while (gap--)
			list1 = list1->next;
	}
	else
	{
		while (gap--)
			list2 = list2->next;
	}

	//两个链表同时开走，只要遇到地址一样的节点那么就是相交的点
	while (list1 != NULL)
	{
		list1 = list1->next;
		list2 = list2->next;
		if (list1 == list2)
			return list1;
	}
	return NULL;
}

//15. 求两个有序单链表交集(差集)
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

// 14. 复杂链表的复制。
ComplexNode* BuyComplexNode(DataType x)
{
	ComplexNode* node = (ComplexNode*)malloc(sizeof(ComplexNode));
	assert(node);
	node->_next = NULL;
	node->_random = NULL;
	node->_data = x;
	return node;
}

//打印这个复杂链表
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
//一个链表的每个节点，有一个指向next指针指向下一个节点， 
//还有一个random指针指向这个链表中的一个随机节点或者NULL， 
//现在要求实现复制这个链表，返回复制后的新链表。
ComplexNode* CopyList(ComplexNode* list)
{
	//1、在当前节点的后面插入一个当前节点的数据
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
	//2、调整插入节点的random指针
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
	//3、拆除链表
	cur = list;
	cp = cur->_next;

	//确定新链表的起始位置
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
//LeetCode链表题目一
pList addTwoNumbers2(pList list1, pList list2)
{
	pList newlist = NULL;
	pNode newNode = NULL;

	int flag = 0;//是否进位
	int sum = 0;//两个data域之和
	pNode tail = newlist;//维护尾插的指针
	pNode cur = NULL;//寻找尾节点前一个节点的指针
	
	//其中一条链表为空就直接返回NULL
	if (list1 == NULL || list2 == NULL)
		return NULL;

	while (list1 != NULL && list2 != NULL)
	{
		sum = list1->data + list2->data;
		if (flag)
			 sum++; //之前有进位则还要加1

		//加了之后是否还需要进位的判断
		if (sum >= 10)
			flag = 1;
		else
			flag = 0;
		//申请新节点
		newNode = BuyNode(sum % 10);
		//尾部插入
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
		//指针同时向后走
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
//LeetCode链表题目一
pList addTwoNumbers(pList list1, pList list2)
{
	pList newlist = NULL;
	pNode newNode = NULL;
	pNode tail = NULL;
	int flag = 0;//是否进位
	//其中一条链表为空就直接返回NULL
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
		
	//开始处理多余部分
	//printf("lis1t1 %d\n",list1->data);
	while (list1 != NULL)
	{
		//使用指针找到链表的末尾
		tail = newlist;
		while (tail->next != NULL)
			tail = tail->next;

		//如果之前没有进位
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
		//使用指针找到链表的末尾
		tail = newlist;
		while (tail->next != NULL)
			tail = tail->next;

		//如果之前没有进位
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

	//最后追加
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