/*************************************************************************
	> File Name: 16_9_ifdef.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 10 Nov 2014 07:34:58 PM CST
 ************************************************************************/
//使用条件编译
#include <stdio.h>

#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
    int i;
    int total = 0;

    for (i = 1; i <= LIMIT; i++)
    {
        total += 2 * i * i + 1;
#ifdef JUST_CHECKING
        printf("i = %d, running total = %d\n", i, total);
#endif
    }
    printf("Grand total = %d\n", total);
    
    return 0;
}
