#ifndef __DATE_H__
#define __DATE_H__
//#pragma once
#include <iostream>

using namespace std;

class Date{
public:
	Date(int year = 1990, int month = 1, int day = 1);

	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	int GetMonthDay(int year, int month);
	int GetYearDay(int year);
	int GetOneOneDay(int year, int month, int day);
	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	Date operator++(); // ++d => d.operator++(&d)
	Date operator++(int); // d++ => d.operator(&d, 0);
	Date operator--(); // --d 
	Date operator--(int); // d--
	void Print();
private:
	int _year;
	int _month;
	int _day;
};



#endif //!__DATE_H__