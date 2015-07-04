/*************************************************************************
	> File Name: 1_12_print_one_word_per_line.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Description: 以每行一个单词的形式打印输入
	> Created Time: Wed 15 Apr 2015 10:11:16 PM CST
 ************************************************************************/

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            if (state == OUT) {
                state = IN;
            }
            putchar(c);
        }
    }

    return 0;
}
