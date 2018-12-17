#include <iostream>
#include <math.h>

using namespace std;

int StrToInt(string str) {
	int ret = 0;
	//"123"
	for(int i = str.length()-1;i>=0;i--){
		ret += str[i]*_Pow_int(10,str.length()-i);
	}
	return ret;
}

int main(){
	int ret = StrToInt("123");
	cout<<ret<<endl;
	return 0;
}