/*************************************************************************
	> File Name: link_list_operation.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 24 Oct 2014 11:29:57 PM CST
 ************************************************************************/

#include "link_list_operation.h"

//初始化一个带头结点的单链表
void Initialize(List * plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->item = 0;
    plist->len = 0;
}

//判断单链表是否为空
bool IsEmpty(const List * plist)
{
    return (0 == plist->len);
}

//判断单链表是否已满
bool IsFull(const List * plist)
{
    Node * ptest;
    ptest = (Node *)malloc(sizeof(Node));
    if (!ptest) {
        return true;
    } else {
        free(ptest);
        return false;
    }
}

//确定单链表元素个数
int ItemCount(const List * plist)
{
    return plist->len;
}

//采用头插法在单链表头部插入一个项目
bool AddItemHead(const Item item, List * plist)
{
    Node * pnode = (Node *)malloc(sizeof(Node));
    if (!pnode) {
        return false;
    } else {
        pnode->item = item;
        pnode->next = plist->head->next;
        plist->head->next = pnode;
        plist->len++;
        return true;
    }
}

//采用尾插法在单链表尾部插入一个项目
bool AddItemTail(const Item item, List * plist)
{
    Node * pnode = (Node *)malloc(sizeof(Node));
    if (!pnode) {
        return false;
    } else {
        Node * ptr;
        ptr = plist->head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        pnode->item = item;
        pnode->next = NULL;
        ptr->next = pnode;
        plist->len++;
        return true;
    }
}

//释放一个结点
static void FreeNode(Node * node)
{
    if (node) {
        free(node);
        node = NULL;
    }
}

//清空单链表中项目
void ClearList(List * plist)
{
    while (plist->head->next) {
        Node * pnode = plist->head->next;
        plist->head->next = pnode->next;
        FreeNode(pnode);
        plist->len--;
    }
}

//销毁单链表
void DestroyList(List * plist)
{
    ClearList(plist);
    FreeNode(plist->head);
}


//删除第一个项目
bool DeleteFirstItem(List * plist)
{
    Node * pnode = plist->head->next;
    if (pnode) {
        plist->head->next = pnode->next;
        FreeNode(pnode);
        plist->len--;
        return true;
    }
    return false;
}

//删除最后一个项目
bool DeleteLastItem(List * plist)
{
    Node * pnode = plist->head->next;
    if (pnode) {
        Node * ptail = pnode->next;
        if (ptail) { //至少含有两个节点
            while (ptail->next) {
                pnode = pnode->next;
                ptail = ptail->next;                
            }
            pnode->next = NULL;
            FreeNode(ptail);
        } else { //只有一个节点
            plist->head->next = NULL;
            FreeNode(pnode);
        }
        plist->len--;
        return true;
    } else {
        return false;
    }
}

//从单链表中删除首次匹配的指定项目
bool RemoveItem(Item item, List * plist)
{
    Node * pfirst = plist->head;
    Node * psecond = pfirst->next;
    while (psecond) {
        if (psecond->item == item) {
            pfirst->next = psecond->next;
            FreeNode(psecond);
            plist->len--;
            return true;
        }
        pfirst = pfirst->next;
        psecond = psecond->next;
    }
    return false;
}

//对单链表每个节点执行指定操作
void Traverse(const List * plist, void (* pfun) (Item item))
{
    Node * pnode = plist->head->next;
    while(pnode) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}
