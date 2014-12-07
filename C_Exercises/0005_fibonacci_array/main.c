/*************************************************************************
	> File Name: main.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 07 Dec 2014 08:05:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include "fibonacci.h"

int main(void)
{
    int n = 0;

    printf("Please input a integer: ");
    scanf("%d", &n);
    printf("Recursion:\nFibonacci(%d) = %d\n", n, fibonacci_recursion(n));
    printf("Loop:\nFibonacci(%d) = %d\n", n, fibonacci_loop(n));

    return 0;
}
