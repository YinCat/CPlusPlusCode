#include <iostream>
using namespace std;


class Date{

private:
	int _year;
	int _month;

public:
	Date(int year, int month){
		this->_month = month;
		this->_year = year;
	}

	bool Equal(const Date& other){
		return this->_year == other._year
			&& this->_month == other._month;
	}

	bool operator==(const Date& other){
		return this->_year == other._year
			&& this->_month == other._month;
	}

	//d2 = d1;
	//d2.operator=(d1);
	//d2.operator=(&d2, d1);
	Date& operator=(const Date& other){
		if (this != &other){ //通过对引用取地址来比较地址是否一样
			this->_month = other._month;
			this->_year = other._year;
		}
		return *this;
	}

	void Print(){
		cout << this->_year << ":" << this->_month << endl;
	}
};

//bool operator==(const Date& d1, const Date& d2){
//	return d1._year == d2._year
//		&& d1._month == d2._month;
//}

int main(){

	Date d1(2018, 10);
	Date d2(2018, 10);
	
	//cout << (operator==(d1, d2)) << endl;
	//cout << (d1 == d2) << endl;//增强可读性
	//cout << d1.Equal(d2) << endl;//增强可读性

	Date d3(2000, 20);
	d3.Print();
	d3 = d2;

	d2.Print();
	d3.Print();

	return 0;
}