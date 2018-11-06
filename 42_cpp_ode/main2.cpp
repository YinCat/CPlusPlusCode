#if 0
#include <iostream>
using namespace std;

class Date{

public:
	//Date(int year, int month, int day);
	/*Date(){
		this->_day = 1900;
		this->_month = 1;
		this->_day = 1;
		
	}*/

	Date(){
		cout << "Ä¬ÈÏ¹¹Ôì" << endl;
	}

	Date(Date& d){
		this->_day = d._day;
		this->_month = d._month;
		this->_year = d._year;
	}

	Date(int year, int month, int day){
		this->_day = day;
		this->_month = month;
		this->_year = year;
	}
	//Date(){
	//	this->_day = day;
	//	this->_month = month;
	//	this->_year = year;
	//}
	/*Date(int day = 1, int month = 1, int year = 1990){
		this->_day = day;
		this->_month = month;
		this->_year = year;	
	}*/
	
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl; 
		//cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//Date::Date(int year, int month, int day){
//	this->_day = day;
//	this->_month = month;
//	this->_year = year;
//}

int main(){

	//Date d1(2018, 10, 20);
	//Date d2(2018, 10, 21);
	////Date d1;
	////Date d2;

	//d1.Print();
	//d2.Print();

	//Date d4(d2);
	//d4.Print();

	int * p = (int*)malloc(100);
	free(p);
	//p = NULL;

	free(p);
	p = NULL;
	return 0;
}

#endif