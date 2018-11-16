#if 0
#include<iostream>
#include <stdlib.h>

using namespace std;

class Demo{
public:
	Demo(){
		cout << "构造函数" << endl;
	}

	~Demo(){
		cout << "析构函数" << endl;
	}
};
int main_03(){
	Demo *pd = (Demo*)malloc(sizeof(Demo));
	free(pd);
	pd = NULL;

	cout << endl;
	Demo *pd2 = new Demo();
	delete pd2;
	

	cout << endl;
	Demo *pd_arr = new Demo[10];
	delete[] pd_arr;

	operator new(20);
	return 0;
}


#endif