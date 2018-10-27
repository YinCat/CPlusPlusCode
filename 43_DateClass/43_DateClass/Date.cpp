#include "Date.h"


int Date::GetMonthDay(int year, int month){
	static const int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((month == 2 )&&
	   ( (year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)){
		return 29;
	}
	return monthDay[month];
}


//int Date::GetYearDay(int year){
//	//闰年
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
//		return 365;
//	}
//	return 366;
//}
//
////从1月1日到现在多少天？
//
//int Date::GetOneOneDay(int year, int month, int day){
//	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
//		monthDay[2] = 29;
//	}
//	int ret = 0;
//	for (int i = 0; i< month; i++){
//		ret += monthDay[i];
//	}
//	return ret;
//}

//构造函数给出默认值
Date::Date(int year, int month, int day){
	if (year > 0 && month > 0 && month <= 12 && day <= GetMonthDay(year, month) && day > 0){
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	else{
		cout << "Date Create error..." << endl;
	}	
};

bool Date::operator>(const Date& d) {
	if (this->_year > d._year){
		return true;
	}
	else if (this->_year == d._year){
		if (this->_month > d._month){
			return true;
		}
		else if (this->_month == d._month){
			if (this->_day > d._day){
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date& d){
	return this->_day == d._day
		&& this->_year == d._year
		&& this->_month == d._month;
}

bool Date::operator<(const Date& d){
	if (*this == d)
		return false;
	if (*this > d)
		return false;
	return true;
}



bool Date::operator !=(const Date& d){
	return !(*this == d);
}

bool Date::operator <=(const Date& d){
	if (*this < d || *this == d)
		return true;
	return false;
}

bool Date::operator >=(const Date& d){
	if (*this > d || *this == d)
		return true;
	return false;
}

Date Date::operator+(int day){
	Date ret(*this);
	Date* pret = &ret;
	pret->_day += day;

	//GetMonthDay(this->_year, this->_month);//本月有多少天
	while (pret->_day - GetMonthDay(pret->_year, pret->_month) > 0){
		pret->_day -= GetMonthDay(pret->_year, pret->_month);
		pret->_month++;
		if (pret->_month >= 13){
			pret->_month = 1;
			pret->_year++;
		}
	}
	return *pret;
}

void Date::Print(){
	cout << this->_year << "年" << this->_month << "月" << this->_day << "日" << endl;
}

Date& Date::operator+=(int day){
	*this = (*this) + day;
	return *this;
}

Date Date::operator-(int day){
	this->_day -= day;
		while (GetMonthDay(this->_year, this->_month) + this->_day < 0){
			this->_day += GetMonthDay(this->_year, this->_month);
			this->_month--;
			if (this->_month <= 0){
				this->_month = 12;
				this->_year--;
			}
		}
		//GetMonthDay(this->_year, this->_month) + this->_day >= 0
		//this->_day = -this->_day;10月 -10号--->9月20号
		this->_day = GetMonthDay(this->_year, this->_month-1) + this->_day;
		this->_month--;
		if (this->_month <= 0){
			this->_month = 12;
			this->_year--;
		}
		return *this;
}

Date& Date::operator-=(int day){
	*this = (*this) - day;
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
	for (int i = -7; i < 8; i++){
		if (_small2 + (ret + i) == _big2){
			return (*this)>d ? (ret + i) : -(ret + i);
		}
	}
	
	return 0;
}

Date Date::operator++(){ // ++d => d.operator++(&d);
	(*this) = (*this) + 1;
	return *this;
}

Date Date::operator++(int){// d++ => d.operator(&d, 0);
	Date ret(*this);
	(*this) = (*this) + 1;
	return ret;
}

Date Date::operator--(){ // --d => d.operator--(&d);
	(*this) = (*this) - 1;
	return *this;
}

Date Date::operator--(int){// d-- => d.operator--(&d, 0);
	Date ret(*this);
	(*this) = (*this) - 1;
	return ret;
}
