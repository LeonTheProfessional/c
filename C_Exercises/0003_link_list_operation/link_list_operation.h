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

/**************数据类型定义**************/

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

/***********函数原型声明***************/

//初始化一个带头结点的单链表
void Initialize(List * plist);

//判断单链表是否为空
bool IsEmpty(const List * plist);

//判断单链表是否已满
bool IsFull(const List * plist);

//确定单链表元素个数
int ItemCount(const List * plist);

//采用头插法在单链表头部插入一个项目
bool AddItemHead(const Item item, List * plist);

//采用尾插法在单链表尾部插入一个项目
bool AddItemTail(const Item item, List * plist);

//清空单链表中项目
void ClearList(List * plist);

//销毁单链表
void DestroyList(List * plist);

//删除第一个项目
bool DeleteFirstItem(List * plist);

//删除最后一个项目
bool DeleteLastItem(List * plist);

//从单链表中删除首次匹配的指定项目
bool RemoveItem(Item item, List * plist);

//对单链表每个节点执行指定操作
void Traverse(const List * plist, void (* pfun) (Item item));

#endif
