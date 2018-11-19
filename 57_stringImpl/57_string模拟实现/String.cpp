#include "String.h"

const size_t xpu::String::npos = -1;


ostream& xpu::operator<<(ostream &out, String& s){
	out << s.c_str();
	return out;
}


void xpu::String::Reserve(size_t n){
	if (n > _capacity){
		char* newstr = new char[n+1];
		strcpy(newstr, _str);
		delete[] _str;

		_str = newstr;
		_capacity = n;
	}
}

void xpu::String::Resize(size_t n, char ch)
{
	if (n <= _size){
		_str[n] = '\0';
		_size = n;
	}else{
		if (n > _capacity)
			Reserve(n);

		size_t pos = _size;
		while (pos < n){
			_str[pos] = ch;
			++pos;
		}
		_size = n;
		_str[n] = '\0';
	}
}

void xpu::String::PushBack(char ch){
	if (_size == _capacity){
		Reserve(_capacity * 2);
	}

	_str[_size] = ch;
	++_size;
	_str[_size] = '\0';
}

void xpu::String::Append(const char* str){
	size_t len = strlen(str);
	//增容的时候不是2倍2倍的增，而是根据字符串长度来判断
	if (_size + len > _capacity){
		Reserve(_size + len);
	}

	strcpy(_str + _size, str);
	_size += len;
}

xpu::String& xpu::String::operator+= (char ch){
	this->PushBack(ch);
	return *this;
}

xpu::String& xpu::String::operator+= (const char* str){
	this->Append(str);
	return *this;
}