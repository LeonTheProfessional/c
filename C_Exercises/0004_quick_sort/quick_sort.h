/*************************************************************************
    > File Name: quick_sort.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Sat 06 Dec 2014 11:51:37 AM CST
 ************************************************************************/

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

//遍历数组，对每个数组元素执行指定操作
void traverse_array(int arr[], const int len, void (*pfun)(int * item));

//采用快排算法对数组排序
void quick_sort(int arr[], int low, int high);

#endif;
