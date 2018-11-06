#include <iostream>

using namespace std;

void Swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

int PartSort(int[] arr, int left, int right){
	int key = arr[right];
	int start = left;
	int end = right;
	while (start < right){
		while (start < right && arr[start++] < key){
			start++;
		}

		while (start < right && arr[end--] > key){
			end--;
		}
		if (start < end)
			Swap(arr[start], arr[end]);
	}
	if (start != right - 1)
		Swap(arr[start], arr[right]);
}

void QuickSort(int[] arr, int left, int right){
	if (left <= right)
		return;
	int ret = PartSort(arr, left, right);
	QuickSort(arr, left, div);
	QuickSort(arr, div+1, right);
}

int main(){
	int arr[] = { 3, 4, 9, 7, 2, 0, 8, 1, 6 };
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, len - 1);
	return 0;
}

