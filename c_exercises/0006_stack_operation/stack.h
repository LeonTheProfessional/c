/*************************************************************************
    > File Name: stack.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Sun 07 Dec 2014 09:28:24 PM CST
 ************************************************************************/

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

typedef int Item;

struct node {
    Item item;
    struct node * next;
};

typedef struct node Node;
typedef struct node * Stack;

void init(Stack * stack);

void clear(Stack * stack);

void destroy(Stack * stack);

bool is_empty(const Stack stack);

void push(Stack * stack, const Item item);

bool pop(Stack * stack, Item * item);

bool top(const Stack * stack, Item * item);

#endif
