#include <iostream>
#include <mutex>
using namespace std;

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
//		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
//		if (m_pInstance == nullptr){
//			m_mutex.lock();
//			if (m_pInstance == nullptr){
//				m_pInstance = new Singleton();
//			}
//			m_mutex.unlock();
//		}
//		return m_pInstance;
//	}
//	// ʵ��һ����Ƕ����������
//	class Recycle {
//	public:
//		~Recycle(){
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//
//	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	static Recycle recycle;
//private:
//	//���캯��˽��
//	Singleton(){}
//
//	//��ֹ����
//	Singleton(const Singleton& other) = delete;
//	Singleton& operator=(const Singleton& other) = delete;
//
//	static Singleton* m_pInstance; // ��������ָ��
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

Singleton Singleton::instance;// �ڳ������֮ǰ����ɵ�������ĳ�ʼ��

int main(){
	char *c = "hello";
	cout << c << endl;
	//StackOnly *p = new StackOnly();
	StackOnly s;
	return 0;
}