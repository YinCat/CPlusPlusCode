#include <iostream>
#include <vector>

using namespace std;

int main(){

	// ֻ���������ֲ��ǳɶԳ��ֵ�
	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1, 7};

	int r_num = 0;

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		r_num ^= arr[i];
	}
	//ret��5��7�������
	int index = 0;//retΪ1��һλ������
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

	return 0;
}