#if 0
#include <iostream>

using namespace std;

class Person{
public:
	virtual void BuyTicket()
	{
		cout << "��ȫ��Ʊ" << endl;
	}
};

class Student :public Person{
public:
	virtual void BuyTicket()
	{
		cout << "����Ʊ" << endl;
	}
};

void Func(Person *p)
{
	p->BuyTicket();
}

void Func2(Person p)
{
	p.BuyTicket();
}

int main()
{
	//Person p;
	//Func(&p);//��ȫ��Ʊ

	//Student s;
	//Func(&s);//����Ʊ
	
	//Person p;
	//Func2(p);//��ȫ��Ʊ

	//Student s;
	//Func2(s);//��ȫ��Ʊ

	return 0;
}
#endif