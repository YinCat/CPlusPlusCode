#include <iostream>
#include <string>


#define MAX(a,b) ((a)>(b)?(a):(b))

int main02(void)
{
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	//list<int> s1(arr,arr+6);
	//list<int>::iterator it = s1.begin();
	//std::cout << "helloworld" << std::endl;
	return 0;
}

using namespace std;

int a = 10;

void Swap(int&a, int&b){
	a += b;
	b = a - b;
	a = a - b;
}

class Student{
public:
	char* name;
	int age;
	void getName(){
		std::cout << name << endl;
	}
};

int main(){
	Student s;
	strcpy(s.name, "hello");
	s.age = 10;
	s.getName();
}
namespace A{
	int a = 10;
	namespace B{
		int a = 10;
	}
}

//using A::a;//ָ����aΪA�����ռ������a

int main01(){
	//std::cout   << a << std::endl;
	//std::cout << A::a << std::endl;
	//std::cout << A::B::a << std::endl;
	//std::cout << 123 << std::endl;
	//std::cout << "helloworld" << std::endl;
	//int a = 10;
	//int& b = a;
	//b = 20;
	//std::cout << a << std::endl;
	//int b = 20;
	//Swap(a, b);
	//cout << a << ":" << b << endl;
	//int* p = &a;
	//int& b = a;
	cout << MAX(4+3, 5) << endl;
	
	return 0;
}