/*************************************************************************
	> File Name: mall.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Tue 11 Nov 2014 12:01:06 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

bool newcustomer(double x); //有新顾客到来吗？
Item customertime(long when); //设置顾客参量

int main(void)
{
    Queue line;
    Item temp;//关于新顾客的数据
    int hours;//模拟的小时数
    int perhour;//每小时顾客的平均数
    long cycle, cyclelimit;//循环计数器，计数器的上界
    long turnaways = 0;//因队列已满而被拒绝的顾客数
    long customers = 0;//被加入队列的顾客数
    long served = 0;//在模拟期间得到服务的顾客数
    long sum_line = 0;//累计的队列长度
    int wait_time = 0;//从当前时刻到空闲所需的时间
    double min_per_cust; //顾客到来的平均间隔时间
    long line_wait = 0;//队列累计等待时间

    InitializeQueue(&line);
    srand(time(0));
    puts("Case Study: Siqmund Lander's Advice Booth");
    puts("Enter the number of simulation hours: ");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour: ");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line))
            {
                turnaways++;
            }
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
        {
            wait_time--;
        }
        sum_line += QueueItemCount(&line);
    }
    
    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("customers served: %ld\n", served);
        printf("turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double)sum_line / cyclelimit);
        printf("average wait time: %.2f minutes\n", (double)line_wait / served);
    }
    else
    {
        puts("No customers!");
    }
    EmptyTheQueue(&line);
    puts("Bye!");

    return 0;
}

//x是顾客到来的平均间隔时间，如果这1分钟内有顾客到来，则返回true
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//when是顾客到来的时间
//函数返回一个Item结构，该结构的顾客到来时间设置为when
//需要的咨询时间设置为一个范围在1~3之间的随机值
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
