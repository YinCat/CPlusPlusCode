#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>

//ָ����̬���ӿ⣬Ҳ��������Ŀ����������
//#pragma comment(lib, "ws2_32.lib") 


int main() {
	WORD ver = MAKEWORD(2, 2);//�汾��2.2
	WSADATA data;
	//����windows��socket����
	WSAStartup(ver, &data);

	// 1 ����һ��socket( IPV4��������������TCPЭ��)	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	// 2 �󶨽��ܿͻ������ӵĶ˿� bind 	sockaddr_in _sin = {};	bind(_sock, (sockaddr*)&_sin, sizeof(_sin));//14:05	// 3 ��������˿� listen 	// 4 �ȴ��¿ͻ������� accept 	// 5 ��ͻ��˷���һ������send 	//--ѭ��4-5	// 6 �ر�socket  closesocket


	//�ر�windows��socket����
	WSACleanup();
	return 0;
}