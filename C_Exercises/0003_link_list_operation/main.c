/*************************************************************************
	> File Name: main.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 24 Oct 2014 11:31:10 PM CST
 ************************************************************************/

#include "link_list_operation.h"

int main(int argc, char * argv[])
{
	LinkList L;
    //InitList
    if (!InitList(&L))
    {
        printf("InitList ERROR!\n");
    }
    else
    {
        printf("InitList OK! LinkList Length: %d\n", L.len);
    }
    //InsFirst
    InsFirst(&L, 1);
    InsFirst(&L, 2);
    InsFirst(&L, 3);
    InsFirst(&L, 4);
    Display(&L);
    DelFirst(&L);
    Display(&L);
    Append(&L, 4);
    Display(&L);
    Remove(&L, 2);
    Display(&L);

    //Destroy List
    if (!DestroyList(&L))
    {
        printf("DestroyList ERROR!\n");
    }
    else
    {
        printf("DestroyList OK!\n");
    }
	return 0;
}
