#if 0
#include<iostream>

using namespace std;

int main(){

	int *ptr = new int;
	int *ptr2 = new int(1);

	//cout << *ptr << endl;
	//cout << *ptr2 << endl;


	//int *arr = new int[3]; //OK ����û�г�ʼ��
	//int *arr = new int[3]{}; //OK ��ʼ��Ϊȫ0
	//int *arr = new int[3]{1, 2, 3}; //OK ָ�����ݳ�ʼ��
	//int *arr = new int[]{1, 2, 3}; //OK ָ�����ݳ�ʼ��
	int *arr = new int[3]{1, 2}; //OK �ƶ��������ݳ�ʼ��
	//int *arr = new int[3]{1, 2, 3, 4};//Error ָ��������ʵ�ʲ�����

	for (int i = 0; i < 3;i++){
		cout << arr[i] << endl;
	}

	return 0;
}

#endif