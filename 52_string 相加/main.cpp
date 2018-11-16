#include <iostream>
#include <string>
using namespace std;

class Demo{
public:
	void swap(char& c1, char& c2){
		char tmp = c1;
		c1 = c2;
		c2 = tmp;
	}
	string reverse(string& s1){
		string ret(s1);
		int start = 0;
		int end = s1.length() - 1;
		while (start < end){
			swap(ret[start], ret[end]);
			start++;
			end--;
		}
		return ret;
	}

	
	string addStrings(string num1, string num2) {
		string num_1 = reverse(num1);
		string num_2 = reverse(num2);
		int max_length = num1.length() > num2.length() ? num1.length() : num2.length();
		int min_length = num1.length() < num2.length() ? num1.length() : num2.length();

		string more_length = num_1.length() == max_length ? num_1 : num_2;

		int *arr = new int[max_length];

		int flag = 0;
		for (int i = 0; i < max_length; i++){
			if (i < min_length){
				arr[i] = (flag + (num_1[i] - 48 + num_2[i] - 48)) % 10;
				if ((flag + num_1[i] - 48 + num_2[i] - 48) >= 10)
					flag = 1;
				else
					flag = 0;
			}
			else{
				arr[i] = (flag + more_length[i] - 48) % 10;
				if ((flag + more_length[i] - 48) >= 10)
					flag = 1;
				else
					flag = 0;
			}
		}
		string ret;
		for (int i = max_length - 1; i >= 0; i--){
			ret += (arr[i] + 48);
		}
		if (flag == 1)
			return "1" + ret;
		else
			return ret;
	}

	string reverseStr(string s, size_t k) {
		string ret = reverse(s, 0, k-1);
		string ret2(ret);
		if (ret.length() - k < k){
			ret2 = reverse(ret, k, ret2.length() - 1);
			return ret2;
		}
		else if ((s.length() < 2 * k && s.length() > k) || s.length() == k){
			return reverse(s, 0, k - 1);
		}

	}
};

/*
 * ����һ���ַ�����һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰk���ַ����з�ת��
 * ���ʣ������ k ���ַ�����ʣ�������ȫ����ת��
 * �����С�� 2k �����ڻ���� k ���ַ�����תǰ k ���ַ�������ʣ����ַ�����ԭ����
 */
int main(){
	//cout << Demo().addStrings("9", "99") << endl;
	cout << Demo().reverseStr("abcdefg", 2) << endl;
	string s = "hello";
	for (auto e : s){ }
	return 0;
}