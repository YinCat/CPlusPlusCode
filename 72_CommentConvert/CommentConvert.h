#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#define  _CRT_SECURE_NO_WARNINGS


#include <xpu.h>
#include <Windows.h>

enum State{
	NUL_STATE, //ÎÞ×¢ÊÍ×´Ì¬
	C_STATE, //C×¢ÊÍ×´Ì¬
	CPP_STATE,//C++×¢ÊÍ×´Ì¬
	END_STATE, //½áÊø×´Ì¬
};

void CommentConver(FILE *pfIn,FILE *pfOut);

void DoNulState(FILE *pfIn,FILE *pfOut,enum State *ps);
void DoCState(FILE *pfIn,FILE *pfOut,enum State *ps);
void DoCppState(FILE *pfIn,FILE *pfOut,enum State *ps);



#endif //__COMMENT_CONVERT_H__