#if 0
#include <iostream>

template<class T1, class T2>
class Data
{
public:
	Data() { std::cout << "Data<T1, T2>" << std::endl; }
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>
{
public:
	Data() { std::cout << "Data<int, char>" << std::endl; }
private:
	int _d1;
	char _d2;
};

int main()
{
	Data<int, int> d1;
	Data<int, char> d2;
}

template<class T1>
class Data<T1, int>
{
public:
	Data() { std::cout << "Data<T1, T2>" << std::endl; }
private:
	T1 _d1;
	T2 _d2;
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { std::cout << "Data<T1*, T2*>" << std::endl; }
private:
	T1* _d1;
	T2* _d2;
};

template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { std::cout << "Data<T1&, T2&>" << std::endl; }
private:
	T1& _d1;
	T2& _d2;
};
#endif
