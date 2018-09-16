#include "LinedkList.h"


void test01()
{
    ListNode *plist = NULL;
    ListNode const *pos = NULL;
    InitList(&plist);
    PushBack(&plist,11);
    PushBack(&plist,22);
    PushBack(&plist,33);
    PushBack(&plist,44);
    PrintList(plist);

    PopBack(&plist);
    PrintList(plist);
    PopBack(&plist);
    PrintList(plist);
    pos = Find(plist,22);
    printf("Fine ret = %d\n",pos->data);
    PushFront(&plist,99);
    PopFront(&plist);
    Destory(&plist);
}


void test02() {
    ListNode *plist = NULL;
    ListNode *pos = NULL;
    InitList(&plist);
    PushBack(&plist, 11);
    PushBack(&plist, 22);
    PushBack(&plist, 33);
    PushBack(&plist, 33);
    PushBack(&plist, 44);
    PushBack(&plist, 33);
    PrintList(plist);

    Remove(&plist,33);
    RemoveAll(&plist,33);
    PrintList(plist);

}
int main(int argc,char* atgv[])
{
    test02();
    return 0;
}