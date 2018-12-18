#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>

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

int main() {
	WORD ver = MAKEWORD(2, 2);//�汾��2.2
	WSADATA data;
	//����windows��socket����
	WSAStartup(ver, &data);

	// 1 ����һ��socket( IPV4��������������TCPЭ��)
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 2 �󶨽��ܿͻ������ӵĶ˿� bind 
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);//host to net unsigned short ת���ֽ���
								//_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;//ȫ��IP���ɷ���

	if (SOCKET_ERROR == bind(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in))) {
		//��ʧ��
		std::cout << "���󣬰�����˿�ʧ��" << std::endl;
	}
	else {
		std::cout << "������˿ڳɹ�" << std::endl;
	}
	// 3 ��������˿� listen 
	if (SOCKET_ERROR == listen(_sock, 5)) {
		std::cout << "���󣬼�������˿�ʧ��" << std::endl;
	}
	else {
		std::cout << "��������˿ڳɹ�" << std::endl;
	}

	// 4 �ȴ��¿ͻ������� accept 
	sockaddr_in clientAddr = {};
	int nAddrLen = sizeof(clientAddr);
	SOCKET _cSock = INVALID_SOCKET;

	
	

	_cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);

	if (INVALID_SOCKET == _cSock) {
		std::cout << "���󣬽��յ���Ч�ͻ���Socket" << std::endl;
	}
	std::cout << "�¿ͻ��˼���:cSock = " << _cSock <<",IP=" << inet_ntoa(clientAddr.sin_addr) << std::endl;

	char _recvBuf[1024] = { 0 };
	while (true) {
		// 5 ���տͻ��˵�����
		DataHeader header = {};
		int nLen = recv(_cSock, (char*)&header, sizeof(DataHeader), 0);
		if (nLen < 0) {
			std::cout << "�ͻ����˳�,�������" << std::endl;
			break;
		}
		std::cout << "�յ����" << header.cmd << "���ݳ���:" << header.dataLength << std::endl;
		// 6 ��������
		switch (header.cmd) 
		{
			case CMD_LOGIN:
			{
				Login login = {};
				recv(_cSock, (char*)&login, sizeof(Login), 0);
				//�����û���������֤
				LoginResult ret = { 1 };
				//������Ϣͷ
				send(_cSock, (char*)&header, sizeof(DataHeader), 0);
				//������Ϣ��
				send(_cSock, (char*)&ret, sizeof(LoginResult), 0);
			}
			break;
			case CMD_LOGOUT:
			{
				LogOut logout = {};
				recv(_cSock, (char*)&logout, sizeof(LogOut), 0);
				//�����û���������֤
				LogOutResult ret = { 1 };
				//������Ϣͷ
				send(_cSock, (char*)&header, sizeof(DataHeader), 0);
				//������Ϣ��
				send(_cSock, (char*)&ret, sizeof(LogOutResult), 0);
			}
			break;
			default:
				header.cmd = CMD_ERROR;
				header.dataLength = 0;
				//������Ϣͷ
				send(_cSock, (char*)&header, sizeof(DataHeader), 0);
				break;
		}
	}

	// 8 �ر�socket  closesocket
	closesocket(_sock);

	//�ر�windows��socket����
	WSACleanup();
	std::cout << "�ͻ������˳����������" << std::endl;

	getchar();
	return 0;
}