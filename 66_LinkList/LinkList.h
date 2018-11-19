# ifndef __LINKLIST_H__
#define __LINKLIST_H__
//不带头节点的实现方式
#include <xpu.h>

typedef int DataType;

typedef struct Node{
	DataType data;
	struct Node *next; 
}Node,*pNode,List,*pList;

//初始化
void InitList(pList *ppl);

//尾部插入
void PushBack(pList *ppl,DataType d);

//打印链表
void PrintList( pList pl);

//销毁链表
void Destroy(pList *ppl);

//头部插入
void PushFront(pList *ppl,DataType d);

//头部删除
void PopFront(pList *ppl);

//查找函数
pNode Find(pList plist, DataType d);

//在指定位置之前插入一个值 
void Insert(pList* pplist, pNode pos, DataType d); 

//指定位置删除 
void Erase(pList* pplist, pNode pos); 

//删除第一个值为d的节点
void Remove(pList* pplist, DataType d); 

//删除所有值为d的节点
void RemoveAll(pList* pplist, DataType d); 

//根据地址删除非尾节点（替换删除法）
void EraseNotTailNode(pNode pos); 

//获得链表的长度
int GetListLength(pList plist); 
#endif //__LINKLIST_H__