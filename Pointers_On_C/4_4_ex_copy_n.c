/*************************************************************************
	> File Name: 4_4_ex_copy_n.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 14 Dec 2014 07:43:20 PM CST
 ************************************************************************/

#include <stdio.h>

#define NUL 0
#define MAX_LEN 32

void copy_n(char dst[], char src[], int n);

int main(void)
{
    char dst[MAX_LEN] = { 0 };
    char src[MAX_LEN] = { 0 };
    int i = 0;

    fgets(src, MAX_LEN, stdin);
    copy_n(dst, src, MAX_LEN);

    while (dst[i] != NUL) {
        putchar(dst[i]);
        ++i;
    }

    return 0;
}

void copy_n(char dst[], char src[], int n)
{
    int i = 0;
    for (i = 0; i < n; ++i) { 
        if (NUL != src[i]) {
            dst[i] = src[i];
        } else {
            dst[i] = NUL;
        }
    }
}
