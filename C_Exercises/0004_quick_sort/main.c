/*************************************************************************
	> File Name: main.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 07 Dec 2014 05:17:50 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "quick_sort.h"

#define MAX_LEN 1000
#define RANGE 100

//随机生成一个数组元素
static void get_rand_item(int * item);
//人工输入一个数组元素
static void get_input_item(int * item);
//打印数组元素
static void print_array_item(int * item);
//清理缓冲区剩余字符
static void clear_buffer();

int main(void)
{
    int arr[MAX_LEN];
    int arr_len = 0;
    char choice = 0;

    printf("Please input the length of array:");
    scanf("%d", &arr_len);
    clear_buffer();

    printf("Enter a char to generate the arrar:\n");
    printf("a. Generate array randomly.\n");
    printf("b. Generate array by standard input.\n");
    scanf("%c", &choice);
    clear_buffer();
    switch (choice) {
        case 'a':
        default:
            //随机生成数组元素
            srand((unsigned int)time(NULL));
            traverse_array(arr, arr_len, get_rand_item);
            break;
        case 'b':
            //手工输入数组元素
            traverse_array(arr, arr_len, get_input_item);
            break;
    }

    quick_sort(arr, 0, arr_len - 1);

    traverse_array(arr, arr_len, print_array_item);
    printf("\n");

    return 0;
}
static void get_rand_item(int * item)
{
    *item = rand() % RANGE;
}

static void get_input_item(int * item)
{
    scanf("%d", item);
}

static void print_array_item(int * item)
{
    static int cnt = 0;
    printf("%2d ", *item);
    cnt++;
    if (cnt % 10 == 0) {
        printf("\n");
    }
}

static void clear_buffer()
{
    int c = 0;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}
