/*************************************************************************
	> File Name: main.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 07 Dec 2014 10:00:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include "stack.h"

static void clear_buffer();

int main(void)
{
    Stack stack;
    Item item;

    init(&stack);
    while (1 == scanf("%d", &item)) {
        push(&stack, item);
    }
    clear_buffer();
    while (stack->next) {
        pop(&stack, &item);
        printf("%d\t", item);
    }
    printf("\n");

    clear(&stack);
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
    }

    while (1 == scanf("%d", &item)) {
        push(&stack, item);
    }
    clear_buffer();
    top(&stack, &item);
    printf("%d\n", item);

    if (is_empty(stack)) {
        printf("Stack is empty!\n");
    } else {
        destroy(&stack);
        printf("Stack has been destroyed!\n");
    }

    return 0;
}
static void clear_buffer()
{
    int c = 0;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}
