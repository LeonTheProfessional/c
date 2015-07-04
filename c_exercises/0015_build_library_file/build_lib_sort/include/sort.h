/*************************************************************************
    > File Name: sort.h
    > Author: Sam Wong
    > Mail: ncepuwanghui@gmail.com 
    > Blog: http://samwong.im 
    > Created Time: Sun 18 Jan 2015 02:24:14 PM CST
 ************************************************************************/

#ifndef SORT_H_
#define SORT_H_

extern void swap(int *a, int *b);

void simple_insert_sort(int *a, int len);
void select_sort(int *a, int len);
void bubble_sort(int *a, int len);
void quick_sort(int *a, int len);
void heap_sort(int *a, int len);

#endif
