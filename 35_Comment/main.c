#include "CommentConvert.h"

void test()
{
	FILE  *pfIn = fopen("D:\\VSworkspace\\35_Comment\\input.c","r");
	FILE  *pfOut = fopen("D:\\VSworkspace\\35_Comment\\output.c","w");
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
int main() {
    test();
    printf("Hello, World!\n");
    return 0;
}