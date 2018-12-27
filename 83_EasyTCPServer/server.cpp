#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
//TODO ��BUG

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
	std::cout << "�¿ͻ��˼���:cSock = " << _cSock << ",IP=" << inet_ntoa(clientAddr.sin_addr) << std::endl;

	char _recvBuf[1024] = { 0 };
	while (true) {
		// 5 ���տͻ��˵�����
		//������
		char szRecv[4096] = {0};
		int nLen = recv(_cSock, (char*)&szRecv, sizeof(DataHeader), 0);
		DataHeader *header = (DataHeader*)_recvBuf;
		if (nLen < 0) {
			std::cout << "�ͻ����˳�,�������" << std::endl;
			break;
		}
		//std::cout << "�յ����" << header.cmd << "���ݳ���:" << header.dataLength << std::endl;
		// 6 ��������
		if (nLen >= sizeof(DataHeader)) {
			//����ճ���Ŀ��ܣ������Ϣͬʱ����ʱ��
		}
		switch (header->cmd)
		{
		case CMD_LOGIN:
		{
			recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			Login *login = (Login*)szRecv;

			std::cout << "�յ����CMD_LOGIN" << " ���ݳ���:" << login->dataLength
				<< " UserName=" << login->userName << " Password=" << login->passWord << std::endl;
			//�����û���������֤
			LoginResult ret;
			//������Ϣ��
			send(_cSock, (char*)&ret, sizeof(LoginResult), 0);
		}
		break;
		case CMD_LOGOUT:
		{
			//recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			recv(_sock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			LogOut *logout = (LogOut*)szRecv;
			std::cout << "�յ����CMD_LOGOUT " << "���ݳ���:" << logout->dataLength
				<< " UserName=" << logout->userName << std::endl;
			//�����û���������֤
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

	// 8 �ر�socket
	closesocket(_sock);

	//�ر�windows��socket����
	WSACleanup();
	std::cout << "�ͻ������˳����������" << std::endl;

	getchar();
	return 0;
}