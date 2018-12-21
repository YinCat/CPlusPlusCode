#include <iostream>
#include <vector>

using namespace std;

int main(){

	// 只有两个数字不是成对出现的
	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1, 7};

	int r_num = 0;

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		r_num ^= arr[i];
	}
	//ret是5和7的异或结果
	int index = 0;//ret为1那一位的索引
	for (int i = 0; i < 32; i++){
		if (((r_num >> i) & 1) == 1)
			break;
		else
			index++;
	}

	int num1 = 0;
	int num2 = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		if (((arr[i] >> index) & 1) == 1)
			num1 ^= arr[i];
		else
			num2 ^= arr[i];
	}

	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;

	// 屏幕录像专家测试呀
	cout << "ret1 = " << num1 << endl;
	cout << "ret2 = " << num2 << endl;

	return 0;
}