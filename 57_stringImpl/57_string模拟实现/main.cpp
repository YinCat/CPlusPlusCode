#include "String.h"
#include <string>
#include <vector>


using namespace xpu;
using namespace std;

int main(){
	String s("hello");
	String s1 = "hello";
	String s2(s1);
	int i = 2018;
	cin >> i;

#if i
	cout << i << endl;
#endif
	cout << s1 << endl;
	cout << s2 << endl;
	

	string s3("helloworld");
	cout << s3.size() << endl;
	cout << s3.length() << endl;

	vector<int> v(10, 2);
	return 0;
}

