#include "CommentConvert.h"

void DoNulState(FILE  *pfIn, FILE *pfOut, enum State *ps)
{
    int first = fgetc(pfIn);//��ȡһ���ַ�
    switch (first)
    {
        case '/':
        {
            int second = fgetc(pfIn);
            switch (second)
            {
                case '*':
                {
                    putc('/', pfOut);
                    putc('/', pfOut);
                    *ps = C_STATE;
                }
                    break;
                case '/':
                {
                    fputc(first, pfOut);
                    fputc(second, pfOut);
                    *ps = CPP_STATE;
                }
                    break;
                default:
                {
                    fputc(first, pfOut);
                    fputc(second, pfOut);
                }
                    break;
            }
        }
            break;
        case EOF://�����ļ�����
        {
            fputc(first, pfOut);
            *ps = END_STATE;
        }
            break;
        default:
        {
            fputc(first, pfOut);
        }
            break;
    }
}

void DoCState(FILE *pfIn, FILE *pfOut, enum State *ps)
{
    int first = fgetc(pfIn);
    switch (first)
    {
        case '*':
        {
            int second = fgetc(pfIn);
            switch (second)
            {
                case '/':
                {
                    int third = fgetc(pfIn);
                    if (third == '\n')
                    {
                        fputc(third, pfOut);
                    }
                    else//���ǻ��з����ֶ���ӻ��з�
                    {
                        fputc('\n', pfOut);
                        ungetc(third, pfIn);//�ѽ������жϵ��ַ��ͻ�����
                    }
                    *ps = NUL_STATE;
                }
                    break;
                default:
                {
                    putc(first, pfOut);
                    ungetc(second, pfIn);
                }
                    break;
            }
        }
            break;
        case '\n':
        {
            fputc(first, pfOut);
            fputc('/', pfOut);
            fputc('/', pfOut);
        }
            break;
        default:
            fputc(first, pfOut);
            break;
    }
}
void DoCppState(FILE *pfIn, FILE *pfOut, enum State *ps)
{
    int first = fgetc(pfIn);
    switch (first)
    {
        case '\n':
        {
            fputc(first, pfOut);
            *ps = NUL_STATE;
            break;
        }
        case EOF:
        {
            *ps = END_STATE;
            break;
        }
        default:
        {
            fputc(first, pfOut);
            break;
        }
    }
}

void CommentConver(FILE *pfIn, FILE *pfOut)
{
    enum State state = NUL_STATE;//�ʼ�ս���input�ļ�����Ϊ��״̬
    while (state != END_STATE)
    {
        switch (state)
        {
            case NUL_STATE:
            {
                DoNulState(pfIn, pfOut, &state);
            }
                break;
            case C_STATE:
            {
                DoCState(pfIn, pfOut, &state);
            }
                break;
            case CPP_STATE:
            {
                DoCppState(pfIn, pfOut, &state);
            }
                break;
        }
    }
}