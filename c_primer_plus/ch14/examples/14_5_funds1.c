/*************************************************************************
	> File Name: 14_5_funds1.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 10 Nov 2014 11:18:47 AM CST
 ************************************************************************/

#include <stdio.h>
#define FUNDLEN 50
struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum (double , double);
double sum (const struct funds *);

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        3024.72,
        "Lucky's Savings and Loan",
        9237.11
    };
    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));

    return 0;
}
//向函数传递结构成员
double sum (double x, double y)
{
    return (x + y);
}
double sum (const struct funds * money)
{
    return (money->bankfund + money->savefund);
}
