/*************************************************************************
	> File Name: list.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 10 Nov 2014 08:42:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//局部函数原型
static void CopyToNode(Item item, Node * pnode);

//接口函数实现

//把列表设置为空列表
void InitializeList(List * plist)
{
    *plist = NULL;
}

//如果列表为空则返回真
bool ListIsEmpty(const List * plist)
{
    if (*plist == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//如果列表已满则返回真
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
    {
        full = false;
    }
    else
    {
        full = false;
    }
    free(pt);

    return full;
}

//返回节点数
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

//创建存放项目的节点，并把它添加到由plist指向的列表尾部
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        return false;
    }

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)
    {
        *plist = pnew;
    }
    else
    {
        while (scan->next != NULL)
        {
            scan = scan->next;
        }
        scan->next = pnew;
    }

    return true;
}

//访问每个节点并对它们分别执行有pfun指向的函数
void Traverse(const List * plist, void (* pfun) (Item item))
{
    Node * pnode = *plist;
    while (pnode != NULL)
    {
        (* pfun)(pnode->item);
        pnode = pnode->next;
    }
}

//释放由malloc()分配的内存
void EmptyTheList(List * plist)
{
    Node * psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

//局部函数实现

//把一个项目复制到一个节点中
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}
