#define WIN32_LEAN_AND_MEAN //避免引入早期的依赖库
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <string>

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
			Login login;
			strcpy(login.userName, "Tim");
			strcpy(login.passWord, "123456");

			//发送正文
			send(_sock, (const char*)&login, sizeof(Login), 0);

			//接收服务器返回数据
			LoginResult loginRet = {};
			recv(_sock, (char*)&loginRet, sizeof(LoginResult), 0);

			std::cout << "LoginResult:" << loginRet.result << std::endl;
		}
		else if (0 == strcmp(cmdBuf, "logout")) {
			LogOut logOut;
			strcpy(logOut.userName, "Tim");

			//发送正文
			send(_sock, (const char*)&logOut, sizeof(LogOut), 0);

			//接收服务器返回数据
			LogOutResult logoutRet = {};
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