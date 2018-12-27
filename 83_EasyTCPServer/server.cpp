#define WIN32_LEAN_AND_MEAN //避免引入早期的依赖库
#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
//TODO 有BUG

//指定动态链接库，也可以在项目配置中设置
#pragma comment(lib, "ws2_32.lib") 

enum MyCmd
{
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_ERROR
};

struct DataHeader {
	short dataLength;//数据长度
	//short MaxLength;
	short cmd;
};

struct Login :public DataHeader {
	Login() {
		dataLength = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char userName[32];
	char passWord[32];
};

struct LoginResult :public DataHeader {
	LoginResult() {
		dataLength = sizeof(LoginResult);
		cmd = CMD_LOGIN_RESULT;
		result = 0;
	}
	int result;
};

struct LogOut :public DataHeader {
	LogOut() {
		dataLength = sizeof(LogOut);
		cmd = CMD_LOGOUT;
	}
	char userName[32];
};

struct LogOutResult :public DataHeader {
	LogOutResult() {
		dataLength = sizeof(LogOutResult);
		cmd = CMD_LOGOUT_RESULT;
		result = 0;
	}
	int result;
};

int main() {
	WORD ver = MAKEWORD(2, 2);//版本号2.2
	WSADATA data;
	//启动windows的socket环境
	WSAStartup(ver, &data);

	// 1 建立一个socket( IPV4、面向数据流、TCP协议)
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 2 绑定接受客户端连接的端口 bind 
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);//host to net unsigned short 转换字节序
								//_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;//全部IP均可访问

	if (SOCKET_ERROR == bind(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in))) {
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
	int nAddrLen = sizeof(clientAddr);
	SOCKET _cSock = INVALID_SOCKET;

	_cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);

	if (INVALID_SOCKET == _cSock) {
		std::cout << "错误，接收到无效客户端Socket" << std::endl;
	}
	std::cout << "新客户端加入:cSock = " << _cSock << ",IP=" << inet_ntoa(clientAddr.sin_addr) << std::endl;

	char _recvBuf[1024] = { 0 };
	while (true) {
		// 5 接收客户端的数据
		//缓冲区
		char szRecv[4096] = {0};
		int nLen = recv(_cSock, (char*)&szRecv, sizeof(DataHeader), 0);
		DataHeader *header = (DataHeader*)_recvBuf;
		if (nLen < 0) {
			std::cout << "客户端退出,任务结束" << std::endl;
			break;
		}
		//std::cout << "收到命令：" << header.cmd << "数据长度:" << header.dataLength << std::endl;
		// 6 处理请求
		if (nLen >= sizeof(DataHeader)) {
			//处理粘包的可能（多个消息同时发的时候）
		}
		switch (header->cmd)
		{
		case CMD_LOGIN:
		{
			recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			Login *login = (Login*)szRecv;

			std::cout << "收到命令：CMD_LOGIN" << " 数据长度:" << login->dataLength
				<< " UserName=" << login->userName << " Password=" << login->passWord << std::endl;
			//忽略用户名密码验证
			LoginResult ret;
			//发送消息体
			send(_cSock, (char*)&ret, sizeof(LoginResult), 0);
		}
		break;
		case CMD_LOGOUT:
		{
			//recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			recv(_sock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			LogOut *logout = (LogOut*)szRecv;
			std::cout << "收到命令：CMD_LOGOUT " << "数据长度:" << logout->dataLength
				<< " UserName=" << logout->userName << std::endl;
			//忽略用户名密码验证
			LogOutResult ret;
			send(_cSock, (char*)&ret, sizeof(LogOutResult), 0);
		}
		break;
		default:
			DataHeader header = { 0, CMD_ERROR};
			send(_cSock, (char*)&header, sizeof(DataHeader), 0);
			break;
		}
	}

	// 8 关闭socket
	closesocket(_sock);

	//关闭windows的socket环境
	WSACleanup();
	std::cout << "客户端已退出，任务结束" << std::endl;

	getchar();
	return 0;
}