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

#define OK 1;
#define ERROR 0;

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
} LNode, *Link;

typedef struct
{
	Link head;
	int len;
} LinkList;

//��ʼ��һ����ͷ���ĵ�����
Status InitList(LinkList *L);
//�ͷ�һ�����
void FreeNode(LNode *p);
//��յ��������ݽ��
Status ClearList(LinkList *L);
//���ٵ�����
Status DestroyList(LinkList *L);
//��ӡ������
void Display(LinkList *L);
//����ͷ�巨�ڵ�����ͷ������һ�����ݽ��
Status InsFirst(LinkList *L, ElemType e);
//ɾ����һ�����ݽ��
Status DelFirst(LinkList *L);
//�ڵ������β׷�ӽ��
Status Append(LinkList *L, ElemType e);
//�ӵ�������ɾ���״�ƥ���ָ�����
Status Remove(LinkList *L, ElemType e);
/*
Status InsBefore(LinkList *L, int i, ElemType e);
Status InsAfter(LinkList * L, int i, ElemType e);
Status IsEmpty(LinkList L);
int Length(LinkList L);
LNode * GetHead(LinkList L);
LNode * GetLast(LinkList L);
LNode * PriorPos(LinkList L, Link p);
LNode * NextPos(LinkList L, Link p);
Status LocateElem(LinkList L, ElemType e, Status (* compare)(ElemType, ElemType));
Status Traverse(LinkList L, Status (* visit)());
*/
#endif
