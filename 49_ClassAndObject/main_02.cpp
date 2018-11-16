#include <iostream>

using namespace std;
class Date{
friend ostream& operator<<(ostream& out, const Date& d);
public:
	Date(int y, int m, int d) :
		year(y),
		month(m),
		day(d){

	}
private:
	int year;
	int month;
	int day;
};

ostream& operator<<(ostream& out, const Date& d){
	out << d.year << ":" << d.month << ":" << d.day;
	return out;
}
int main(){
	Date d(2018, 11, 10);
	cout << d << endl;;
	return 0;
}

class Date; // ǰ������
class Time
{
	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{	}

private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
		_t._hour = hour;
		_t._minute = minute;
		_t.second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());

	return 0;
}