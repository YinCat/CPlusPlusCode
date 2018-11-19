#include "CommentConvert.h"

void DoNulState(FILE *pfIn,FILE *pfOut,enum State *ps)
{
	int first = fgetc(pfIn);
	switch(first)
	{
	case '/':
		{
			int second = fgetc(pfIn);
			switch(second)
			{
			case '*':
				{
					putc('/',pfOut);
					putc('/',pfOut);
					*ps = C_STATE;
				}
				break;
			case '/':
				{
					fputc(first,pfOut);
					fputc(second,pfOut);
					*ps = CPP_STATE;
				}
				break;
			default:
				{
					fputc(first,pfOut);
					fputc(second,pfOut);
				}
				break;
			}
		}
		break;

	case EOF:	//到了文件结束
		{
			fputc(first,pfOut);
			*ps = END_STATE;
			break;
		}
	default:
		fputc(first,pfOut);
		break;
	}
}

void DoCState(FILE *pfIn,FILE *pfOut,enum State *ps)
{
	int first = fgetc(pfIn);
	switch(first)
	{
	case '*':
		{
			int second = fgetc(pfIn);
			switch(second)
			{
			case '/':
				{
					int third = fgetc(pfIn);
					if(third == '\n')
					{
						fputc(third,pfOut);
					}
					else //不是换行的需要手动加换行
					{
						fputc('\n',pfOut);
						ungetc(third,pfIn);//把将来做判断的字符送回流中
					}
					*ps = NUL_STATE;
				}
				break;
			default:
				{
					putc(first,pfOut);
					ungetc(second,pfIn);
				}
				break;
			}
		}
		break;
	case '\n':
		{
			fputc(first,pfOut);
			fputc('/',pfOut);
			fputc('/',pfOut);
		}
		break;
	default:
		fputc(first,pfOut);
		break;
	}
}

void DoCppState(FILE *pfIn,FILE *pfOut,enum State *ps)
{
	int first = fgetc(pfIn);
	switch(first)
	{
	case '\n':
		{
			fputc(first,pfOut);
			*ps = NUL_STATE;
		}
		break;
	case EOF:
		*ps = END_STATE;
		break;
	default:
		fputc(first,pfOut);
		break;
	}
}

void CommentConver(FILE *pfIn,FILE *pfOut)
{
	enum State state = NUL_STATE;
	while(state != END_STATE)//结束状态的时候就已经处理完毕
	{
		switch(state)
		{
		case NUL_STATE:	//无状态
			{
				DoNulState(pfIn,pfOut,&state);
			}
			break;
		case C_STATE:
			{
				DoCState(pfIn,pfOut,&state);
			}
			break;
		case CPP_STATE:
			{
				DoCppState(pfIn,pfOut,&state);
			}
			break;
		}

	}
}