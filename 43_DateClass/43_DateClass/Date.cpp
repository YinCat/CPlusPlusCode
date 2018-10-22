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

Date::Date(int year, int month, int day){
	if (year > 0 && month > 0 && month <= 12 && day < GetMonthDay(year, month) && day > 0){
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	else{
		cout << "Date Create error..." << endl;
	}	
};

bool Date::operator>(const Date& d){
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
	this->_day += day;

	//GetMonthDay(this->_year, this->_month);//本月有多少天
	while (this->_day - GetMonthDay(this->_year, this->_month) > 0){	
		this->_day -= GetMonthDay(this->_year, this->_month);
		this->_month++;
		if (this->_month >= 13){
			this->_month = 1;
			this->_year++;
		}
	}
	return *this;
}

void Date::Print(){
	cout << this->_year << "年" << this->_month << "月" << this->_day << "日" << endl;
}

Date& Date::operator+=(int day){
	return (*this) + day;
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
	return (*this) - day;
}

int Date::operator-(const Date& d){
	int ret = 0;
	if ((*this) > d){
		if (this->_day - d._day < 0){
			this->_month--;
			if (this->_month == 0){
				this->_year--;
				this->_month = 12;
			}
			this->_day += GetMonthDay(this->_year, this->_month);
		}

	}
	else{
		cout << "error" << endl;
	}
	return 0;
}

//Date Date::operator++(); // ++d => d.operator++(&d)
//Date Date::operator++(int); // d++ => d.operator(&d, 0);
//Date Date::operator--(); // --d 
//Date Date::operator--(int); // d--
