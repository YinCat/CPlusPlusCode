#define WIN32_LEAN_AND_MEAN //避免引入早期的依赖库
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <string>

//指定动态链接库，也可以在项目配置中设置
#pragma comment(lib, "ws2_32.lib")

int main() 
{
	WORD ver = MAKEWORD(2, 2);//版本号2.2
	WSADATA data;
	//启动windows的socket环境
	WSAStartup(ver, &data);
	// 1 建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == _sock) 
	{
		std::cout << "Error，建立socket失败" << std::endl;
		return -1;
	}else{
		std::cout << "建立socket成功" << std::endl;
	}

	// 2 连接服务器
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	int ret = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret)
	{
		std::cout << "Error，连接服务器失败，" << std::endl;
		return -1;
	}
	else {
		std::cout << "连接服务器成功" << std::endl;
	}
	//接受服务器信息
	char recvBuf[1024] = { 0 };
	int nlen = recv(_sock, recvBuf, 1024, 0);
	if (nlen > 0) {
		std::cout << "接收到数据：" << nlen << "字节" << std::endl;
		std::cout << std::string(recvBuf) << std::endl;
	}
	//关闭Socket
	closesocket(_sock);

	//关闭windows的socket环境
	WSACleanup();
	while (1);
	return 0;
}