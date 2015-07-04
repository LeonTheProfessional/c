/*************************************************************************
    > File Name: tree.h
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Tue 11 Nov 2014 12:20:10 AM CST
 ************************************************************************/
//二叉搜索树，树中不允许有相同的项目
#ifndef __TREE_H__
#define __TREE_H__

#include <stdbool.h>

typedef struct item {
    char petname[20];
    char petkind[20];
} Item;

#define MAXITEMS 10

typedef struct node {
    Item item;
    struct node * left;
    struct node * right;
} Node;

typedef struct tree {
    Node * root;
    int size;
} Tree;

//把一个树初始化为空树
void InitializeTree(Tree * ptree);

//确定树是否为空
bool TreeIsEmpty(const Tree * ptree);

//确定树是否已满
bool TreeIsFull(const Tree * ptree);

//确定树中项目的个数
int TreeItemCount(const Tree * ptree);

//向树中添加一个项目
bool AddItem(const Item * pi, Tree * ptree);

//在树中查找一个项目
bool InTree(const Item * pi, const Tree * ptree);

//从树中删除一个项目
bool DeleteItem(const Item * pi, Tree * ptree);

//把一个函数作用于树中每一个项目
void Traverse(const Tree * ptree, void (* pfun) (Item item));

//从树中删除所有节点
void DeleteAll(Tree * ptree);

#endif
