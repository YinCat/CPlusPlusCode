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

	new(d)Demo;//�����Ѿ��еĿռ���ù��캯����ʼ��
	return 0;
}
#endif