/*************************************************************************
	> File Name: 1_9_remove_extra_blanks.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Description: replace string of blanks with a single blank
	> Created Time: Thu 02 Apr 2015 10:50:16 PM CST
 ************************************************************************/

#include <stdio.h>

#define NONBLANK 'A'

int main(void)
{
    int ch, pre_ch;

    pre_ch = NONBLANK;
    while ((ch = getchar()) != EOF)
    {
        if (ch != ' ' || pre_ch != ' ')
        {
            putchar(ch);
        }
        pre_ch = ch;
    }

    return 0;
}
