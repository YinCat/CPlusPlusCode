#if 0
#include <iostream>

using namespace std;

//ר�Ŵ���int�ĺ���
int Func(const int& x1, const int& x2)
{
	cout << "Sub(int,int)" << endl;
	return x1 - x2;
}
//���õĺ���ģ��
template<class T>
T Func(const T& x1, const T& x2)
{
	cout << "Sub(T,T)" << endl;
	return x1 - x2;
}
int main()
{
	int a1 = 2, a2 = 3;
	Func(a1, a2);//���ģ�庯��ƥ�䣬����������Ҫ�ػ� 
	Func<int>(a1, a2);//���ñ������ػ��ĺ���
	return 0;
}

#endif