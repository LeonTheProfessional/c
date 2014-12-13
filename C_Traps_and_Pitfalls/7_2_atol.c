/*************************************************************************
	> File Name: 7_2_atol.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 08:33:29 AM CST
 ************************************************************************/

#include <stdio.h>

//可移植的atol函数
long atol(const char * s);

int main(void)
{
    const char * str = "123.04560";

    printf("Result: %ld\n", atol(str));

    return 0;
}

long atol(const char * s)
{
    long r = 0;
    int neg = 0;

    switch (*s) {
        case '-':
            neg = 1;
            /* 此处没有break语句 */
        case '+':
            s++;
            break;
    }
    while (*s >= '0' && *s <= '9') {
        int n = *s++ - '0';
        if (neg) {
            n = -n;
        }
        r = r * 10 + n;
    }

    return r;
}
