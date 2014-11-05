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

//初始化一个带头结点的单链表
Status InitList(LinkList *L);
//释放一个结点
void FreeNode(LNode *p);
//清空单链表数据结点
Status ClearList(LinkList *L);
//销毁单链表
Status DestroyList(LinkList *L);
//打印单链表
void Display(LinkList *L);
//采用头插法在单链表头部插入一个数据结点
Status InsFirst(LinkList *L, ElemType e);
//删除第一个数据结点
Status DelFirst(LinkList *L);
//在单链表结尾追加结点
Status Append(LinkList *L, ElemType e);
//从单链表中删除首次匹配的指定结点
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
