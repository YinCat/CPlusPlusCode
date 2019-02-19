#if 0
#include <iostream>

using namespace std;

class Person{
public:
	virtual void BuyTicket()
	{
		cout << "买全价票" << endl;
	}
};

class Student :public Person{
public:
	virtual void BuyTicket()
	{
		cout << "买半价票" << endl;
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
	//Func(&p);//买全价票

	//Student s;
	//Func(&s);//买半价票
	
	//Person p;
	//Func2(p);//买全价票

	//Student s;
	//Func2(s);//买全价票

	return 0;
}
#endif