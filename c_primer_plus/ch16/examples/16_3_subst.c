/*************************************************************************
	> File Name: 16_3_subst.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 10 Nov 2014 07:26:01 PM CST
 ************************************************************************/

//���ַ����н����滻
#include <stdio.h>

#define PSQR(x) printf("The square of " #x " is %d.\n", ((x) * (x)))

int main(void)
{
    int y = 5;

    PSQR(y);
    PSQR(2 + 4);

    return 0;
}
