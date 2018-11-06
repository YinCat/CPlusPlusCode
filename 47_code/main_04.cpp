#include <iostream>

using namespace std;

//template<typename T>
template<class T>
void Swap(T& t1, T& t2)
{
	T tmp = t1;
	t1 = t2;
	t2 = tmp;
}
int main(int argc, char* argv[])
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	Swap<int>(a, b);//ÏÔÊ½ÊµÀý»¯
	cout << a << " " << b << endl;
}
