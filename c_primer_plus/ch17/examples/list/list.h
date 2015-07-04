/*************************************************************************
    > File Name: list.h
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Mon 10 Nov 2014 08:34:24 PM CST
 ************************************************************************/

#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>

#define TSIZE 45
//特定程序的声明
struct film {
    char title[TSIZE];
    int rating;
};
//一般类型定义
typedef struct film Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef Node * List;
//初始化一个列表
void InitializeList(List * plist);
//判断列表是否为空列表
bool ListIsEmpty(const List * plist);
//判断列表是否已满
bool ListIsFull(const List * plist);
//确定列表中项目的个数
unsigned int ListItemCount(const List * plist);
//在列表尾部添加一个项目
bool AddItem(Item item, List * plist);
//把一个函数作用于列表中的每个项目
void Traverse(const List * plist, void (* pfun) (Item item));
//释放已分配的内存
void EmptyTheList(List * plist);

#endif
