#include "demo.h"
#include <iostream>
using namespace std;


//extern "C" int add(int a, char b) {
//	return 0;
//}

void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a)
{
	cout << "void TestFunc(int)" << endl;
}

int main() {

	return 0;
}