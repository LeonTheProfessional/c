/*************************************************************************
    > File Name: fibonacci.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Sun 07 Dec 2014 07:46:43 PM CST
 ************************************************************************/

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#define MAX_LEN 100

//利用递归实现斐波拉契数列
int fibonacci_recursion(int n);

//利用三个元素的循环队列实现斐波拉契数列
int fibonacci_loop(int n);

#endif
