/*************************************************************************
	> File Name: sort.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 09 Jan 2015 09:21:58 PM CST
 ************************************************************************/

#include "sort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//交换两个整数
static void swap(int * a, int * b);
//快排一趟划分
static int partition(int * a, int low, int high);
//采用传入区间的方法排序
static void quick_sort_by_partition(int * a, int low, int high);
//调整堆
static void sift(int * a, int low, int high);
static void heap_adjust(int * a, int i, int heap_size);

//快速排序
void quick_sort(int * a, int len)
{
    quick_sort_by_partition(a, 0, len - 1);
}

//冒泡排序
void bubble_sort(int * a, int len)
{
    int i, j;
    bool flag;

    for (i = 0; i < len; ++i)
    {
        flag = false;
        for (j = len - 1; j > i; --j)
        {
            if (a[j] < a[j-1])
            {
                swap(&a[j], &a[j-1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

//直接插入排序
void direct_insert_sort(int * a, int len)
{
    int i, j, temp;

    for (j = 1; j < len; ++j)
    {
        temp = a[j];
        for (i = j - 1; i >= 0 && temp < a[i]; --i)
        {
            a[i+1] = a[i];
        }
        ++i;
        a[i] = temp;
    }
}

//选择排序
void select_sort(int * a, int len)
{
    int i, j, min;

    for (i = 0;i < len; ++i)
    {
        min = i;
        for (j = i + 1; j < len; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&a[i], &a[min]);
        }
    }
}

//堆排序
void heap_sort(int * a, int len)
{
    int i;

    for (i = len / 2; i >= 0; --i)
    {
        //sift(a, i, len - 1);
        heap_adjust(a, i, len - 1);
    }
    for (i = len - 1; i >= 1; --i)
    {
        swap(&a[0], &a[i]);
        //sift(a, 0, i - 1);
        heap_adjust(a, 0, i - 1);
    }
}

//计数排序
void counting_sort(int * a, int len)
{
    int * num;
    int i, j;

    num = (int *) malloc(sizeof(int) * RANGE);
    memset(num, 0, (sizeof(int) * RANGE));
    for (i = 0; i < len; ++i)
    {
        num[a[i]]++;
    }
    for(i = 0, j = 0; i < RANGE; ++i)
    {
        while (num[i] && j < len)
        {
            a[j++] = i;
            num[i]--;
        }
    }
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int * a, int low, int high)
{
    int pivot = a[low];

    while (low != high)
    {
        while (low < high && a[high] > pivot)
        {
            --high;
        }
        if (low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while (low < high && a[low] < pivot)
        {
            ++low;
        }
        if (low < high)
        {
            a[high] = a[low];
            --high;
        }
    }
    a[low] = pivot;

    return low;
}

void quick_sort_by_partition(int * a, int low, int high)
{
    int i = 0;
    if (low < high)
    {
        i = partition(a, low, high);
        quick_sort_by_partition(a, low, i - 1);
        quick_sort_by_partition(a, i + 1, high);
    }
}

void sift(int * a, int low, int high)
{
    int i, j, temp;

    i = low;
    j = 2 * i;
    temp = a[i];
    while (j < high)
    {
        if (j < high && a[j] < a[j+1])
        {
            ++j;
        }
        if (temp < a[j])
        {
            a[i] = a[j];
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }
    a[i] = temp;
}

void heap_adjust(int * a, int i, int heap_size)
{
    int largest = 0;
    int left = 2 * i;
    int right = left + 1;

    if (left <= heap_size && a[left] > a[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right <= heap_size && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&a[largest], &a[i]);
        heap_adjust(a, largest, heap_size);
    }
}
