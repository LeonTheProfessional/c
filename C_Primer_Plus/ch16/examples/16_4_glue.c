/*************************************************************************
	> File Name: 16_4_glue.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 10 Nov 2014 07:28:37 PM CST
 ************************************************************************/
//使用##运算符
#include <stdio.h>

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n)

int main(void)
{
    int XNAME(1) = 14;
    int XNAME(2) = 20;
    PRINT_XN(1);
    PRINT_XN(2);

    return 0;
}
