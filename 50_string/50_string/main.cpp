#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void fun(){
	string s1 = "hello";//explicit
	string s2("hello");
	string s3(s2);
	string s4;
	//string s5(); error
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	//cout << s5 << endl;
}

void fun2(){
	string s = "1234";
	string::iterator start = s.begin();

	auto it = s.begin();
	//while (start < s.end()){
	//	cout << *start << endl;
	//	++start;
	//}
	while (it < s.end()){
		cout << *it << endl;
		++it;
	}
}

void fun3(){
	vector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);

	auto it = v.begin();
	while (it < v.end()){
		cout << *it << endl;
		it++;
	}
	auto end = v.end();


}

//void fun4(const string& num){
void fun4(){
	//string::iterator it = num.begin();//error 因为迭代器可以修改数据，所以使用从const修饰是不行的
	//const_iterator begin()const;//const 修饰的是this指针
	//cbegin是c98之后的const iterator
	string s("hello");
	for (auto e : s){
		cout << e << endl;
	}
}

void fun5(){
	std::map<std::string, std::vector<std::string>> strMap;
	vector<string> v;
	
	std::map<std::string, std::vector<std::string>>::iterator it = strMap.begin();
	std::map<std::string, std::vector<std::string>>::iterator end = strMap.end();

	for (auto e : strMap){
		cout << e.first << endl;
	}

}

void fun6(){
	string s("hello");
	s.push_back(' ');
	s.append("world");
	cout << s << endl;
	s += 'x';
	s += " cpp";
	cout << s << endl;
	string num = "1234";
	int ret = atoi(num.c_str());//将cpp的字符串变成c风格的字符串
	cout << ret << endl;
}

void fun7(){
	string s = "http://106.12.202.93/solo-2.9.5/admin-index.do#tools/category-list";
	size_t start = s.find("://");
	if (start == string::npos){
		cout << "url incalid" << endl;
		return;
	}
	start += 3;
	size_t finsh = s.find('/', start);
	cout << s.substr(start, finsh - start) << endl;
}

void fun8(){
	string s;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	int i = s.capacity();//增容一次？？
	s.reserve(300);
	s += 2;
	for (int i = 0; i < 200; i++){
		s += 'c';
		if (i != s.capacity()){
			cout << s.capacity() << endl;
			i = s.capacity();
		}
	}
}
int main()
{
	//fun();
	//fun2();
	//fun3();
	//fun4();
	//fun5();
	//fun6();
	//fun7();
	fun8();
	return 0;
}