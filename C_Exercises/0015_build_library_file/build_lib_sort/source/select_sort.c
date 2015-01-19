/*************************************************************************
	> File Name: select_sort.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Created Time: Sun 18 Jan 2015 02:29:00 PM CST
 ************************************************************************/
#include "../include/sort.h"

extern void swap(int *a, int *b);

void select_sort(int *a, int len)
{
	int i, j, min;
	
	for (i = 0; i < len; ++i)
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
			swap(&a[min], &a[i]);
		}
	}
}
