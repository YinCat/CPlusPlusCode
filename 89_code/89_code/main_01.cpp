#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

void testSet(){
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(20);
	s1.insert(3);
	s1.insert(14);
	s1.insert(25);
	s1.insert(6);

	auto start = s1.begin();
	auto end = s1.end();

	//while (start != end){
	//	cout << *start << endl;
	//	start++;
	//}

	for (auto e : s1){
		cout << e << ", ";
	}
}

void testfind()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);
	s1.insert(70);

	//查找在不在set中
	if (s1.find(10) != s1.end())
	{
		cout << "10存在" << endl;
		s1.erase(10);
	}

	auto start = s1.begin();
	for (auto e : s1){
		cout << e << endl;
	}
}
void testmultiset()
{
	multiset<int> s1;
	s1.insert(40);
	s1.insert(10);
	s1.insert(20);
	s1.insert(20);
	s1.insert(30);
	vector<int> ret;
	for (auto s : s1){
		cout << s << ", ";
		ret.push_back(s);
	}
	cout <<"----------------"<< endl;
}

typedef pair<string, string> type;

void testmap(){
	map<string, string> dict;
	dict.insert(type("hello", "你好"));
	dict.insert(type("word", "世界"));
	dict.insert(type("insert", "插入"));
	dict.insert(type("find", "查找"));

	auto start = dict.begin();
	auto end = dict.end();
	while (start != end){
		cout << "Key=" << (*start).first << ", Value=" << (*start).second << endl;
		cout << "Key=" << start->first << ", Value=" << start->second << endl;
		start++;
	}
	cout << endl;
	for (auto e : dict){
		cout << "Key=" << e.first << ", Value=" << e.second << endl;
	}
	string str;
	while (cin >> str)
	{

	}
}


void testmap_02(){
	map<string, string> dict;

	dict.insert(make_pair("hello", "你好"));
	dict.insert(make_pair("word", "世界"));
	dict.insert(make_pair("insert", "插入"));
	dict.insert(make_pair("find", "查找"));
	
	
	map<string, string>::iterator  start = dict.begin();
	auto end = dict.end();
	while (start != end){
		cout << "Key=" << (*start).first << ", Value=" << (*start).second << endl;
		cout << "Key=" << start->first << ", Value=" << start->second << endl;
		start++;
	}
	cout << endl;
	for (auto e : dict){
		cout << "Key=" << e.first << ", Value=" << e.second << endl;
	}
	string str;
	while (cin >> str)
	{
		auto it = dict.find(str);
		if (it != dict.end()){
			cout << "译文：" << it->second << endl;
		}
		else{
			cout << "不在词库中" << endl;
		}
	}

	//map如何修改Value
	auto it = dict.find("hello");
	if (it != dict.end())
	{
		dict["hello"] = "你好呀";
	}
	for (auto s : dict){
		cout << s.first << "=" << s.second << endl;
	}
}
int main(void)
{
	//testSet();
	//testfind();
	//testmultiset();
	//testmap();
	testmap_02();
	return 0;
}