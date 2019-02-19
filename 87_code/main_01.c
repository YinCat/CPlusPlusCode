#if 0
#include <stdio.h>
//
//int main()
//{
//	int a = 42;
//	printf("%d\n", printf("%d\n", a));
//}

void f(void)
{
	static int a = 3;
	static int b;
	int c;
	++a; ++b; ++c;
	printf("a=%d\n", a);//4 5 6
	printf("b=%d\n", b);//1 2 3
	printf("c=%d\n", c);//Ëæ»ú Ëæ»ú Ëæ»ú
}
int main(void)
{
	f();
	f();
	f();
}
#endif