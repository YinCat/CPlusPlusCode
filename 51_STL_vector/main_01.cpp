#include<iostream>
#include <vector>
#include <locale>
#include <string>
#include "String.h"

using namespace std;

class Solution {
public:
#if 0
	string addStrings(string num1, string num2) {//111 889
		string ret;
		int min = num1.length() < num2.length() ? num1.length() : num2.length();
		int max = num1.length() > num2.length() ? num1.length() : num2.length();
		string maxstr = num1.length() == max ? num1 : num2;
		int *arr = new int[max];
		//99-->2
		// 9--->1
		//arr[0] = 8;flag = 1;
		int flag = 0;
		for (int i = max-1; i >= 0; i--){
			arr[i] = (flag + (num1[i] - 48 + num2[i] - 48)) % 10;
			cout << "arr["<< i <<"]" << arr[i] << endl;
			if ((flag + num1[i] - 48 + num2[i] - 48) >= 10)
				flag = 1;
			else
				flag = 0;
		}

        	//9999
			//   9
			//arr[4] = { *,*,*,8}//flag = 1;
		//for (int i = max - min; i >= 0; i--){
		//	arr[i] = (flag + maxstr[i] - 48) % 10;
		//	cout << "arr[" << i << "]" << arr[i] << endl;
		//	if ((flag + num1[i] - 48 + num2[i] - 48) >= 10)
		//		flag = 1;
		//	else
		//		flag = 0;
		//}
		

		//°Ñint[]×ªÎª×Ö·û´®
		for (int i = 0; i < max; i++)
			ret += arr[i] + 48;
		if (flag == 1)
			return "1" + ret;
		return ret;
	}

#endif

	string addStrings(string num1, string num2) {
		string ret;
		int min = num1.length() < num2.length() ? num1.length() : num2.length();
		int max = num1.length() > num2.length() ? num1.length() : num2.length();
		
		int *arr = new int[min];
		int flag = 0;
		for (int i = min - 1; i >= 0; i--){
			arr[i] = (flag + (num1[i] - 48 + num2[i] - 48)) % 10;
			cout << "arr[" << i << "]" << arr[i] << endl;
			if ((flag + num1[i] - 48 + num2[i] - 48) >= 10)
				flag = 1;
			else
				flag = 0;
		}

		int *arr2 = new int[max - min];
		string maxstr = num1.length() == max ? num1 : num2;
		string other = maxstr.substr(0, max - min);

		for (int i = other.length()-1; i >= 0; i--){
			arr2[i] = (flag + other[i] - 48) % 10;
			cout << "arr2[" << i << "]" << arr[i] << endl;
			if ((flag + other[i] - 48) >= 10)
				flag = 1;
			else
				flag = 0;
		}
		return "";
	}
};

int main(){
	//string s = "Test";
	//cout << s.size() - 1 << endl;
	//for (size_t i = 0; i < s.length(); i++){
	//	s[i] = toupper(s[i]);
	//}
	//cout << s << endl;
	
	string num1 = "99";
	string num2 = "9";
	cout << Solution().addStrings(num1, num2) << endl;
	cout << "\00" << endl;
	return 0;
}

int main01(){
	String s;
	String s1("2w2w2");
	cout << s << endl;
	return 0;
}