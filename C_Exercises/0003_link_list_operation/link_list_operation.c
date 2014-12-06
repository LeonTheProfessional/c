/*************************************************************************
	> File Name: link_list_operation.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 24 Oct 2014 11:29:57 PM CST
 ************************************************************************/

#include "link_list_operation.h"

//��ʼ��һ����ͷ���ĵ�����
void Initialize(List * plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->item = 0;
    plist->len = 0;
}

//�жϵ������Ƿ�Ϊ��
bool IsEmpty(const List * plist)
{
    return (0 == plist->len);
}

//�жϵ������Ƿ�����
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

//ȷ��������Ԫ�ظ���
int ItemCount(const List * plist)
{
    return plist->len;
}

//����ͷ�巨�ڵ�����ͷ������һ����Ŀ
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

//����β�巨�ڵ�����β������һ����Ŀ
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

//�ͷ�һ�����
static void FreeNode(Node * node)
{
    if (node) {
        free(node);
        node = NULL;
    }
}

//��յ���������Ŀ
void ClearList(List * plist)
{
    while (plist->head->next) {
        Node * pnode = plist->head->next;
        plist->head->next = pnode->next;
        FreeNode(pnode);
        plist->len--;
    }
}

//���ٵ�����
void DestroyList(List * plist)
{
    ClearList(plist);
    FreeNode(plist->head);
}


//ɾ����һ����Ŀ
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

//ɾ�����һ����Ŀ
bool DeleteLastItem(List * plist)
{
    Node * pnode = plist->head->next;
    if (pnode) {
        Node * ptail = pnode->next;
        if (ptail) { //���ٺ��������ڵ�
            while (ptail->next) {
                pnode = pnode->next;
                ptail = ptail->next;                
            }
            pnode->next = NULL;
            FreeNode(ptail);
        } else { //ֻ��һ���ڵ�
            plist->head->next = NULL;
            FreeNode(pnode);
        }
        plist->len--;
        return true;
    } else {
        return false;
    }
}

//�ӵ�������ɾ���״�ƥ���ָ����Ŀ
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

//�Ե�����ÿ���ڵ�ִ��ָ������
void Traverse(const List * plist, void (* pfun) (Item item))
{
    Node * pnode = plist->head->next;
    while(pnode) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}
