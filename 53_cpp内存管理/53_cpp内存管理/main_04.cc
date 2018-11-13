#ifdef _DEBUG
#define new new(__FILE__, __FUNCDNAME__, __LINE__)
#define delete(p) operator delete(p, __FILE__, __FUNCDNAME__, __LINE__)
#endif

#include <iostream>
#include <stdlib.h>

using namespace std;

void* operator new(size_t size, const char* strFileName, const char* strFuncName, size_t lineNo){
	void p = ::operator new(size);
	cout << strFileName << "--" << lineNode << "-- " << strFuncName << " new:" << size << " " << p << endl;
	return p;
}
void* operator new(void* p, const char* strFileName, const char* strFuncName, size_t
	lineNo)
{
	cout << strFileName << "--" << lineNode << "-- " << strFuncName << " delete:" << size << " " << p << endl;
	::operator delete(p);
}

int main()
{
	int* p = new int;
	delete(p);
	return 0;
}