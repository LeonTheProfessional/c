/*************************************************************************
	> File Name: 5_3_ex_reverse_bits.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Tue 16 Dec 2014 01:46:35 PM CST
 ************************************************************************/

#include <stdio.h>

//反转value的二进制位模式
unsigned int reverse_bits(unsigned int value);

int main(void)
{
    unsigned int value;
    
    printf("Enter a unsigned integer:");
    scanf("%u", &value);
    reverse_bits(value);
    printf("\n");

    return 0;
}

//反转value的二进制位模式
unsigned int reverse_bits(unsigned int value)
{
    unsigned int result = 0;
    int cnt = 1;

    for (cnt = 1; cnt != 0; cnt <<= 1) {
        if (value & 1) {
            result |= 1;
            putchar('1');
        } else {
            putchar('0');
        }
        value >>= 1;
        result <<= 1;
    }

    return result;
}
