#define WIN32_LEAN_AND_MEAN //避免引入早期的依赖库
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <string>

//指定动态链接库，也可以在项目配置中设置
#pragma comment(lib, "ws2_32.lib")

//struct DataPackage{
//	int age;
//	char name[32];
//};

enum MyCmd
{
	CMD_LOGIN,
	CMD_LOGOUT,
	CMD_ERROR
};

struct DataHeader {
	short dataLength;//数据长度
	short cmd;
};

struct Login {
	char userName[32];
	char passWord[32];
};

struct LoginResult {
	int result;
};

struct LogOut {
	char userName[32];
};

struct LogOutResult {
	int result;
};

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
	}
	else {
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

	char cmdBuf[1024] = { 0 };
	while (true) 
	{
		// 3 接收键盘输入
		std::cin >> cmdBuf;

		// 4 处理请求命令
		if (0 == strcmp(cmdBuf, "exit"))
		{
			std::cout << "收到退出命令，任务结束" << std::endl;
			break;
		}
		else if (0 == strcmp(cmdBuf, "login")) {
			Login login = { "Tim", "12580" };
			DataHeader dh = {sizeof(Login), CMD_LOGIN };
			//发送数据头
			send(_sock, (const char*)&dh, sizeof(DataHeader), 0);
			//发送正文
			send(_sock, (const char*)&login, sizeof(Login), 0);

			//接收服务器返回数据
			DataHeader retHeader = {};
			LoginResult loginRet = {};
			recv(_sock, (char*)&retHeader, sizeof(DataHeader), 0);
			recv(_sock, (char*)&loginRet, sizeof(LoginResult), 0);

			std::cout << "LoginResult:" << loginRet.result << std::endl;
		}
		else if (0 == strcmp(cmdBuf, "logout")) {
			LogOut logOut = {"Tim"};
			DataHeader  dh = { sizeof(LogOut) , CMD_LOGOUT };
			//发送数据头
			send(_sock, (const char*)&dh, sizeof(DataHeader), 0);
			//发送正文
			send(_sock, (const char*)&logOut, sizeof(LogOut), 0);

			//接收服务器返回数据
			DataHeader retHeader = {};
			LogOutResult logoutRet = {};
			recv(_sock, (char*)&retHeader, sizeof(DataHeader), 0);
			recv(_sock, (char*)&logoutRet, sizeof(LogOutResult), 0);

			std::cout << "LogoutResult:" << logoutRet.result << std::endl;
		}
		else {
			std::cout << "不支持的命令，请重新输入" << std::endl;
		}
	}
	
	// 7 关闭Socket
	closesocket(_sock);

	//8 关闭windows的socket环境
	WSACleanup();
	std::cout << "已退出， 任务结束" << std::endl;
	getchar();
	return 0;
}