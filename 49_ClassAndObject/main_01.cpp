//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}


//#include <iostream>
//
//class Date{
//public:
//	void display() const {
//		//display2();
//		std::cout << _year << ":" << _month << ":" << _day << std::endl;
//	}
//	void display2(){
//		
//		std::cout << _year << ":" << _month << ":" << _day << std::endl;
//	}
//private:
//	size_t _year;
//	size_t _month;
//	size_t _day;
//};
//
//int main(){
//	const Date d;
//	//d.display2();error
//	Date d2;
//	d2.display();
//	d2.display2();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Date{
//public:
//	Date(int year) :
//		_year(year){
//	
//	}
//
//	static void fun_s(){
//		cout << "static fun()..." << endl;
//		//fun_u();error
//		//_year = 10;
//	}
//
//	void fun_u(){
//		fun_s();
//	}
//private:
//	size_t _year;
//	static int num;
//	// 非静态成员变量，可以在成员声明时，直接初始化。
//	int a = 10;
//	int* p = (int*)malloc(4);
//};
//int Date::num = 10;
//
//int main(){
//	Date d1(2017);
//	Date d2 = 2018;
//	//Date::fun();
//	
//	return 0;
//}