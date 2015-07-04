/*************************************************************************
	> File Name: 2_1_ex_brace_matching.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 10:02:27 AM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
    int ch;
    int cnt = 0;

    while (EOF != (ch = getchar())) {
        if ('{' == ch) {
            ++cnt;
        } else if ('}' == ch) {
            if (0 == cnt) {
                printf("Extra closing brace!\n");
            } else {
                --cnt;
            }
        }
    }

    if (cnt > 0) {
        printf("%d unmatched opening brace(s).\n", cnt);
    }

    return 0;
}
