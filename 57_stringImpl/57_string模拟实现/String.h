#ifndef __STRING_H__
#define __STRING_H__
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;

namespace xpu
{
class String
{

public:
	
	// ������
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin(){
		return _str;
	}

	iterator end(){
		return _str + _size;
	}


	// ��������ʵ�֣�Ĭ����inline
	String(const char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}

	~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}

	// s1 = s2
	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}

	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	const char* c_str()
	{
		return _str;
	}

	void Reserve(size_t n);
	void Resize(size_t n, char ch = '\0');

	void PushBack(char ch);
	void Append(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);
	size_t Find(char ch, size_t pos = 0);
	size_t Find(const char* str, size_t pos = 0);
	void Insert(size_t pos, char ch);
	void Insert(size_t pos, const char* str);
	void Erase(size_t pos, size_t len = npos);
	friend ostream & operator<< (ostream &output, String& s);
	//String Substr();
private:
	char* _str;
	size_t _size;
	size_t _capacity;

	static const size_t npos;
};

// ��չѧϰ
//operator<<()
//operator>>()
//operator> �Ƚϴ�С
//operator<


}



#endif //!__STRING_H__