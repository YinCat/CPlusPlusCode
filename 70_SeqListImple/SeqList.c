#include "SeqList.h"

//初始化 
void InitSeqList(PSeqList pSeq)
{
	assert(pSeq != NULL);
	memset(pSeq->data,0,sizeof(pSeq->data));
	pSeq->sz = 0;
}

//尾部插入
void PushBack(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	if(pSeq->sz == MAX)
	{
		printf("表满，无法插入\n");
		return;
	}
	pSeq->data[pSeq->sz] = data;
	pSeq->sz++;
}

//打印
void PrintSeqList(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0){
		printf("空表，无法打印\n");
		return;
	}
	for(i=0;i<pSeq->sz;i++)
	{
		printf("%d ",pSeq->data[i]);
	}
	printf("\n");
}

//尾部删除
void PopBack(PSeqList pSeq)
{
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("空表，无法删除\n");
		return;
	}
	pSeq->sz--;
}

//头部插入
void PushFront(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == MAX)
	{
		printf("表满，无法插入\n");
		return;
	}
	for(i = pSeq->sz;i>=0;i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[0] = data;
	pSeq->sz++;
}

//头部删除 
void PopFront(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("表空，无法删除\n");
	}
	for(i = 0;i<pSeq->sz-1;i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;
}

//查找指定元素，返回索引
int Find(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	for(i=0;i<pSeq->sz;i++)
	{
		if(data == pSeq->data[i])
		{
			return i;
		}
	}
	return -1;
}
//指定位置插入 
void Insert(PSeqList pSeq, int pos, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == MAX)
	{
		printf("表满，无法插入\n");
	}
	for(i = pSeq->sz;i>pos;i--)
	{
		pSeq->data[i] = pSeq->data[i-1]; 
	}
	pSeq->data[pos] = data;
	pSeq->sz++;
}

//删除指定位置元素 
void Erase(PSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos>=0 && pos<pSeq->sz);
	if(pSeq->sz == 0)
	{
		printf("空表，无法删除\n");
	}
	for(i = pos;i<pSeq->sz-1;i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;
}

//删除指定元素 
void Remove(PSeqList pSeq, DataType data)
{
	int pos = 0;
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("空表，无法删除\n");
	}
	pos = Find(pSeq,data);
	for(i=pos;i<pSeq->sz-1;i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;
}

//删除所有的指定元素 
void RemoveAll(PSeqList pSeq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("空表，无法删除\n");
	}
	for(i=0 ;i<pSeq->sz;i++)
	{
		if(pSeq->data[i] != data)
		{
			pSeq->data[j++] = pSeq->data[i];
		}
	}
	pSeq->sz = j;
}

//返回顺序表的大小 
int Size(PSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

//判断顺序表是否为空 
int Empty(PSeqList pSeq){
	assert(pSeq != NULL);
	return pSeq->sz == 0;
}
static void swap(DataType *d1,DataType *d2)
{
	DataType tmp = *d2;
	*d2 = *d1;
	*d1 = tmp;
}
//冒泡排序 
void BubbleSort(PSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	for(i=0;i<pSeq->sz;i++)
	{
		int flag = 0;
		for(j=0;j<pSeq->sz-i-1;j++)
		{
			if(pSeq->data[j]>pSeq->data[j+1])
			{
				flag = 1;
				swap(pSeq->data+j,pSeq->data+j+1);
			}
		}
		//说明已经有序，无需再排序
		if(flag == 0)
		{
			return;
		}
	}
}

//选择排序 
void SelectSort(PSeqList pSeq)
{
	int i = 0; 
	int j = 0;
	assert(pSeq != NULL);
	for( i = 0; i<pSeq->sz;i++)
	{
		for( j = i ; j<pSeq->sz;j++)
		{
			if(pSeq->data[i]>pSeq->data[j])
			{
				swap(pSeq->data+i,pSeq->data+j);
			}
		}
	}
}

//选择排序的优化 
void SelectSortOP(PSeqList pSeq)
{
	int start = 0;
	int end = pSeq->sz-1;
	assert(pSeq != NULL);
	while(start<end)
	{
		int max = start;
		int min = start;
		int i = 0;
		for(i = start;i<=end;i++)
		{
			if(pSeq->data[i]>pSeq->data[max])
			{
				max = i;
			}
			if(pSeq->data[i]<pSeq->data[min])
			{
				min = i;
			}
		}
		if(min != start)
		{
			swap(pSeq->data+start,pSeq->data+min);
		}
		if(max == start)
		{
			max = min;
		}
		if(max != end)
		{
			swap(pSeq->data+max,pSeq->data+end);
		}
		start++;
		end--;
	}
}

//二分查找 
int BinarySearch(PSeqList pSeq, DataType data)
{
	int left = 0;
	int right = pSeq->sz-1;
	assert(pSeq != NULL);
	
	while(left<=right)
	{
		int mind = left+(right-left)/2;
		if(pSeq->data[mind]>data)
		{
			right = mind-1;
		}
		else if(pSeq->data[mind]<data)
		{
			left = mind+1;
		}
		else
		{
			return mind;
		}
	}
	return -1;
}

//二分查找递归写法 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d)
{
	int mind = left+(right-left)/1;
	if(left>right)
	{
		return -1;
	}
	if(pSeq->data[ mind]>d)
	{
		return BinarySearch_R(pSeq,left,mind-1,d);
	}
	else if(pSeq->data[mind]<d)
	{
		return BinarySearch_R(pSeq,mind+1,right,d);
	}
	else
	{
		return mind;
	}
}