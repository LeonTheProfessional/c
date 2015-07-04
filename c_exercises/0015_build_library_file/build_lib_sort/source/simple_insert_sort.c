/*************************************************************************
	> File Name: simple_insert_sort.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Created Time: Sun 18 Jan 2015 02:29:11 PM CST
 ************************************************************************/
#include "../include/sort.h"

void simple_insert_sort(int *a, int len)
{
	int i, j, temp;
	
	for (i = 1; i < len; ++i)
	{
		j = i - 1;
		temp = a[i];
		while (j >= 0 && a[j] > temp)
		{
			a[j+1] = a[j];
			--j;
		}
		a[++j] = temp;
	}
}
