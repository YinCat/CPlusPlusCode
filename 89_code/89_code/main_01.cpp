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

	//�����ڲ���set��
	if (s1.find(10) != s1.end())
	{
		cout << "10����" << endl;
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
	dict.insert(type("hello", "���"));
	dict.insert(type("word", "����"));
	dict.insert(type("insert", "����"));
	dict.insert(type("find", "����"));

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

	dict.insert(make_pair("hello", "���"));
	dict.insert(make_pair("word", "����"));
	dict.insert(make_pair("insert", "����"));
	dict.insert(make_pair("find", "����"));
	
	
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
			cout << "���ģ�" << it->second << endl;
		}
		else{
			cout << "���ڴʿ���" << endl;
		}
	}

	//map����޸�Value
	auto it = dict.find("hello");
	if (it != dict.end())
	{
		dict["hello"] = "���ѽ";
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