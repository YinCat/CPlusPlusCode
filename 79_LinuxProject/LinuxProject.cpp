#include <iostream>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "helloworld: " << i  << endl;
	}
	return 0;
}