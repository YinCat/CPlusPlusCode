#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void test_vector1()
{
	string str("hello");

	vector<int> v1;
	vector<int> v2(10, 3);
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(str.begin(), str.end());

	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v4.begin();
	while (it != v4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//vector<int>::reverse_iterator rit = v4.rbegin();
	auto rit = v4.rbegin();
	while (rit != v4.rend())
	{
		//*rit = 10;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<int>::const_iterator cit = v4.begin();
	while (cit != v4.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	for (size_t i = 0; i < v4.size(); ++i)
	{
		cout << v4[i] << " ";
	}
	cout << endl;

	for (const auto& e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<string> strv;
	strv.push_back("hello");
	strv.push_back("world");
	for (const auto& s : strv)
	{
		cout << s << " ";
	}
	cout << endl;

	// 遍历
	// 1.迭代器
	// 2.for+[i]
	// 3.for-each C++11
}

void test_vector2()
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	foo.reserve(100);
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		//foo[i] = i;
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	for (const auto& e : foo)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v.push_back(5);

	//vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	auto pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.insert(pos, 20);
	}

	// 迭代器失效
	//*pos = 10;
	pos = find(v.begin(), v.end(), 2);
	v.erase(pos);
	*pos = 10;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include "Vector.h"

void TestVector1()
{
	bit::Vector<int> v1;
	/*v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);*/

	for (auto e : v1)
	{
		cout << e << endl;
	}
}

int main()
{
	//test_vector4();

	TestVector1();

	return 0;
}