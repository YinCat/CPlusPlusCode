#include <iostream>
#include <mutex>

class StackOnly{
public:
	StackOnly(){}
private:
	void* operator new(size_t size) = delete;
	void operator delete(void *p) = delete;
};

//
//class Singleton{
//public:
//	static Singleton* GetInstance(){
//		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
//		if (m_pInstance == nullptr){
//			m_mutex.lock();
//			if (m_pInstance == nullptr){
//				m_pInstance = new Singleton();
//			}
//			m_mutex.unlock();
//		}
//		return m_pInstance;
//	}
//	// 实现一个内嵌垃圾回收类
//	class Recycle {
//	public:
//		~Recycle(){
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static Recycle recycle;
//private:
//	//构造函数私有
//	Singleton(){}
//
//	//防止拷贝
//	Singleton(const Singleton& other) = delete;
//	Singleton& operator=(const Singleton& other) = delete;
//
//	static Singleton* m_pInstance; // 单例对象指针
//	static std::mutex m_mutex;
//};
//Singleton* Singleton::m_pInstance = nullptr;
//std::mutex Singleton::m_mutex;
//
//Singleton::Recycle recycle;


class Singleton{
public:
	Singleton* GetInstance(){
		return &instance;
	}
private:
	Singleton(){}
	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;
	static Singleton instance;
};

Singleton Singleton::instance;// 在程序入口之前就完成单例对象的初始化

int main(){

	//StackOnly *p = new StackOnly();
	StackOnly s;
	return 0;
}