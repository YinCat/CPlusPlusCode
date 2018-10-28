#ifndef __DATE_H__
#define __DATE_H__
//#pragma once


#include <iostream>

using namespace std;

class Date{

public:
	Date(int year = 1990, int month = 1, int day = 1);

	inline bool operator>(const Date& d) const;
	inline bool operator<(const Date& d) const;//多次调用的时候使用内联
	inline bool operator<=(const Date& d) const;
	inline bool operator>=(const Date& d) const;
	inline bool operator==(const Date& d) const;
	inline bool operator!=(const Date& d) const;

	inline int GetMonthDay(int year, int month);
	inline Date operator+(int day) const;
	inline Date& operator+=(int day);
	inline Date operator-(int day) const;
	inline Date& operator-=(int day);
	int operator-(const Date& d);
	inline Date& operator++(); // ++d => d.operator++(&d)
	inline Date operator++(int); // d++ => d.operator(&d, int);
	inline Date& operator--(); // --d => d.operator--(&d)
	inline Date operator--(int); // d-- => d.operator--(&d, int)
	//void Print(const Date* this);
	void Print() const;
	void fun() {
		Print();
	}
private:
	int _year;
	int _month;
	int _day;
};

#endif //!__DATE_H__