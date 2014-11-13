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

typedef struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct list
{
	Node * head;
	int len;
} List;

/***********����ԭ������***************/

//��ʼ��һ����ͷ���ĵ�����
void Initialize(List * plist);

//�жϵ������Ƿ�Ϊ��
bool IsEmpty(const List * plist);

//�жϵ������Ƿ�����
bool IsFull(const List * plist);

//ȷ��������Ԫ�ظ���
unsigned int ItemCount(const List * plist);

//����ͷ�巨�ڵ�����ͷ������һ����Ŀ
bool AddItemHead(Item item, List * plist);

//����β�巨�ڵ�����β������һ����Ŀ
bool AddItemTail(Item item, List * plist);

//�ͷ�һ�����
void FreeNode(Node * node);

//��յ���������Ŀ
bool ClearList(List * plist);

//���ٵ�����
bool DestroyList(List * plist);

//��ӡ��Ŀ��Ϣ
void DisplayItem(Item * item);

//ɾ����һ����Ŀ
bool DeleteFirstItem(List * plist);

//ɾ�����һ����Ŀ
bool DeleteLastItem(List * plist);

//�ӵ�������ɾ���״�ƥ���ָ����Ŀ
bool Remove(Item item, List * plist);

#endif
