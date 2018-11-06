#include "demo.h"
#include <iostream>
#include <list>
#include <string>
#include <thread>
using namespace std;


//extern "C" int add(int a, char b) {
//	return 0;
//}

//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc(int a)
//{
//	cout << "void TestFunc(int)" << endl;
//}

//void fun(int& a, int& b) {
//	a += b;
//	b = a - b;
//	a = a - b;
//}
//void fun2(int arr[])
//{
//	for (int arrs : arr){
//		
//	}
//}

//int main() {

	//auto a = 10;
	//auto b = 20;


	//list<string> s;

	//list<string>::iterator be = s.begin();
	//list<string>::iterator en = s.end();

	//int s1[] = { 1,2,3,4,5 };
	//auto b[5] = s1;
	//auto be2 = s.begin();
	//auto en2 = s.end();

	//int arr[] = { 1,3,5,7,9,11 };
	//
	//for(int i:arr){
	//	cout << i << " ";
	//}
	//void* s = nullptr;
	//NULL;
	//cout << sizeof((void*)0) << endl;
	//int arr[] = { 12,3 };
	//fun2(arr);

	//long long a = 10;
	//cout << sizeof(a) << endl;


	//int a = 20;
	//constexpr int x = a;
	//return 0;
//}

//constexpr int fun(){
//	return 0;
//}
//int main(){
//	constexpr int ret = fun();
//	return 0;
//}
//constexpr int size(int s)
//{
//	return s * 4;
//}
//
//int a = 20;
//const int b = 30;
//constexpr int c = 40;
//constexpr int si = size(a);  //error a是一个变量所以函数返回的是一个可变的值
//constexpr int si1 = size(20); //ok 函数返回的实际上是一个常量
//constexpr int si2 = size(b);  //ok
//constexpr int si3 = size(c);  //ok

//typedef int INT;  // 右侧符号代表左侧
//using INT2 = int; // 左侧符号代表右侧
//
//INT a = 20;
//INT2 b = 30;

//int main()
//{
//	int a = 10;
//	const int i = a;
//	constexpr int i2 = a;
//
//	return 0;
//}

////列表初始化还可以用结构体
//typedef struct Str {
//	int x;
//	int y;
//}Str;
//Str s = { 10,20 };
//
////列表初始化类,必须是public成员,如果含有私有成员会失败
//class Cls {
//public:
//	int x;
//	int y;
//};
//Cls c = { 10,20 };

//int main()
//{
//	int a = { 10 };//OK
//	int b = { 10.1 };//error
//	int c = 10.1 ;//OK
//
//	return 0;
//}

int main()
{
	auto add = [](int a, int b)->int {
         return a + b;
    };
    int ret = add(1, 2);
	std::cout << "ret:" << ret << std::endl;
    return 0;
}