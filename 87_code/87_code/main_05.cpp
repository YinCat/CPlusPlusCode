#if 0
#include <iostream>

using namespace std;

// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	cout << "Func(int,int)" << endl;
	return left + right;
}

// ͨ�üӷ�����
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	cout << "Func(T1,T2)" << endl;
	return left + right;
}
void main()
{
	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
}
#endif