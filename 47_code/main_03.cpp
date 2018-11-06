#if 0
#include <iostream>
#include <mutex>
using namespace  std;
//����ʽ(�򵥡����ܻᵼ������������
class SingletonE
{
public:
	//static SingletonE* GetSingletonE()
	//{
	//	return &_sInstance;
	//}
	static SingletonE& GetSingletonE()
	{
		return _sInstance;
	}
private:
	SingletonE(){}
	//��ֹ����C++98
	//SingletonE(const SingletonE&);//���ο�������
	//SingletonE& operator=(const SingletonE&);

	//C++11
	SingletonE(const SingletonE&) = delete;//���ο�������
	SingletonE& operator=(const SingletonE&) = delete;
	static SingletonE _sInstance;
};

//���о�̬�Ķ�������߳�ʼ��
SingletonE SingletonE::_sInstance;

//����ʽ(��һ��ʹ��ʵ������ʱ����������)
class SingletonL
{
public:
	static SingletonL* GetInstance()
	{
		//ע������˫��飬��������Ч��
		if(_spInstance == nullptr){
			_smtx.lock();//����
			if(_spInstance == nullptr)
				_spInstance = new SingletonL;
			_smtx.unlock();//����
		}
		return _spInstance;
	}
	// ʵ��һ����Ƕ����������
	class CGarbo {
	public:
		~CGarbo() {
			if (SingletonL::_spInstance)
				delete SingletonL::_spInstance;
		}
	};
private:
	SingletonL(){}
	static SingletonL* _spInstance;
	static mutex _smtx;
	static CGarbo _gc;
};

SingletonL* SingletonL::_spInstance = nullptr;

SingletonL::CGarbo SingletonL::_gc;

mutex SingletonL::_smtx;

int main(int argc, char* argv[])
{
	cout << &SingletonE::GetSingletonE() << endl;
	cout << &SingletonE::GetSingletonE() << endl;

	cout << SingletonL::GetInstance() << endl;
	cout << SingletonL::GetInstance() << endl;
	return 0;
}
#endif