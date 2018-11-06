#if 0
#include <iostream>
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()
	{
		return new HeapOnly;
	}

private:
	HeapOnly(){}//���ι���
	//HeapOnly(const HeapOnly& other){}//���ο�������
	//HeapOnly(const HeapOnly& other);//�����������ͻ��ñ�������Ϊ��д�˿������죬���ǿ��Բ�д��1��ֻ��������ʵ�� 2������Ϊ˽��3����һ��Ԫ�أ���
	HeapOnly(const HeapOnly& other) = delete;//C++11�������ԣ��κ�����²���ʹ�ÿ�������
};

class StackOnly
{
public:
	static StackOnly GetStackObj()
	{
		return StackOnly();//���ص�ʱ�����ÿ�������
	}
	void Print()
	{
		std::cout << "StackOnly::Print" << std::endl;
	}
private:
	StackOnly(){}
};

class StackType
{
public:
	StackType(){}
	void Print()
	{
		std::cout << "StackOnly::Print" << std::endl;
	}
private:
	//�����Ϳ����Զ���new��delete�Ĳ���
	//void* operator new(size_t n) {}
	//void operator delete(void* p) {}
	//��ȫ�����ֱ�ӷ���
	void* operator new(size_t n) = delete;
	void operator delete(void* p) = delete;
};



int main()
{
	//HeapOnly s;//Ҫ���ι��캯��
	HeapOnly* p1 = HeapOnly::GetHeapObj();
	//HeapOnly s(*p1);//�������컹�ǿ��԰Ѷ��󴴽��ڶ���
	StackOnly::GetStackObj().Print();
	//StackType* n = new StackOnly;
	//StackOnly s;

	//static StackOnly s;
	return 0;
}
#endif