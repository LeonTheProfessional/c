/*************************************************************************
	> File Name: ex_1_1_add_line_number.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 09:34:10 AM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
    int ch = 0;
    int line = 0;
    int pre_ch = '\n';

    while ((ch = getchar()) != EOF) {
        if ('\n' == pre_ch) {
            ++line;
            printf("%d: ", line);
        }
        putchar(ch);
        pre_ch = ch;
    }

    return 0;
}
