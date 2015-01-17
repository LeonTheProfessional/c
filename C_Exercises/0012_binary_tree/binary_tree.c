/*************************************************************************
	> File Name: binary_tree.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 10 Jan 2015 08:14:54 PM CST
 ************************************************************************/

#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
};

void create_tree(Tree *T)
{
    *T = (Tree)malloc(sizeof(struct TreeNode));
    if (*T == NULL) {
        perror("create_tree:malloc");
        exit(EXIT_FAILURE);
    }
    if (scanf("%d", &((*T)->data)) != 1) {
        return ;
    }
    create_tree(&((*T)->lchild));
    create_tree(&((*T)->rchild));
}

void empty_tree(Tree *T)
{
    if (*T != NULL) {
        empty_tree(&((*T)->lchild));
        empty_tree(&((*T)->rchild));
        free(*T);
    }
}

void pre_order(Tree T)
{
    if (T) {
        printf("%d\t", T->data);
        pre_order(T->lchild);
        pre_order(T->rchild);
    }
}

void post_order(Tree T)
{
    if (T) {
        post_order(T->lchild);
        post_order(T->rchild);
        printf("%d\t", T->data);
    }
}

void mid_order(Tree T)
{
    if (T) {
        mid_order(T->lchild);
        printf("%d\t", T->data);
        mid_order(T->rchild);
    }
}

void level_order(Tree T)
{
    const int MAX = 128;
    Tree queue[MAX];
    int front, rear;
    Tree temp;

    front = rear = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = T;
    if (T) {
        while (front != rear) {
            front = (front + 1) % MAX;
            temp = queue[front];
            printf("%d\t", temp->data);
            if (temp->lchild) {
                rear = (rear + 1) % MAX;
                queue[rear] = temp->lchild;
            }
            if (temp->rchild) {
                rear = (rear + 1) % MAX;
                queue[rear] = temp->rchild;
            }
        }
    }
}
