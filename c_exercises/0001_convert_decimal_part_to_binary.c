/*************************************************************************
  > File Name: convert_decimal_part_to_binary.c
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Mon 09 Jun 2014 04:35:09 PM CST
 ************************************************************************/
/*
 * 功能：将小数部分换算成二进制
 * 方法：乘基取整
 * 遇到的问题：编译可通过，但链接时出现undefined reference to `pow‘错误
 * 解决方法：gcc 引用math.h头文件，需要加参数-lm 来加载动态链接库libm.so 
 * 参考链接：http://blog.csdn.net/hercaffe/article/details/7198563
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

#define PRECISION 23

void decimal_to_binary_by_compare(float f, unsigned char c[PRECISION]);
void decimal_to_binary_by_multiply_base(float f, unsigned char c[PRECISION]);

int main(void)
{
    float f = 0.456f;
    unsigned char c[PRECISION];
    memset(c, 0, PRECISION);

    decimal_to_binary_by_compare(f, c);
    printf("\n");

    return 0;
}

void decimal_to_binary_by_compare(float f, unsigned char c[PRECISION])
{
    int i = 0, j = 0;

    for (i = -1, j = 0; i >= -23; i--, j++)
    {
        if (f > (float)pow(2, i))
        {
            c[j] = 1;
            printf("%d", c[j]);
            f = (float)f - (float)pow(2, i);
        }
        else
        {
            c[j] = 0;
            printf("%d", c[j]);
        }
    }
}
