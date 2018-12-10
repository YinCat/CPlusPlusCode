#define WIN32_LEAN_AND_MEAN //避免引入早期的依赖库
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>
#include <iostream>


#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
//指定动态链接库，也可以在项目配置中设置
#pragma comment(lib, "ws2_32.lib") 


int main() {
	WORD ver = MAKEWORD(2, 2);//版本号2.2
	WSADATA data;
	//启动windows的socket环境
	WSAStartup(ver, &data);

	// 1 建立一个socket( IPV4、面向数据流、TCP协议)
	SOCKET _sock = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);

	// 2 绑定接受客户端连接的端口 bind 
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET6;
	_sin.sin_port = htons(4567);//host to net unsigned short 转换字节序
	//_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;//全部IP均可访问

	if (SOCKET_ERROR == bind(_sock, (sockaddr*)&_sin, sizeof(_sin)) ) {
		//绑定失败
		std::cout << "错误，绑定网络端口失败" << std::endl;
	}
	else {
		std::cout << "绑定网络端口成功" << std::endl;
	}
	// 3 监听网络端口 listen 
	if (SOCKET_ERROR == listen(_sock, 5)) {
		std::cout << "错误，监听网络端口失败" << std::endl;
	}
	else {
		std::cout << "监听网络端口成功" << std::endl;
	}

	// 4 等待新客户端连接 accept 
	sockaddr_in clientAddr = {};
	int nAddr = sizeof(clientAddr);
	SOCKET _cSock = INVALID_SOCKET;

	char msgBuf[] = "hello,socket";

	while (true) {
		_cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddr);

		if (INVALID_SOCKET == _cSock) {
			std::cout << "错误，接收到无效客户端Socket" << std::endl;
		}
		std::cout << "新客户端加入:IP=" << inet_ntoa(clientAddr.sin_addr) << std::endl;
		// 5 向客户端发送一条数据send 
		send(_cSock, msgBuf, strlen(msgBuf) + 1, 0);
		//--循环4-5
	}
	
	// 6 关闭socket  closesocket
	closesocket(_sock);

	//关闭windows的socket环境
	WSACleanup();
	return 0;
}