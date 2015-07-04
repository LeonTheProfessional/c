/*************************************************************************
	> File Name: printf_stdarg.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 08:57:37 AM CST
 ************************************************************************/

#include <stdarg.h>

int printf(char * format, ...);

int printf(char * format, ...)
{
    va_list ap;
    int n;

    va_start(ap, format);
    n = vprintf(format, ap);
    va_end(ap);

    return n;
}
