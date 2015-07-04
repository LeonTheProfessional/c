/*************************************************************************
  > File Name: main.c
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Sun 04 Jan 2015 08:47:46 PM CST
 ************************************************************************/

//compute the value of infix expression
//1.convert the infix to suffix expression
//2.compute the value by suffix expression

#include <stdio.h>
#include "expression_evaluation.h"

int main(void)
{
    char exp_infix[MAX_LEN];
    char exp_suffix[MAX_LEN];
    int i = 0;

    printf("Please input a infix expression:\nInfix expression:");
    scanf("%s", exp_infix);

    infix_to_suffix(exp_infix, exp_suffix);
    printf("Suffix expression:");
    while (exp_suffix[i] != '\0')
    {
        printf("%c",exp_suffix[i++]);
    }
    printf("\n");
    printf("%s = %d\n", exp_infix, get_value(exp_suffix));

    return 0;
}
