/*************************************************************************
	> File Name: fibonacci.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 07 Dec 2014 07:48:14 PM CST
 ************************************************************************/

#include <stdio.h>


//利用递归实现斐波拉契数列
int fibonacci_recursion(int n)
{
    if (n < 2) {
        return n;
    } else {
        return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
    }
}

//利用三个元素的循环队列实现斐波拉契数列
int fibonacci_loop(int n)
{
    if (n < 2) {
        return n;
    } else {
        const int queue_size = 3;
        int queue[queue_size];
        int i = 0;

        queue[0] = 0;
        queue[1] = 1;
        for (i = 2; i <= n; i++) {
            queue[i % queue_size] = queue[(i + 1) % queue_size] + queue[(i + 2) % queue_size];
        }
        
        return queue[(i - 1) % queue_size];
    }
}
