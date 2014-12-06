/*************************************************************************
    > File Name: link_list_operation.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Fri 24 Oct 2014 11:29:06 PM CST
 ************************************************************************/

#ifndef __LINK_LIST_OPERATION_H__
#define __LINK_LIST_OPERATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**************�������Ͷ���**************/

typedef int Item;

struct node
{
	Item item;
	struct node * next;
};

typedef struct node Node;

struct list
{
	Node * head;
	int len;
};

typedef struct list List;

/***********����ԭ������***************/

//��ʼ��һ����ͷ���ĵ�����
void Initialize(List * plist);

//�жϵ������Ƿ�Ϊ��
bool IsEmpty(const List * plist);

//�жϵ������Ƿ�����
bool IsFull(const List * plist);

//ȷ��������Ԫ�ظ���
int ItemCount(const List * plist);

//����ͷ�巨�ڵ�����ͷ������һ����Ŀ
bool AddItemHead(const Item item, List * plist);

//����β�巨�ڵ�����β������һ����Ŀ
bool AddItemTail(const Item item, List * plist);

//��յ���������Ŀ
void ClearList(List * plist);

//���ٵ�����
void DestroyList(List * plist);

//ɾ����һ����Ŀ
bool DeleteFirstItem(List * plist);

//ɾ�����һ����Ŀ
bool DeleteLastItem(List * plist);

//�ӵ�������ɾ���״�ƥ���ָ����Ŀ
bool RemoveItem(Item item, List * plist);

//�Ե�����ÿ���ڵ�ִ��ָ������
void Traverse(const List * plist, void (* pfun) (Item item));

#endif
