#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <string>

//ָ����̬���ӿ⣬Ҳ��������Ŀ����������
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
	short dataLength;//���ݳ���
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
	WORD ver = MAKEWORD(2, 2);//�汾��2.2
	WSADATA data;
	//����windows��socket����
	WSAStartup(ver, &data);
	// 1 ����һ��socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == _sock)
	{
		std::cout << "Error������socketʧ��" << std::endl;
		return -1;
	}
	else {
		std::cout << "����socket�ɹ�" << std::endl;
	}

	// 2 ���ӷ�����
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	int ret = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret)
	{
		std::cout << "Error�����ӷ�����ʧ�ܣ�" << std::endl;
		return -1;
	}
	else {
		std::cout << "���ӷ������ɹ�" << std::endl;
	}

	char cmdBuf[1024] = { 0 };
	while (true)
	{
		// 3 ���ռ�������
		std::cin >> cmdBuf;

		// 4 ������������
		if (0 == strcmp(cmdBuf, "exit"))
		{
			std::cout << "�յ��˳�����������" << std::endl;
			break;
		}
		else if (0 == strcmp(cmdBuf, "login")) {
			Login login;
			strcpy(login.userName, "Tim");
			strcpy(login.passWord, "123456");

			//��������
			send(_sock, (const char*)&login, sizeof(Login), 0);

			//���շ�������������
			LoginResult loginRet = {};
			recv(_sock, (char*)&loginRet, sizeof(LoginResult), 0);

			std::cout << "LoginResult:" << loginRet.result << std::endl;
		}
		else if (0 == strcmp(cmdBuf, "logout")) {
			LogOut logOut;
			strcpy(logOut.userName, "Tim");

			//��������
			send(_sock, (const char*)&logOut, sizeof(LogOut), 0);

			//���շ�������������
			LogOutResult logoutRet = {};
			recv(_sock, (char*)&logoutRet, sizeof(LogOutResult), 0);

			std::cout << "LogoutResult:" << logoutRet.result << std::endl;
		}
		else {
			std::cout << "��֧�ֵ��������������" << std::endl;
		}
	}

	// 7 �ر�Socket
	closesocket(_sock);

	//8 �ر�windows��socket����
	WSACleanup();
	std::cout << "���˳��� �������" << std::endl;
	getchar();
	return 0;
}