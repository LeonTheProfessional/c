/*************************************************************************
    > File Name: queue.h
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Mon 10 Nov 2014 11:30:54 PM CST
 ************************************************************************/

#pragma c9x on
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

//typedef int Item;
typedef struct item {
    long arrive;
    int processtime;
} Item;

#define MAXQUEUE 10

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct queue {
    Node * front;//指向队首的指针
    Node * rear;//指向队尾的指针
    int items;//队列中项目的个数
} Queue;

//初始化队列
void InitializeQueue(Queue * pq);
//检查队列是否已满
bool QueueIsFull(const Queue * pq);
//检查队列是否为空
bool QueueIsEmpty(const Queue * pq);
//确定队列中项目的个数
int QueueItemCount(const Queue * pq);
//向队列尾端添加项目
bool EnQueue(Item item, Queue * pq);
//从队列首端删除项目
bool DeQueue(Item * pitem, Queue * pq);
//清空队列
void EmptyTheQueue(Queue * pq);

#endif
