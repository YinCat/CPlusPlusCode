#if 0
#include <iostream>

using namespace std;

// 定义一个模板类型的静态数组

template<class T, size_t N = rand()>
class Array {

private:
	T _arr[N];
	size_t _size;
};

//template<class T, double NUM = 10.0>
//class MyClass {
//private:
//	double s = NUM;
//};

int main()
{
	return 0;
}

//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}
#endif