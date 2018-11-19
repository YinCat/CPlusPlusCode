#include<xpu.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS 
//����˵��:  
//in Դ�ַ���  
//out �����������ַ���  
//outlen out���Ĵ�С  
//src Ҫ�滻���ַ���  
//dst �滻��ʲô�ַ���
char *strrpl(char *in, char *out, int outlen, const char *src, char *dst)  
{  
	char *p = in;  
	unsigned int  len = outlen - 1;  

	// �⼸�μ������Ϸ���  
	if((NULL == src) || (NULL == dst) || (NULL == in) || (NULL == out))  
	{  
		return NULL;  
	}  
	if((strcmp(in, "") == 0) || (strcmp(src, "") == 0))  
	{  
		return NULL;  
	}  
	if(outlen <= 0)  
	{  
		return NULL;  
	}  

	while((*p != '\0') && (len > 0))  
	{  
		if(strncmp(p, src, strlen(src)) != 0)  
		{  
			int n = strlen(out);  

			out[n] = *p;  
			out[n + 1] = '\0';  

			p++;  
			len--;  
		}  
		else  
		{  
			strcat_s(out, outlen, dst);  
			p += strlen(src);  
			len -= strlen(dst);  
		}  
	}  
	return out;  
}  
void loopThrough(char* path,char* findType)
{
	char currentPath[200],subPath[200];
	WIN32_FIND_DATA findFileData;
	HANDLE hFind;

	sprintf(currentPath,"%s\\%s",path,findType);  
	hFind=FindFirstFile(currentPath,&findFileData);

	if(hFind==INVALID_HANDLE_VALUE) 
	{
		printf("INVALID HANDLE!\n");
		return;
	}
	else 
	{
		while(TRUE)
		{
			if(findFileData.dwFileAttributes
				& FILE_ATTRIBUTE_DIRECTORY) 
			{
				if(findFileData.cFileName[0]!='.')
				{
					sprintf(subPath,"%s\\%s",path,findFileData.cFileName);
					loopThrough(subPath,findType);
				}
			}
			else 
			{
				char arr[200] = {0};
				char arr2[100] = {0};
				char arr3[100] = {0};
				FILE *pfIn = NULL;
				FILE *pfOut = NULL;
				strrpl(path,arr,100,"\\","\\\\");
				strcat(arr,"\\\\");
				strcat(arr,findFileData.cFileName);
				pfIn = fopen(arr,"r"); 
				if(pfIn == NULL)
				{
					perror("loopThrough::fopen->pfIn");
					exit(EXIT_FAILURE);
				}
				strrpl(path,arr2,100,"\\�ҵ��ĵ�\\","\\\\�ҵ��ĵ�_other\\\\");
				strcpy(arr3,arr2);//arr3�д�ľ����ļ��е�·��
				strcat(arr2,"\\\\");
				strcat(arr2,findFileData.cFileName);//arr2���������ļ���·��������
				pfOut = fopen(arr2,"w");
				
				if(pfOut == NULL)
				{
					char mkdir_str[100] = {0};
					strcpy(mkdir_str,"mkdir ");
					strcat(mkdir_str,arr3);
					system(mkdir_str);
					pfOut = fopen(arr2,"w");
				}
				if(pfOut == NULL)
				{
					perror("loopThrough::fopen");
					exit(EXIT_FAILURE);
				}
				//��ʼת��
				CommentConver(pfIn,pfOut);
			}

			if(!FindNextFile(hFind,&findFileData)) 
			{
				break;
			}
		}
		FindClose(hFind);
	}
}


//����˵����
//��һ��������Դ�ļ���
//�ڶ���������Ŀ���ļ�����
int main(int argc,char* argv[])
{
	printf("%s %s\n",argv[1],argv[2]);
	loopThrough("D:\\�ҵ��ĵ�","*.*");
	system("pause");
	return 0;
}