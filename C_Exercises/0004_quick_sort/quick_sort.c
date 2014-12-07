/*************************************************************************
	> File Name: quick_sort.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 07 Dec 2014 04:56:57 PM CST
 ************************************************************************/

#include "quick_sort.h"

//遍历数组，对每个数组元素执行指定操作
void traverse_array(int arr[], const int len, void (*pfun)(int * item))
{
    int i = 0;

    for (i = 0; i < len; i++) {
        (*pfun)(&arr[i]);
    }
}

static int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while (low != high) {
        while (low < high && arr[high] > pivot) {
            --high;
        }
        if (low < high) {
            arr[low] = arr[high];
            ++low;
        }
        while (low < high && arr[low] < pivot) {
            ++low;
        }
        if (low < high) {
            arr[high] = arr[low];
            --high;
        }
    }
    arr[low] = pivot;
    return low;
}

//采用快排算法对数组排序
void quick_sort(int arr[], int low, int high)
{
    int i = 0;
    if (low < high) {
        i = partition(arr, low, high);
        quick_sort(arr, low, high - 1);
        quick_sort(arr, low + 1, high);
    }
}

