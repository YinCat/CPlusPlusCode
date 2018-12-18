#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <string>

//ָ����̬���ӿ⣬Ҳ��������Ŀ����������
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
	short dataLength;//���ݳ���
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
			Login login = { "Tim", "12580" };
			DataHeader dh = {sizeof(Login), CMD_LOGIN };
			//��������ͷ
			send(_sock, (const char*)&dh, sizeof(DataHeader), 0);
			//��������
			send(_sock, (const char*)&login, sizeof(Login), 0);

			//���շ�������������
			DataHeader retHeader = {};
			LoginResult loginRet = {};
			recv(_sock, (char*)&retHeader, sizeof(DataHeader), 0);
			recv(_sock, (char*)&loginRet, sizeof(LoginResult), 0);

			std::cout << "LoginResult:" << loginRet.result << std::endl;
		}
		else if (0 == strcmp(cmdBuf, "logout")) {
			LogOut logOut = {"Tim"};
			DataHeader  dh = { sizeof(LogOut) , CMD_LOGOUT };
			//��������ͷ
			send(_sock, (const char*)&dh, sizeof(DataHeader), 0);
			//��������
			send(_sock, (const char*)&logOut, sizeof(LogOut), 0);

			//���շ�������������
			DataHeader retHeader = {};
			LogOutResult logoutRet = {};
			recv(_sock, (char*)&retHeader, sizeof(DataHeader), 0);
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