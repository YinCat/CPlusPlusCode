#include "Date.h"

int Date::GetMonthDay(int year, int month){
	static const int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((month == 2 )&&
	   ( (year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)){
		return 29;
	}
	return monthDay[month];
}

Date::Date(int year, int month, int day){
	if (year > 0 && month > 0 && month <= 12 && day <= GetMonthDay(year, month) && day > 0){
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	else
		cout << "Date Create error..." << endl;
};

bool Date::operator>(const Date& d)  const {
	if (this->_year > d._year)
		return true;
	else if (this->_year == d._year){
		if (this->_month > d._month){
			return true;
		}
		else if (this->_month == d._month){
			if (this->_day > d._day)
				return true;
		}
	}
	return false;
}

bool Date::operator==(const Date& d) const {
	return this->_day == d._day
		&& this->_year == d._year
		&& this->_month == d._month;
}

bool Date::operator<(const Date& d) const {
	if (*this == d)
		return false;
	if (*this > d)
		return false;
	return true;
}

bool Date::operator !=(const Date& d) const {
	return !(*this == d);
}

bool Date::operator <=(const Date& d) const {
	if (*this < d || *this == d)
		return true;
	return false;
}

bool Date::operator >=(const Date& d) const {
	if (*this > d || *this == d)
		return true;
	return false;
}

Date Date::operator+(int day) const {  //��+ȥ����+=
	Date ret(*this);
	ret += day;
	return ret;
}

//������ʵ���� void Date::Print() const
void Date::Print() const{
	cout << this->_year << "��" << this->_month << "��" << this->_day << "��" << endl;
}

Date& Date::operator+=(int day){
	if (day < 0) 
		return *this -= (-day);

	_day += day;
	while (_day - GetMonthDay(_year, _month) > 0){
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month >= 13){
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator-(int day) const {
	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator-=(int day){
	if (day < 0)
		return *this += -day;
	_day -= day;
	while (_day <= 0) {
		--_month;
		if (_month <= 0){
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

int Date::operator-(const Date& d){
	if ((*this) == d)
		return 0;

	int ret = 0;
	Date _big;
	Date _small;

	_big = (*this) > d ? (*this) : d;
	_small = (*this) < d ? (*this) : d;

	Date _big2(_big);
	Date _small2(_small);

	Date *tmp = &_big;
	if (_big._day - _small._day < 0){
		_big._month--;
		if (_big._month == 0){
			_big._year--;
			_big._month = 12;
		}
		_big._day += GetMonthDay(_big._year, _big._month);
	}
	_big._day -= _small._day;
	if (_big._month - _small._month < 0){
		_big._year--;
		_big._month += 12;
	}
	_big._month -= _small._month;
	_big._year -= _small._year;

	ret = _big._year * 365 + _big._month * 30 + _big._day;
	
	for (int i = 0; i < _big._year/4 + 8; i++) {
		if (_small2 + (ret + i) == _big2) {
			return (*this) > d ? (ret + i) : -(ret + i);
		}
	}
	return 0;
}

Date& Date::operator++(){ // ++d => d.operator++(&d);
	*this += 1;
	return *this;
}

Date Date::operator++(int){// d++ => d.operator(&d, 0);
	Date ret(*this);
	(*this) += 1;
	return ret;
}

Date& Date::operator--(){ // --d => d.operator--(&d);
	*this -= 1;
	return *this;
}

Date Date::operator--(int){// d-- => d.operator--(&d, 0);
	Date ret(*this);
	(*this) -= 1;
	return ret;
}