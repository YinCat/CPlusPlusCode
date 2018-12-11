#include <iostream>

using namespace std;


template<int N>
class Sum {
public:
	enum{ RET = N+Sum<N-1>::RET};
};

//ÌØ»¯
template<>
class Sum<1> {
public:
	enum { RET = 1 };
};


int main() {
	cout << Sum<10>::RET << endl;
	cout << 441992 - 442493<< endl;
	cout << 441992 - 443179 << endl;

	int i = 0;
	cout << typeid(i).name() << endl;
	return 0;
}