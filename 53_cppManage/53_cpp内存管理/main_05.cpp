#include <stdio.h>
#include <iostream>

using namespace std;
class StackOnly{
public:

private:

};

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6};
	for (auto e : arr){
		cout << e << " ";
	}
	return 0;
}