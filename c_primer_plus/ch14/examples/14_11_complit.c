/*************************************************************************
	> File Name: 14_11_complit.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 10 Nov 2014 01:01:20 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;

    printf("Enter test score: ");
    scanf("%d", &score);

    if (score >= 84)
    {
        readfirst = (struct book) 
        {
            "Crime and Punishment",
            "Fyodor Dostoyevsky",
            9.99  
        };
    }
    else
    {
        readfirst = (struct book)
        {
            "Mr. Bouncy's Nice Hat",
            "Fred Winsome",
            5.99
        };
    }
    printf("Your assigned reading:\n");
    printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);

    return 0;
}
