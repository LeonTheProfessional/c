/*************************************************************************
	> File Name: quick_sort.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Created Time: Sun 18 Jan 2015 02:28:48 PM CST
 ************************************************************************/
#include "../include/sort.h"

static int partion(int *a, int len)
{
	int low = 0;
	int high = len - 1;
	int pivot = a[low];
	
	while (low < high)
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

void quick_sort(int *a, int len)
{
	int i;	
	
	if (len > 1)
	{
		i = partion(a, len);
		quick_sort(a, i);
		quick_sort(&a[i + 1], len - (i + 1));
	}
}
