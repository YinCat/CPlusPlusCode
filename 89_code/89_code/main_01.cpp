#if 0
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

void testmap_03()
{
	string str_arr[] = { "sort", "first", "sort", "second", "end", "end" };
	typedef map<string, int> CountMap;
	typedef map<string, int>::iterator CountMapIter;
	CountMap count_map;

	//1、find+insert统计次数
	for (const auto& e : str_arr)
	{
		CountMapIter it = count_map.find(e);
		if (it != count_map.end())
		{
			it->second++;
		}
		else{
			count_map.insert(make_pair(e, 1));
		}
	}

	CountMap count_map2;
	//2、使用insert统计次数
	for (const auto& e : str_arr){
		//auto ret = count_map2.insert(make_pair(e, 1));
		std::pair<map<string, int>::iterator, bool> ret = count_map2.insert(make_pair(e, 1));
		if (ret.second == false)//如果插入失败
		{
			(ret.first->second)++;
		}
	}

	//3、使用operator统计次数
	CountMap count_map3;
	for (const auto& e : str_arr){
		count_map3[e]++;
	}
}

void testmap_04()
{

	typedef map<string, int>::iterator CountMapIter;
	typedef map<string, string> Dict;

	Dict dict;
	dict["hello"] = "你好";
	dict["world"] = "世界";
	cout << dict["hello"] << endl;
	//key不存在就插入
	//cout << dict["s"] << endl;

	vector<int> v;
	v.resize(4, 0);
	for (int e : v){
		cout << e << ", ";
	}
}

void benchmark()
{
	//size_t n;
}
#include <list>
long fbnq(long n)
{
	long a = 0;
	long b = 1;
	long c = 1;
	for (long i = 1; i < n; i++){
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}
long fun(int num)
{
	list<long> list;
	int num2 = num;
	for (int i = 0; i < 36; i++)
		list.push_back(fbnq(i));

	for (auto e : list)
	{
		if (e == num)
			return 0;
	}

	int step_sub = 0;
	bool flag_sub = true;
	while (num-- > 0 && flag_sub)
	{
		step_sub++;
		//TODO：二分查找
		for (auto e : list)
		{
			if (e == num){
				flag_sub = false;
				break;
			}
		}
	}

	int step_add = 0;
	bool flag_add = true;
	while (num2++ < 1000000 && flag_add)
	{
		step_add++;
		for (auto e : list)
		{
			if (e == num2){
				flag_add = false;
				break;
			}
		}
	}
	return step_add < step_sub ? step_add : step_sub;
}
int main(void)
{
	//testSet();
	//testfind();
	//testmultiset();
	//testmap();
	//testmap_02();
	//testmap_03();
	//testmap_03();
	cout << fun(17) << endl;
	return 0;
}
#endif