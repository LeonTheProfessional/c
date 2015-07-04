/*************************************************************************
	> File Name: 3_6_count_print.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Thu 13 Nov 2014 04:07:12 PM CST
 ************************************************************************/

#include <stdio.h>

#define NROWS 10
#define NCOLS 10

#define BUFSIZE (NROWS * (NCOLS - 1))

static int buffer[BUFSIZE];
static int *bufptr = buffer;

void printnum(int n);
void printnl();
void printpage();
void print(int n);
void flush();

int main(void)
{
    int cnt = 0;
    int i = 0;

    printf("Please enter the max number: ");
    scanf("%d", &cnt);
    for (i = 0; i < cnt; ++i)
    {
        print(i);
    }
    flush();
    
    return 0;
}

void print(int n)
{
    if (bufptr == &buffer[BUFSIZE]) {
        static int row = 0;
        int *p;
        for (p = buffer + row; p < bufptr; p += NROWS) {
            printnum(*p);
        }
        printnum(n);
        printnl();
        if (++row == NROWS) {
            printpage();
            row = 0;//重置当前行序号
            bufptr = buffer;//重置指针bufptr
        }
    } 
    else {
        *bufptr++ = n;
    }
}
/*
void flush()
{
    int row;
    for (row = 0; row < NROWS; row++) {
       int *p;
       for (p = buffer + row; p < bufptr; p += NROWS) {
           printnum(*p);
       }
       printnl();
    }
    printpage();
}
*/
void flush()
{
    int row;
    int k = bufptr - buffer;//计算缓冲区中剩余项的数目
    if (k > NROWS) {
        k = NROWS;
    }
    if (k > 0) {
        for (row = 0; row < k; row++) {
            int *p;
            for (p = buffer + row; p < bufptr; p += NROWS) {
                printnum(*p);
            }
            printnl();
        }
        printpage();
    }
}

void printnum(int n)
{
    printf("%d ", n);
}
void printnl()
{
    printf("\n");
}
void printpage()
{
    int i = 0;
    for (i = 0; i < NCOLS; i++) {
        printf("----");
    }
    printnl();
}
