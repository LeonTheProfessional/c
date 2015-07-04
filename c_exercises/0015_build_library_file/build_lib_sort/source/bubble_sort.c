/*************************************************************************
	> File Name: bubble_sort.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Created Time: Sun 18 Jan 2015 02:26:26 PM CST
 ************************************************************************/
#include "../include/sort.h"

void swap(int *a, int *b);

void bubble_sort(int *a, int len)
{
	int i, j, flag;
	
	for (i = len; i > 1; --i)
	{
		flag = 0;
		for (j = 1; j < i; ++j)
		{
			if (a[j] > a[j-1])
			{
				swap(&a[j], &a[j-1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
