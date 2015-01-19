/*************************************************************************
	> File Name: main.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Created Time: Sat 17 Jan 2015 11:32:10 PM CST
 ************************************************************************/
#include <stdio.h>
#include "calculate.h"

int main(void)
{
    printf("add(3, 4) = %d\n", add(3, 4));
    printf("sub(4, 1) = %d\n", sub(4, 1));
    printf("mul(3, 2) = %d\n", mul(3, 2));
    printf("div(6, 2) = %d\n", div(6, 2));

    return 0;
}

