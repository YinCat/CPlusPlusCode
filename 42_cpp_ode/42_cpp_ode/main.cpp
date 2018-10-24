#include <string>

#if 1
#include <iostream>
using namespace std;

struct ListNode{
	ListNode* next;
	ListNode* prev;
};

class A{
public:
	void SetA(int a)
	{
		this->a = a;
	}
	void PrintA(){
		cout << a << endl;
	}
private:
	int a;
};

class X{

};
int main(){
	//A a;
	//a.SetA(10);
	//a.PrintA();

	//A* a2 = new A();
	//a2->SetA(20);
	//a2->PrintA();
	//cout << sizeof(X) << endl;

	//一个字符数组保存的"Love", 另一个字符数组保存的"We  China."要把Love插入到后面的那个里面怎么搞 ?用退格的方式
	char love[] = "Love";
	char wechina[20] = { 0 };
	strcpy(wechina, "We China");
	
	for (int i = 20; i > 0; i--){
		if (wechina[i] != 0){
			wechina[i + 5] = wechina[i];
		}
	}
	int index = 0;
	wechina[2] = ' ';
	wechina[3] = love[index++];
	wechina[4] = love[index++];
	wechina[5] = love[index++];
	wechina[6] = love[index++];

	cout << wechina << endl;
	return 0;
}
#endif