#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int main(){
	FILE* s = fopen("a.txt", "w+");
	assert(s != NULL);
	return 0;
}