#if 0
#include<iostream>

using namespace std;

int main(){

	int *ptr = new int;
	int *ptr2 = new int(1);

	//cout << *ptr << endl;
	//cout << *ptr2 << endl;


	//int *arr = new int[3]; //OK 但是没有初始化
	//int *arr = new int[3]{}; //OK 初始化为全0
	//int *arr = new int[3]{1, 2, 3}; //OK 指定内容初始化
	//int *arr = new int[]{1, 2, 3}; //OK 指定内容初始化
	int *arr = new int[3]{1, 2}; //OK 制定部分内容初始化
	//int *arr = new int[3]{1, 2, 3, 4};//Error 指定个数与实际不符合

	for (int i = 0; i < 3;i++){
		cout << arr[i] << endl;
	}

	return 0;
}

#endif