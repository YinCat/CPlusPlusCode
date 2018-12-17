#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>
#include <iostream>
#include <string>

//ָ����̬���ӿ⣬Ҳ��������Ŀ����������
#pragma comment(lib, "ws2_32.lib")

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
		else {
			// 5 �������������������
			send(_sock, cmdBuf, strlen(cmdBuf)+1, 0);
		}

		// 6 ���ܷ�������Ϣ
		char recvBuf[1024] = { 0 };
		int nlen = recv(_sock, recvBuf, 1024, 0);
		if (nlen > 0) {
			std::cout << "���յ����ݣ�" << nlen << "�ֽ�" << std::endl;
			std::cout << std::string(recvBuf) << std::endl;
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