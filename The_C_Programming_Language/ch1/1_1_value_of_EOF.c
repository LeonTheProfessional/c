/*************************************************************************
	> File Name: 1_1_value_of_EOF.c
	> Author: Sam Wong
	> Mail: ncepuwanghui@gmail.com
	> Blog: http://samwong.im
	> Description: Test the value of 'EOF'
	> Created Time: Thu 02 Apr 2015 10:16:21 PM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
    int ch;

    ch = getchar();
    while (ch != EOF)
    {
        putchar(ch);
        ch = getchar();
    }
    printf("EOF is %d\n", ch);
    printf("EOF is %d\n", EOF);
    
    return 0;
}
