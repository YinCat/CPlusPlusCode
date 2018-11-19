#include "CommentConvert.h"

void test()
{
	FILE  *pfIn = fopen("input.c","r");
	FILE  *pfOut = fopen("output.c","w"); 
	if(pfIn == NULL)
	{
		perror("open file for read");
	}
	if(pfOut == NULL)
	{
		perror("open file for write");
		fclose(pfIn); //Ҫ�Ǵ�ʧ�ܾ͹رյ�һ���Ѿ��򿪵��ļ���
		pfIn = NULL;
		exit(EXIT_FAILURE);
	}
	//ע��ת��
	CommentConver(pfIn,pfOut);


	//�ر��ļ���
	fclose(pfIn);
	fclose(pfOut);
	pfIn = NULL;
	pfOut = NULL;
}

//�ݹ�����ļ�
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
				strrpl(path,arr,100,"\\","\\\\");
				//arr�����ļ�·��
				//_mkdir(path);
				//printf("%s\\\\%s\n",arr,findFileData.cFileName);
				strcat(arr,"\\");
				strcat(arr,findFileData.cFileName)
				FILE *pfIn = fopen(arr,"r");
				if(pfIn == NULL)
				{
					
				}
			}

			if(!FindNextFile(hFind,&findFileData)) 
			{
				break;
			}
		}
		FindClose(hFind); // close HANDLE
	}
}
// ����˵��:  
// in�� Դ�ַ���  
// out, �����������ַ���  
// outlen��out���Ĵ�С  
// src��Ҫ�滻���ַ���  
// dst���滻��ʲô�ַ���  
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
int main(int argc,char* argv[])
{
	//test();
	//loopThrough("D:\\�ҵ��ĵ�","*.*");
	//_mkdir("Hello");
	fopen("D:\\�ҵ��ĵ�\\����ĵ�\\Hello2.txt","w");

	return 0;
}