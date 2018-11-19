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
		fclose(pfIn); //要是打开失败就关闭第一个已经打开的文件流
		pfIn = NULL;
		exit(EXIT_FAILURE);
	}
	//注释转换
	CommentConver(pfIn,pfOut);


	//关闭文件流
	fclose(pfIn);
	fclose(pfOut);
	pfIn = NULL;
	pfOut = NULL;
}

//递归遍历文件
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
				//arr就是文件路径
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
// 参数说明:  
// in， 源字符串  
// out, 存放最后结果的字符串  
// outlen，out最大的大小  
// src，要替换的字符串  
// dst，替换成什么字符串  
char *strrpl(char *in, char *out, int outlen, const char *src, char *dst)  
{  
	char *p = in;  
	unsigned int  len = outlen - 1;  

	// 这几段检查参数合法性  
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
	//loopThrough("D:\\我的文档","*.*");
	//_mkdir("Hello");
	fopen("D:\\我的文档\\你的文档\\Hello2.txt","w");

	return 0;
}