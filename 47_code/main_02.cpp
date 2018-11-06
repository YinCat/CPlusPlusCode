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
	HeapOnly(){}//屏蔽构造
	//HeapOnly(const HeapOnly& other){}//屏蔽拷贝构造
	//HeapOnly(const HeapOnly& other);//单纯的声明就会让编译器认为你写了拷贝构造，但是可以不写（1、只声明，不实现 2、声明为私有3、万一友元呢？）
	HeapOnly(const HeapOnly& other) = delete;//C++11的新特性，任何情况下不能使用拷贝构造
};

class StackOnly
{
public:
	static StackOnly GetStackObj()
	{
		return StackOnly();//返回的时候后调用拷贝构造
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
	//这样就可以自定义new和delete的操作
	//void* operator new(size_t n) {}
	//void operator delete(void* p) {}
	//安全起见，直接封死
	void* operator new(size_t n) = delete;
	void operator delete(void* p) = delete;
};



int main()
{
	//HeapOnly s;//要屏蔽构造函数
	HeapOnly* p1 = HeapOnly::GetHeapObj();
	//HeapOnly s(*p1);//拷贝构造还是可以把对象创建在堆上
	StackOnly::GetStackObj().Print();
	//StackType* n = new StackOnly;
	//StackOnly s;

	//static StackOnly s;
	return 0;
}
#endif