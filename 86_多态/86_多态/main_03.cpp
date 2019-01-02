#if 0
#include <iostream>

using namespace std;
//void fun() throw(string, std::bad_alloc)
//{
//	throw "some error";
//}
//


class MyException :public std::exception {
public:
	//重写exception的what方法
	const char * what() const throw ()
	{
		return "这是自定义异常";
	}
};

void fun2() throw (MyException){
	MyException e;
	throw e;
}
void 方法() {
	cout << "XXXX" << endl;
}
int main()
{
	////fun();
	//try {
	//	fun();
	//}
	//catch (...)
	//{
	//	cout << "异常" << endl;
	//}

	//fun();
	try {
		fun2();
	}catch(MyException& e)
	{
		cout << e.what() << endl;
	}
	方法();
	return 0;
}
#endif