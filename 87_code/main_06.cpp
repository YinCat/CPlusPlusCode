#if 0
#include <iostream>

//专门处理int的函数
int Func(const int& x1, const int& x2)
{
	std::cout << "Func(int, int)" << std::endl;
	return x1 - x2;
}
//调用的函数模板
template<class T>
T Func(const T& x1, const T& x2)
{
	std::cout << "Func(T, T)" << std::endl;
	return x1 - x2;
}
int main()
{
	Func(1, 2);//与非函数模板类型完全匹配，不需要函数模板实例化
	Func<>(1, 2);//调用模板生成的Add函数
	return 0;
}
#endif