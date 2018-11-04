#include <iostream>
#include <string>
using namespace std;

template <class T>
class Vector
{
public:
	Vector()
		:_array(nullptr),
		_capacity(0),
		_size(0)
	{

	}
	void PushBack(const T& x)
	{
		if (_size == _capacity)
		{
			size_t newsize = _capacity == 0 ? 3 : _capacity * 2;
			T* new_arr = new T(newsize);
			memcpy(new_arr, _array, sizeof(T)*_size);
			delete[] _array;
			_array = new_arr;
		}
		_array[_size] = x;
		_size++;
	}

	T& operator[](size_t pos)
	{
		return _array[pos];
	}
	~Vector()
	{
		delete[] _array;
		_capacity = _size = 0;
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

#include <stack>


class Solution {
public:
	bool isValid(string s) {
		stack<char> ck;
		for (int i = 0; i < s.size() - 1; i++) {
			char top  = 0;
			if (!ck.empty())
				top = ck.top();
			if (top == '(') {
				if (s[i] == ')') {
					ck.pop();
				}
				else {
					ck.push(s[i]);
				}
			}
			else if (top == '[') {
				if (s[i] == ']') {
					ck.pop();
				}
				else {
					ck.push(s[i]);
				}
			}
			else if (top == '{') {
				if (s[i] == '}') {
					ck.pop();
				}
				else {
					ck.push(s[i]);
				}
			}
			else {
				ck.push(s[i]);
			}

		}
		return ck.empty();
	}
};
int main(int argc, char* argv[])
{
	Solution s;
	//cout << s.isValid("()") << endl;
	//Vector<int> v;
	//v.PushBack(11);
	//v.PushBack(12);
	//v.PushBack(13);
	//v.PushBack(14);

	//cout << v[1]+"" << " ";
	//cout << endl;
	
	bool ret = s.isValid("()");
	cout << ret << endl;
	return 0;
}
