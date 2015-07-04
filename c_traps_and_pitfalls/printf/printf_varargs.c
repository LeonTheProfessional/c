/*************************************************************************
	> File Name: printf_varargs.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 08:44:12 AM CST
 ************************************************************************/

#include <varargs.h>

int printf(va_alist) va_dcl;

int printf(va_alist) va_dcl
{
    va_list ap;
    char * format;
    int n;

    va_start(ap);
    format = va_arg(ap, char *);
    n = vprintf(format, ap);
    va_end(ap);

    return n;
}
