/*************************************************************************
	> File Name: 0013_int_to_string.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 10 Jan 2015 09:40:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 16

void int_to_string(int num, char *str);

int main(void)
{
    int num;
    char *str;

    str = (char*) malloc(sizeof(char) * MAX);
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN); 
    printf("Input a integer (non-integer to stop):\n");
    while (1 == scanf("%d", &num)) {
        if (num <= INT_MIN || num >= INT_MAX) {
            printf("Incorrect input! Please input again!\n");
        } else {
            int_to_string(num, str);
            printf("Integer: %d\nString: %s\n", num, str);
            printf("Please input another integer (non-integer to stop).\n");
        }
    }
    free(str);

    return 0;
}

void int_to_string(int num, char *str)
{
    int i = 0;
    int stack[MAX];
    int top = -1;

    if (num < 0) {
        str[i++] = '-';
        num = -num;
    }
    while (num) {
        stack[++top] = num % 10;
        num /= 10;
    }
    while (-1 != top) {
        str[i++] = "0123456789"[stack[top--]];
    }
    str[i] = '\0';
}
