#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <iostream>
using namespace std;

class String{
public:
	String& operator=(String& other){
		if (this == &other)
			return *this;
		delete[] this->_str;
		this->_str = new char[strlen(other._str) + 1];
		strcpy(this->_str, other._str);
		return *this;
	}

	//String(const String& s)
	//:_str(new char[strlen(s._str)+1]){
	//	strcpy(this->_str, s._str);
	//}
	//ÏÖ´úÐ´·¨
	String(const String& s)
	:_str(nullptr){
		String tmp(s._str);
		swap(this->_str, tmp._str);
	}


	String(char* str  = "")
		:_str(new char[strlen(str)+1]){
		strcpy(_str, str);
	}

	friend ostream& operator<<(ostream& out, String& str);
private:
	char *_str;
};

ostream& operator<<(ostream& out, String& str){
	std::cout << str._str;
	return std::cout;
}