#define WIN32_LEAN_AND_MEAN //�����������ڵ�������
#define _CRT_SECURE_NO_WARNINGS 1

#include <WinSock2.h>
#include <windows.h>

//ָ����̬���ӿ⣬Ҳ��������Ŀ����������
#pragma comment(lib, "ws2_32.lib") 


int main() {
	WORD ver = MAKEWORD(2,2);//�汾��2.2
	WSADATA data;
	//����windows��socket����
	WSAStartup(ver, &data);

	
	//�ر�windows��socket����
	WSACleanup();
	return 0;
}