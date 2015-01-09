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

#define MAX_NUM 100
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

    open_file(&fp_in, IN_FILE, "wb");
    generate_file(fp_in, MAX_NUM);
    fclose(fp_in);

    a = (int *) malloc(sizeof(int) * MAX_NUM);
    memset(a, 0, (sizeof(int) * MAX_NUM));
    open_file(&fp_in, IN_FILE, "rb");
    read_file(fp_in, a, MAX_NUM);
    fclose(fp_in);

    quick_sort(a, MAX_NUM);
    //bubble_sort(a, MAX_NUM);
    //direct_insert_sort(a, MAX_NUM);
    //heap_sort(a, MAX_NUM);
    //counting_sort(a, MAX_NUM);
    

    open_file(&fp_out, OUT_FILE, "wb");
    write_file(fp_out, a, MAX_NUM);
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
