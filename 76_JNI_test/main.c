#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))


#define simplify_fun(NAME) com_xpu_my_##NAME()
void com_xpu_my_write() {
	printf("write\n");
}

void com_xpu_my_read() {
	printf("read\n");
}


#define simlify_fun2(NAME)(NUM1,NUM2) com_xpu_my_##(NAME)(NUM1,NUM2)
int com_xpu_my_add(int n1, int n2) {
	return n1 + n2;
}

int com_xpu_my_sub(int n1, int n2) {
	return n1 - n2;
}

int main() {
	printf("%d\n", MAX(3, 5));

	simplify_fun(write);
	simplify_fun(read);

	//simlify_fun2(add)(2,3); error
	return 0;
}