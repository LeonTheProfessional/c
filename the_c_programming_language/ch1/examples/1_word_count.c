/*************************************************************************
	> File Name: 1_word_count.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Description: 统计输入的行数、单词数与字符数 
	> Created Time: Thu 02 Apr 2015 11:21:33 PM CST
 ************************************************************************/

#include <stdio.h>

#define IN  1   //在单词内
#define OUT 0   //在单词外

int main(void)
{

    int c, nl, nw, nc, state;

    state = OUT; 
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}
