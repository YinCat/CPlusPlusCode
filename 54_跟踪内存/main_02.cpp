#include <iostream>

using namespace std;

class Demo{
public:
	Demo(){
		cout << "���캯��" << endl;
	}
};

class HeapOnly{
public:
	static HeapOnly* CreatInstance(){
		  return new HeapOnly;
	}
private:
	HeapOnly(){}
	// ������
	HeapOnly(const HeapOnly&);
};




int main(){
	Demo *p = (Demo*)malloc(sizeof(Demo));
	new(p)Demo;

	delete p;
	return 0;
}