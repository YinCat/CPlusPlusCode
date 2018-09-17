#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#define  _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<assert.h>
#include <Windows.h>

enum State{
	NUL_STATE, //��ע��״̬
	C_STATE, //Cע��״̬
	CPP_STATE,//C++ע��״̬
	END_STATE, //����״̬
};

void CommentConver(FILE *pfIn,FILE *pfOut);

void DoNulState(FILE *pfIn,FILE *pfOut,enum State *ps);
void DoCState(FILE *pfIn,FILE *pfOut,enum State *ps);
void DoCppState(FILE *pfIn,FILE *pfOut,enum State *ps);



#endif //__COMMENT_CONVERT_H__