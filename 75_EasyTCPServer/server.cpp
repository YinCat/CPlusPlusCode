#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>

//ָ����̬���ӿ⣬Ҳ��������Ŀ����������
#pragma comment(lib, "ws2_32.lib") 


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

	if (SOCKET_ERROR == bind(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in)) ) {
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

	char msgBuf[] = "Hello,socket";
	int length = strlen(msgBuf) + 1;
	while (true) {
		_cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);

		if (INVALID_SOCKET == _cSock) {
			std::cout << "���󣬽��յ���Ч�ͻ���Socket" << std::endl;
		}
		std::cout << "�¿ͻ��˼���:IP=" << inet_ntoa(clientAddr.sin_addr) << std::endl;
		// 5 ��ͻ��˷���һ������send 
		send(_cSock, msgBuf, length, 0);
		//--ѭ��4-5
	}
	
	// 6 �ر�socket  closesocket
	closesocket(_sock);

	//�ر�windows��socket����
	WSACleanup();
	return 0;
}