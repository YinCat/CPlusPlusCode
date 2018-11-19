#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

typedef int DataType;

typedef struct Node{
	DataType data;
	struct Node *next;
}Node, *pNode, List, *pList;

//初始化
void InitList(pList *ppl);

//尾部插入
void PushBack(pList *ppl, DataType d);

//打印链表
void PrintList(pList pl);

//销毁链表
void Destroy(pList *ppl);

//删除尾部元素
void PopBack(pList* pplist);

//头部插入
void PushFront(pList* pplist, DataType d);

//头部删除
void PopFront(pList* pplist);

//查找第一次出现值为d的位置
pNode Find(pList plist, DataType d);

//在指定位置之前插入一个值 
void Insert(pList* pplist, pNode pos, DataType d);

//指定位置删除 
void Erase(pList* pplist, pNode pos);

//删除指定元素,指定值（第一次出现）
void Remove(pList* pplist, DataType d);

//删除指定元素,指定值（删除所有匹配的元素）
void RemoveAll(pList* pplist, DataType d);

//根据位置删除非尾节点元素
void EraseNotTailNode(pNode pos);

//获取链表长度
int GetListLength(pList plist);

//1. 逆序打印单项链表 
void PrintTailToHead(pList plist);
void PrintTailToHead_R(pList plist);

//3. 删除一个无头单链表的非尾节点 
void EraseNotTail(pNode pos);

//4. 在无头单链表的一个节点前插入一个节点 
void InsertNode(pNode pos, DataType data);

//5. 单链表实现约瑟夫环 
pNode JosephCycle(pList * pplist, int num);

//6. 逆置/反转单链表 
void ReverseList(pList* pplist);
pNode ReverseList_R(pNode p);

//7. 单链表排序（冒泡排序） 
void BubbleSort(pList * pplist);

//8. 合并两个有序链表,合并后依然有序 
pNode Merge(pList list1, pList list2);
pNode Merge_R(pList list1, pList list2);

//9. 查找单链表的中间节点，要求只能遍历一次链表 
pNode FindMidNode(pList head);

//10. 查找单链表的倒数第k个节点，要求只能遍历一次链表 
pNode FindLastKNode(pList *pplist, int k);

//11. 判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。 
pNode CheckCycle(pList plist);//返回交汇点
int GetCircleLength(pNode meet);//返回长度
pNode GetCycleEntryNode(pList list, pNode meetNode);//求入口点

//12. 判断两个链表是否相交，若相交，求交点。（假设链表不带环） 
int CheckCross(pList list1, pList list2);//相交返回1
pNode GetGrossNode(pList list1, pList list2);
//13. 判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 

//15. 求两个有序单链表交集(差集)。 
void UnionSet(pList list1, pList list2);

// 14. 复杂链表的复制。
//一个链表的每个节点，有一个指向next指针指向下一个节点， 
//还有一个random指针指向这个链表中的一个随机节点或者NULL， 
//现在要求实现复制这个链表，返回复制后的新链表。 
typedef struct ComplexNode
{
	DataType _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode;

//产生新节点
ComplexNode* BuyComplexNode(DataType x);

//打印此复杂链表
void PrintComplexList(ComplexNode* plist);

//复制复杂链表
ComplexNode* CopyList(ComplexNode* list);

//LeetCode链表题目一
pList addTwoNumbers(pList list1, pList list2);

#endif //__LINKLIST_H__