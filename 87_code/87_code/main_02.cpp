//#include <iostream>
//
//using namespace std;
//
//template <class T1, class T2>
//T1 fun(T1 t1, T2 t2)
//{
//	return t1 + t2;
//}
//
//int main(void)
//{
//	cout << fun(2, 5.0) << endl;
//	return 0;
//}

template<class T>
T Sub(const T& x1, const T& x2)
{
	return x1 - x2;
}
int main()
{
	
	Sub(10, 20);
	Sub(10.0, 20.0);
	//Sub(a1, d1);�������У��������ͱ�������֪��Ҫ���Ǹ����������µĴ���
	//�������:1.��d1ǿ������ת��Ϊint���߰�a1ǿ������ת��Ϊdouble
	Sub(10, (int)20.0);
	//2.������ʾʵ����
	//Sub<int>(a1, d1);
	return 0;
}
