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

void testmap_03()
{
	string str_arr[] = { "sort", "first", "sort", "second", "end", "end" };
	typedef map<string, int> CountMap;
	typedef map<string, int>::iterator CountMapIter;
	CountMap count_map;

	//1��find+insertͳ�ƴ���
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
	//2��ʹ��insertͳ�ƴ���
	for (const auto& e : str_arr){
		//auto ret = count_map2.insert(make_pair(e, 1));
		std::pair<map<string, int>::iterator, bool> ret = count_map2.insert(make_pair(e, 1));
		if (ret.second == false)//�������ʧ��
		{
			(ret.first->second)++;
		}
	}

	//3��ʹ��operatorͳ�ƴ���
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
	dict["hello"] = "���";
	dict["world"] = "����";
	cout << dict["hello"] << endl;
	//key�����ھͲ���
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
		//TODO�����ֲ���
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