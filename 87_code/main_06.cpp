#if 0
#include <iostream>

//ר�Ŵ���int�ĺ���
int Func(const int& x1, const int& x2)
{
	std::cout << "Func(int, int)" << std::endl;
	return x1 - x2;
}
//���õĺ���ģ��
template<class T>
T Func(const T& x1, const T& x2)
{
	std::cout << "Func(T, T)" << std::endl;
	return x1 - x2;
}
int main()
{
	Func(1, 2);//��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Func<>(1, 2);//����ģ�����ɵ�Add����
	return 0;
}
#endif