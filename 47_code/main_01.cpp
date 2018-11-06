#if 0
#include <iostream>
#include <string.h>
using namespace  std;
class Demo
{
public:
	Demo()
	{
		cout << "hello" << endl;
	}
};

int main(int argc, char* argv[])
{
	//Demo* d = new Demo();
	Demo* d = (Demo*)malloc(sizeof(Demo));

	new(d)Demo;//对于已经有的空间调用构造函数初始化
	return 0;
}
#endif