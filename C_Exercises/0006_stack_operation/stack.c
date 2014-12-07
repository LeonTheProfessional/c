/*************************************************************************
	> File Name: stack.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 07 Dec 2014 09:43:28 PM CST
 ************************************************************************/

#include <stdlib.h>
#include "stack.h"

void init(Stack * stack)
{
   *stack = (Node *)malloc(sizeof(Node));
}

void clear(Stack * stack)
{
    while ((*stack)->next) {
       Item item;
       pop(stack, &item);
    }
}

void destroy(Stack * stack)
{
    clear(stack);
    free(*stack);
    (*stack)->next = NULL;
}

bool is_empty(const Stack stack)
{
    return stack->next == NULL;
}

void push(Stack * stack, const Item item)
{
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = (*stack)->next;
    (*stack)->next = new_node;
}

bool pop(Stack * stack, Item * item)
{
    if ((*stack)->next) {
        Node * temp = (*stack)->next;
        *item = temp->item;
        (*stack)->next = temp->next;
        free(temp);
        temp->next = NULL;
        return true;
    } else {
        return false;
    }
}

bool top(const Stack * stack, Item * item)
{
    if ((*stack)->next) {
        *item = (*stack)->next->item;
        return true;
    } else {
        return false;
    }
}
