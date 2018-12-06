#define WIN32_LEAN_AND_MEAN //避免引入早期的依赖库
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>

//指定动态链接库，也可以在项目配置中设置
//#pragma comment(lib, "ws2_32.lib") 


int main() {
	WORD ver = MAKEWORD(2, 2);//版本号2.2
	WSADATA data;
	//启动windows的socket环境
	WSAStartup(ver, &data);

	// 1 建立一个socket( IPV4、面向数据流、TCP协议)
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 2 绑定接受客户端连接的端口 bind 
	sockaddr_in _sin = {};
	bind(_sock, (sockaddr*)&_sin, sizeof(_sin));//14:05
	// 3 监听网络端口 listen 
	// 4 等待新客户端连接 accept 
	// 5 向客户端发送一条数据send 
	//--循环4-5
	// 6 关闭socket  closesocket


	//关闭windows的socket环境
	WSACleanup();
	return 0;
}