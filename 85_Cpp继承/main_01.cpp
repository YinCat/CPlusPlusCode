#include <iostream>
#if 0
class A{
public:
	static A getInstance(){
		return A();
	}

private:
	A(){}
};

class B final{

};

class C :public A{

};
//
//class D :public B{
//
//};

int main()
{
	A ret = A::getInstance();
	return 0;
}
#endif