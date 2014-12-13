/*************************************************************************
    > File Name: varargs.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Sat 13 Dec 2014 08:50:59 AM CST
 ************************************************************************/

#ifndef VARARGS_H_
#define VARARGS_H_

typedef char * va_list;
#define va_dcl int va_alist;
#define va_start(list) list = (char *)&va_alist;
#define va_end(list)
#define va_arg(list, mode) ((mode *) (list += sizeof(mode)))[-1]

#endif
