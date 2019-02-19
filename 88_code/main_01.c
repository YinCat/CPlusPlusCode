#include <stdio.h>
//#include "head_01.h"
//int main()
//{
//	int a = 42;
//	printf("%d\n", printf("%d\n", a));
//}

//void f(void)
//{
//	static int a = 3;
//	static int b;
//	int c;
//	++a; ++b; ++c;
//	printf("a=%d\n", a);//4 5 6
//	printf("b=%d\n", b);//1 2 3
//	printf("c=%d\n", c);//Ëæ»ú Ëæ»ú Ëæ»ú
//}
//
//int main(void)
//{
//	f();
//	f();
//	f();
//}

//
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}

//void foo(void)
//{
//	int a;
//	printf("%d\n", a);
//}
//
//void bar(void)
//{
//	int a = 42;
//}
//
//int main(void)
//{
//	bar();
//	foo();
//}


//int b(void)
//{ 
//	printf("3"); 
//	return 3;
//}
//int c(void) 
//{ 
//	printf("4");
//	return 4; 
//}
//int main(void)
//{
//	int a = b() + c();
//	printf("%d\n", a);
//}

//int main(void)
//{
//	//int a = 41; 
//	//a++;
//	//printf("%d\n", a);
//
//	//int a = 41; a++ & printf("%d\n", a);
//	//int a = 41; a++ && printf("%d\n", a);
//	//int a = 41; if (a++ < 42) printf("%d\n", a);
//	int a = 41; a = a++; printf("%d\n", a);
//}

//int main()
//{
//	struct X { int a; char b; int c; };
//	printf("%d,", sizeof(struct X));
//	struct Y { int a; char b; int c; char d; };
//	printf("%d\n", sizeof(struct Y));
//}

//#include <stdio.h>
//int main(void)
//{
//	int a[5];
//	printf("%d\n", a);
//	printf("%d\n", a + 1);
//	printf("%d\n", &a);
//	printf("%d\n", &a + 1);
//}

//int fun()
//{
//	int x;
//	return x == (1 && x);
//}

//int x;
//int fun()
//{
//	int s;
//	printf("%d\n", s);
//}
//int main()
//{
//	
//	fun();
//}

int x = 5;
int fun() {
	int x = 3;
	{
		extern int x;
		return x;
	}
}

int main()
{
	printf("%d\n",fun());
}