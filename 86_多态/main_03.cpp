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
	//��дexception��what����
	const char * what() const throw ()
	{
		return "�����Զ����쳣";
	}
};

void fun2() throw (MyException){
	MyException e;
	throw e;
}
void ����() {
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
	//	cout << "�쳣" << endl;
	//}

	//fun();
	try {
		fun2();
	}catch(MyException& e)
	{
		cout << e.what() << endl;
	}
	����();
	return 0;
}
#endif