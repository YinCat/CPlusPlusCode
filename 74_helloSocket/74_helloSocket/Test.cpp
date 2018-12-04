#define WIN32_LEAN_AND_MEAN //避免引入早期的依赖库
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>

//指定动态链接库，也可以在项目配置中设置
//#pragma comment(lib, "ws2_32.lib") 


int main() {
	WORD ver = MAKEWORD(2,2);//版本号2.2
	WSADATA data;
	//启动windows的socket环境
	WSAStartup(ver, &data);



	//关闭windows的socket环境
	WSACleanup();
	return 0;
}