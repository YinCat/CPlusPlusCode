#include "SeqList.h"

//��ʼ��
void InitSeqList(PSeqList pSeq)
{
	assert(pSeq != NULL);
	pSeq->capacity = DEFAULT_SZ;
	pSeq->sz = 0;
	pSeq->data = (DataType*)malloc(sizeof(DataType)*DEFAULT_SZ);
	if(pSeq->data == NULL)
	{
		perror("use InitSeqList::malloc ");
		exit(EXIT_FAILURE);
	}
}
//���ݵķ���
void CheckCapacity(PSeqList pSeq)
{
	assert(pSeq != NULL);
	if(pSeq->sz == pSeq->capacity)
	{
		DataType *tmp = (DataType*)realloc(pSeq->data,sizeof(pSeq->data)+sizeof(DataType)*DEFAULT_SZ);
		if(tmp == NULL)
		{
			perror("CheckCapacity::realloc ");
		}
		else
		{
			pSeq->data = tmp;	
		}
	}
}

//β������ 
void PushBack(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	CheckCapacity(pSeq);
	pSeq->data[pSeq->sz] = data;
	pSeq->sz++;
}

//��ӡ 
void PrintSeqList(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("�ձ�\n");
		return;
	}
	for(i = 0; i<pSeq->sz;i++)
	{
		printf("%d ",pSeq->data[i]);
	}
	printf("\n");
}

//β��ɾ�� 
void PopBack(PSeqList pSeq)
{
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("�ձ�,�޷�ɾ��\n");
		return; 
	}
	pSeq->sz--;
}

//ͷ������ 
void PushFront(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	CheckCapacity(pSeq);
	for(i = pSeq->sz;i>=0;i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[0] = data;
	pSeq->sz++;
}

//ͷ��ɾ�� 
void PopFront(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("�ձ��޷�ɾ��\n");
		return;
	}
	for(i = 0;i<pSeq->sz-1;i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;
}

//����ָ��Ԫ�� 
int Find(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	for(i = 0;i<pSeq->sz;i++)
	{
		if(pSeq->data[i] == data)
		{
			return i;
		}
	}
	return -1;
}

//ָ��λ�ò��� 
void Insert(PSeqList pSeq, int pos, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos >= 0 && pos<pSeq->sz);
	CheckCapacity(pSeq);
	for(i=pSeq->sz;i>pos;i--)
	{
		pSeq->data[i] = pSeq->data[i-1];
	}
	pSeq->data[pos] = data;
	pSeq->sz++;
}

//ɾ��ָ��λ��Ԫ�� 
void Erase(PSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("�ձ��޷�ɾ��\n");
		return;
	}
	for(i = pos;i<pSeq->sz-1;i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;

}

//ɾ��ָ��Ԫ�� 
void Remove(PSeqList pSeq, DataType data)
{
	int pos = 0;
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("�ձ��޷�ɾ��\n");
	}
	pos = Find(pSeq,data);
	for(i=pos;i<pSeq->sz-1;i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->sz--;
}

//ɾ�����е�ָ��Ԫ�� 
void RemoveAll(PSeqList pSeq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("�ձ��޷�ɾ��\n");
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

//����˳���Ĵ�С 
int Size(PSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

//�ж�˳����Ƿ�Ϊ�� 
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
//ð������ 
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
		//˵���Ѿ���������������
		if(flag == 0)
		{
			return;
		}
	}
}

//ѡ������ 
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

//ѡ��������Ż� 
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

//���ֲ��� 
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

//���ֲ��ҵݹ�д�� 
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