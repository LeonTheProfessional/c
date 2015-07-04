/*************************************************************************
  > File Name: main.c
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Fri 09 Jan 2015 10:09:33 PM CST
 ************************************************************************/

#include "sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define IN_FILE "input.dat"
#define OUT_FILE "output.dat"

//生成随机数文件
void generate_file(FILE * fp, int num);
//将随机数写入文件
void write_file(FILE * fp, const int * a, int len);
//读取随机数文件
void read_file(FILE * fp, int * a, int len);
//打开文件
void open_file(FILE ** fp, const char * filename, const char * mode);

int main(void)
{
    FILE * fp_in, * fp_out;
    int * a;
    int flag;
    int num;
    int ch;

    printf("Array Size:");
    while (scanf("%d", &num) != 1 || num <= 0)
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            ;
        }
        printf("Incorrect input! Try again!\n");
    }

    open_file(&fp_in, IN_FILE, "wb");
    generate_file(fp_in, num);
    fclose(fp_in);

    a = (int *) malloc(sizeof(int) * num);
    memset(a, 0, (sizeof(int) * num));
    open_file(&fp_in, IN_FILE, "rb");
    read_file(fp_in, a, num);
    fclose(fp_in);

    printf("Please choose a algorithm to sort:\n");
    printf("1.Quick Sort Algorithm\n");
    printf("2.Bubble Sort Algorithm\n");
    printf("3.Direct Insert Sort Algorithm\n");
    printf("4.Select Sort Algorithm\n");
    printf("5.Heap Sort Algorithm\n");
    printf("6.Counting Sort Algorithm\n");

    while (scanf("%d", &flag) != 1 || flag < 1 || flag > 6)
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            ;
        }
        printf("Incorrect input! Try again!\n");
    }
    switch (flag)
    {
        case 1:
            quick_sort(a, num);
            break;
        case 2: 
            bubble_sort(a, num);
            break;
        case 3:
            direct_insert_sort(a, num);
            break;
        case 4:
            select_sort(a, num);
            break;
        case 5:
            heap_sort(a, num);
            break;
        case 6:
            counting_sort(a, num);
            break;
        default:
            quick_sort(a, num);
    }

    open_file(&fp_out, OUT_FILE, "wb");
    write_file(fp_out, a, num);
    fclose(fp_out);

    return 0;
}

//打开文件
void open_file(FILE ** fp, const char * filename, const char * mode)
{
    *fp = fopen(filename, mode);
    if (!(*fp))
    {
        perror("open_file,fopen:");
        exit(EXIT_FAILURE);
    }
}

//生成随机数文件
void generate_file(FILE * fp, int num)
{
    int i;

    srand(time(NULL));
    for (i = 0; i < num; ++i)
    {
        fprintf(fp, "%d\t", rand() % RANGE);
    }
}
//将随机数写入文件
void write_file(FILE * fp, const int * a, int len)
{
    int i;

    for (i = 0; i < len; ++i)
    {
        fprintf(fp, "%d\t", a[i]);
    }
}
//读取随机数文件
void read_file(FILE * fp, int * a, int len)
{
    int i;

    for (i = 0; i < len; ++i)
    {
        fscanf(fp, "%d\t", &a[i]);
    }
}
