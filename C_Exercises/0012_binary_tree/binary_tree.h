/*************************************************************************
    > File Name: binary_tree.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Sat 10 Jan 2015 08:11:20 PM CST
 ************************************************************************/

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

struct TreeNode;
typedef struct TreeNode *Tree;

void create_tree(Tree *T);
void empty_tree(Tree *T);
void pre_order(Tree T);
void post_order(Tree T);
void mid_order(Tree T);
void level_order(Tree T);

#endif
