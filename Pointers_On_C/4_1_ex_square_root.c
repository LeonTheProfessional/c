/*************************************************************************
	> File Name: 4_1_ex_square_root.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 04:24:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

/*
 * 计算正数n的平方根：
 * 公式：a(i+1) = (a(i) + n / a(i)) / 2;
 */
float square_root(int n);

int main(void)
{
    int n;

    printf("Please input a integer: ");
    scanf("%d", &n);
    square_root(n);
    printf("The square root of %d is %f.\n", n, square_root(n));

    return 0;
}

float square_root(int n)
{
    float pre = 1.0F; //初始近似值为1
    float a;
    const float PRECISION = 1e-6;

    do {
        a = pre;
        pre = (a + n / a) / 2;
        printf("%f\t%f\n", a, pre);
    } while (fabsf(pre - a) > PRECISION);

    return a;
}
