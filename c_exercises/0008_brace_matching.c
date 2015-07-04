/*************************************************************************
  > File Name: 0008_brace_matching.c
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Sun 04 Jan 2015 08:53:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

bool match(char* exp, int n);

int main(void)
{
    char exp[MAX_LEN];

    printf("Please input a expression:\n");
    fgets(exp, MAX_LEN, stdin);
    if (match(exp, strlen(exp)))
    {
        printf("Matched!\n");
    }
    else
    {
        printf("Not matched!\n");
    }

    return 0;
}

bool match(char exp[], int n)
{
    char stack[MAX_LEN];
    int top = -1;
    int i = 0;

    for (i = 0; i < n; ++i)
    {
        if (exp[i] == '(')
        {
            stack[++top] = '(';     
        }
        else if (exp[i] == ')')
        {
            if (top == -1)
            {
                return 0;
            }
            else
            {
                --top;      
            }
        }
    }

    if (-1 == top)
    {
        return true;
    }

    return false;
}
