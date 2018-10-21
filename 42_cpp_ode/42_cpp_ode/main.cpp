#if 0
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
	cout << sizeof(X) << endl;
	
	
	
	return 0;
}
#endif