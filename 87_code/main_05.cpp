#if 0
#include <iostream>

using namespace std;

// 专门处理int的加法函数
int Add(int left, int right)
{
	cout << "Func(int,int)" << endl;
	return left + right;
}

// 通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	cout << "Func(T1,T2)" << endl;
	return left + right;
}
void main()
{
	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
}
#endif