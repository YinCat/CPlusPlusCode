#include "Heap.h"

void Swap(HPDataType *x1, HPDataType *x2){
	HPDataType tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

//向下调整
void AdjustDown(HPDataType *arr, int n, int root){
	int parent = root;
	int child = parent*2+1;
	while(child < n){
		//选左右孩子中较大的
		if(child + 1 < n && arr[child+1]>arr[child]){
			child++;
		}
		//如果父节点不是最大的则交换
		if(arr[parent] < arr[child]){
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child  = parent*2+1;
		}else{
			break;
		}
	}
}

//向上调整
void AdjustUp(HPDataType *arr, int n, int child){
	assert(arr);
	int parent = (child - 1) / 2;
	//while (parent >= 0){
	while (child > 0){
		if (arr[parent] < arr[child]){
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			break;
		}
	}
}



void HeapInit(Heap *hp, HPDataType *arr ,int n){
	int i = 0;
	assert(hp);
	hp->_arr = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = n;
	hp->_capacity = n;
	for(i = 0; i <= n; ++i){
		hp->_arr[i] = arr[i];
	}
	//调堆
	for(i = (n-2)/2; i>=0;--i){
		AdjustDown(hp->_arr,hp->_size,i);
    }
}
void HeapDestroy(Heap *hp,int n)
{
	assert(hp);
	free(hp->_arr);
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_arr = NULL;
}
void HeapPush(Heap *hp, HPDataType x)
{
	assert(hp);
	//增容
	if (hp->_capacity == hp->_size){
		hp->_capacity *= 2;
		hp->_arr = realloc(hp->_arr, sizeof(HPDataType)* hp->_capacity);
	}
	hp->_arr[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_arr,hp->_size, hp->_size-1);
}

void HeapPop(Heap *hp)
{
	assert(hp);
	hp->_arr[0] = hp->_arr[hp->_size - 1];
	hp->_size--;
	AdjustDown(hp->_arr, hp->_size, 0);
}

HPDataType HeapTop(Heap *hp)
{
	assert(hp);
	assert(hp->_size >= 1);
	return hp->_arr[0];   
}

int HeapSize(Heap *hp)
{
    assert(hp != NULL);
    return hp->_size;
}

//空返回1，非空返回0
int HeapEmpty(Heap *hp)
{
    assert(hp != NULL);
    return hp->_size > 0?1:0;
}

void HeapPrint(Heap * hp){
    int i = 0;
    assert(hp);
	for(i = 0;i<hp->_size;i++){
		printf("%d ",hp->_arr[i]);
	}
	printf("\n");
}

void HeapSort(int *arr, int len){
	int i = 0;
	
	//建堆
	for (i = (len - 2) / 2; i >= 0; --i){
		int parent = i;
		int child = parent * 2 + 1;
		while (child < len){
			if (child + 1 < len && arr[child] < arr[child + 1]){
				child++;
			}
			if (arr[child] > arr[parent]){
				Swap(&arr[child], &arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else{
				break;
			}
		}
	}
	//调堆
	//向下调整
    for(i = len-1;i>0;i--)
    {
        Swap(&arr[i], &arr[0]);
        int parent = 0;
		len = i;
		int child = parent * 2 + 1;
		while (child < len){
			if (child + 1 < len && arr[child] < arr[child + 1]){
				child++;
			}
			if (arr[child] > arr[parent]){
				Swap(&arr[child], &arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else{
				break;
			}
		}
    }
}
void HeapTest()
{
	Heap hp;
	int arr[] = {53, 17, 78, 9, 45, 65, 87, 23, 31};
	int len = sizeof(arr) / sizeof(HPDataType);
	int i = 0;
	HeapInit(&hp, arr, len);
	HeapSort(arr, len);
	for (i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	//HeapPrint(&hp);
	//HeapPush(&hp, 100);
	//HeapPrint(&hp);
	//HeapPop(&hp);
	//HeapPrint(&hp);
	//HeapPop(&hp);
	//HeapPrint(&hp);
	//HeapPop(&hp);
	//HeapPrint(&hp);
	//HeapPop(&hp);
	//HeapPrint(&hp);
}
