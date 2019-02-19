#if 0
#include <iostream>

using namespace std;

//专门处理int的函数
int Func(const int& x1, const int& x2)
{
	cout << "Sub(int,int)" << endl;
	return x1 - x2;
}
//调用的函数模板
template<class T>
T Func(const T& x1, const T& x2)
{
	cout << "Sub(T,T)" << endl;
	return x1 - x2;
}
int main()
{
	int a1 = 2, a2 = 3;
	Func(a1, a2);//与非模板函数匹配，编译器不需要特化 
	Func<int>(a1, a2);//调用编译器特化的函数
	return 0;
}

#endif