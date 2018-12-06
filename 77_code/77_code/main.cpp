#include <iostream>
#include <math.h>

using namespace std;

int StrToInt(string str) {
	if (str.length() == 0)
		return 0;
	int flag = 0;
	if (str[0] == '+' || str[0] == '-') {
		str = str.substr(1, str.length() - 1);
		flag = str[0] == '-' ? 1 : 0;
	}
	int ret = 0;
	//"+123"
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i]<'0' || str[i]>'9')
			return 0;
		ret += (str[i] - '0') * pow(10, str.length() - i - 1);
	}
	if (flag) 
		return  -ret;
	return ret;
}

int main() {
	int ret = StrToInt("-123");
	cout << ret << endl;
	return 0;
}