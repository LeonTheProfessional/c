/*************************************************************************
    > File Name: sort.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Fri 09 Jan 2015 09:17:40 PM CST
 ************************************************************************/

#ifndef SORT_H_
#define SORT_H_

#define RANGE 100

//快速排序
void quick_sort(int * a, int len);

//冒泡排序
void bubble_sort(int * a, int len);

//直接插入排序
void direct_insert_sort(int * a, int len);

//选择排序
void select_sort(int * a, int len);

//堆排序
void heap_sort(int * a, int len);

//计数排序
void counting_sort(int * a, int len);

#endif
