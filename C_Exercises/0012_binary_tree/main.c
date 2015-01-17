/*************************************************************************
	> File Name: main.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 10 Jan 2015 08:49:34 PM CST
 ************************************************************************/

#include <stdio.h>
#include "binary_tree.h"

int main(void)
{
    Tree tree;

    printf("Create Tree (non-integer to stop):\n");
    create_tree(&tree);

    printf("\nPre Order:\n");
    pre_order(tree);

    printf("\nMid Order:\n");
    mid_order(tree);

    printf("\nPost Order:\n");
    post_order(tree);

    printf("\nLever Order:\n");
    level_order(tree);

    empty_tree(&tree);

    return 0;
}
