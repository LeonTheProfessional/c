/*************************************************************************
	> File Name: 4_2_ex_print_prime_number.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 04:47:10 PM CST
 ************************************************************************/
/*
 * 打印1~100之间的质数
 */

#include <stdio.h>
#include <stdbool.h>

//打印指定范围内的所有质数
void print_prime_number(int start, int end);

//判断一个整数是不是质数
static bool is_prime_number(int n); 

int main(void)
{
    int start, end;

    printf("Enter the range to check(like 1,100): ");
    scanf("%d,%d", &start, &end);
    print_prime_number(start, end);

    return 0;
}

//打印指定范围内的所有质数
void print_prime_number(int start, int end)
{
    int i;

    for (i = start; i <= end; ++i) {
        if (is_prime_number(i)) {
            printf("%d is a prime number.\n", i);
        }
    }
}

//判断一个整数是不是质数
static bool is_prime_number(int n)
{
    int i;

    if (1 == n) {
        return true;
    }
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
