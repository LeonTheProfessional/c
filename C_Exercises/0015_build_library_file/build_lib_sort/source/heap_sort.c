/*************************************************************************
	> File Name: heap_sort.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Created Time: Sun 18 Jan 2015 02:27:10 PM CST
 ************************************************************************/
#include "../include/sort.h"

extern void swap(int *a, int *b);

static void heap_adjust(int *a, int heap_size, int i);

void heap_sort(int *a, int len)
{
	int i;
	
	for (i = len / 2 - 1; i >= 0; --i)
	{
		heap_adjust(a, len - 1, i);
	}
	for (i = len - 1; i >= 1; --i)
	{
		swap(&a[0], &a[i]);
		heap_adjust(a, i - 1, 0);
	}
}

void heap_adjust(int *a, int heap_size, int i)
{
	int largest = 0;
	int left = 2 * i + 1;
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
		heap_adjust(a, heap_size, largest);
	}
}
