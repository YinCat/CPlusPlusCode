# ifndef __LINKLIST_H__
#define __LINKLIST_H__
//����ͷ�ڵ��ʵ�ַ�ʽ
#include <xpu.h>

typedef int DataType;

typedef struct Node{
	DataType data;
	struct Node *next; 
}Node,*pNode,List,*pList;

//��ʼ��
void InitList(pList *ppl);

//β������
void PushBack(pList *ppl,DataType d);

//��ӡ����
void PrintList( pList pl);

//��������
void Destroy(pList *ppl);

//ͷ������
void PushFront(pList *ppl,DataType d);

//ͷ��ɾ��
void PopFront(pList *ppl);

//���Һ���
pNode Find(pList plist, DataType d);

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d); 

//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos); 

//ɾ����һ��ֵΪd�Ľڵ�
void Remove(pList* pplist, DataType d); 

//ɾ������ֵΪd�Ľڵ�
void RemoveAll(pList* pplist, DataType d); 

//���ݵ�ַɾ����β�ڵ㣨�滻ɾ������
void EraseNotTailNode(pNode pos); 

//�������ĳ���
int GetListLength(pList plist); 
#endif //__LINKLIST_H__