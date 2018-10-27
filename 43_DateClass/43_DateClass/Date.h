#ifndef __DATE_H__
#define __DATE_H__
//#pragma once


#include <iostream>

using namespace std;

class Date{

public:
	Date(int year = 1990, int month = 1, int day = 1);

	inline bool operator>(const Date& d);
	inline bool operator<(const Date& d);//多次调用的时候使用内联
	inline bool operator<=(const Date& d);
	inline bool operator>=(const Date& d);
	inline bool operator==(const Date& d);
	inline bool operator!=(const Date& d);

	inline int GetMonthDay(int year, int month);
	inline Date operator+(int day);
	inline Date& operator+=(int day);
	inline Date operator-(int day);
	inline Date& operator-=(int day);
	inline int operator-(const Date& d);
	inline Date& operator++(); // ++d => d.operator++(&d)
	inline Date operator++(int); // d++ => d.operator(&d, int);
	inline Date& operator--(); // --d => d.operator--(&d)
	inline Date operator--(int); // d-- => d.operator--(&d, int)
	void Print();

private:
	int _year;
	int _month;
	int _day;
};

#endif //!__DATE_H__