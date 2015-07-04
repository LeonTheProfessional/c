/*************************************************************************
	> File Name: testcase.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Created Time: Sun 18 Jan 2015 02:36:15 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#include "./include/sort.h"

static void generate_array(int *a, int len, int range);
static void print_array(int *a, int len);

int main(int argc, char *argv[])
{
	int size;
	int range;
    int *arr;
	int flag;

    if (argc < 3)
    {
        printf("Usage:exe size range\n");
        exit(EXIT_FAILURE);
    }
	size = atoi(argv[1]);
	range = atoi(argv[2]);
	arr = (int*) malloc(size * sizeof(int));
	memset(arr, 0, size * sizeof(int));

	generate_array(arr, size, range);
	printf("Please choose a algorithm to sort:\n");
	printf("1.Simple Insert Sort Algorithm\n");
	printf("2.Bubble Sort Algorithm\n");
	printf("3.Select Sort Algorithm\n");
	printf("4.Quick Sort Algorithm\n");
	printf("5.Heap Sort Algorithm\n");
	scanf("%d", &flag);
	printf("Before Sort:\n");
	print_array(arr, size);
	switch (flag)
	{
		case 1:
			printf("After Sort (by Simple Insert Sort Algorithm):\n");
			simple_insert_sort(arr, size);
			break;
		case 2:	
			printf("After Sort (by Bubble Sort Algorithm):\n");
			bubble_sort(arr, size);
			break;
		case 3:
			printf("After Sort (by Select Sort Algorithm):\n");
			select_sort(arr, size);
			break;
		case 4:
			printf("After Sort (by Quick Sort Algorithm):\n");
			quick_sort(arr, size);
			break;
		case 5:
			printf("After Sort (by Heap Sort Algorithm):\n");
			heap_sort(arr, size);
			break;
		default:
			printf("Incorrect Selection!\n");
	}
	print_array(arr, size);

	return 0;
}

void generate_array(int *a, int len, int range)
{
	srand(time(NULL));
	while (--len >= 0)
	{
		a[len] = rand() % range;
	}
}

void print_array(int *a, int len)
{
	int i;

	for (i =0; i < len; ++i)
	{
		printf("%-8d", a[i]);
	}
	printf("\n");
}
