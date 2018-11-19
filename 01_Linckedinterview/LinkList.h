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

//��ʼ��
void InitList(pList *ppl);

//β������
void PushBack(pList *ppl, DataType d);

//��ӡ����
void PrintList(pList pl);

//��������
void Destroy(pList *ppl);

//ɾ��β��Ԫ��
void PopBack(pList* pplist);

//ͷ������
void PushFront(pList* pplist, DataType d);

//ͷ��ɾ��
void PopFront(pList* pplist);

//���ҵ�һ�γ���ֵΪd��λ��
pNode Find(pList plist, DataType d);

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d);

//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos);

//ɾ��ָ��Ԫ��,ָ��ֵ����һ�γ��֣�
void Remove(pList* pplist, DataType d);

//ɾ��ָ��Ԫ��,ָ��ֵ��ɾ������ƥ���Ԫ�أ�
void RemoveAll(pList* pplist, DataType d);

//����λ��ɾ����β�ڵ�Ԫ��
void EraseNotTailNode(pNode pos);

//��ȡ������
int GetListLength(pList plist);

//1. �����ӡ�������� 
void PrintTailToHead(pList plist);
void PrintTailToHead_R(pList plist);

//3. ɾ��һ����ͷ������ķ�β�ڵ� 
void EraseNotTail(pNode pos);

//4. ����ͷ�������һ���ڵ�ǰ����һ���ڵ� 
void InsertNode(pNode pos, DataType data);

//5. ������ʵ��Լɪ�� 
pNode JosephCycle(pList * pplist, int num);

//6. ����/��ת������ 
void ReverseList(pList* pplist);
pNode ReverseList_R(pNode p);

//7. ����������ð������ 
void BubbleSort(pList * pplist);

//8. �ϲ�������������,�ϲ�����Ȼ���� 
pNode Merge(pList list1, pList list2);
pNode Merge_R(pList list1, pList list2);

//9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
pNode FindMidNode(pList head);

//10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
pNode FindLastKNode(pList *pplist, int k);

//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ� 
pNode CheckCycle(pList plist);//���ؽ����
int GetCircleLength(pNode meet);//���س���
pNode GetCycleEntryNode(pList list, pNode meetNode);//����ڵ�

//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
int CheckCross(pList list1, pList list2);//�ཻ����1
pNode GetGrossNode(pList list1, pList list2);
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 

//15. ����������������(�)�� 
void UnionSet(pList list1, pList list2);

// 14. ��������ĸ��ơ�
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬 
//����һ��randomָ��ָ����������е�һ������ڵ����NULL�� 
//����Ҫ��ʵ�ָ�������������ظ��ƺ�������� 
typedef struct ComplexNode
{
	DataType _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode;

//�����½ڵ�
ComplexNode* BuyComplexNode(DataType x);

//��ӡ�˸�������
void PrintComplexList(ComplexNode* plist);

//���Ƹ�������
ComplexNode* CopyList(ComplexNode* list);

//LeetCode������Ŀһ
pList addTwoNumbers(pList list1, pList list2);

#endif //__LINKLIST_H__