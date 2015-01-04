/*************************************************************************
  > File Name: expression_evaluation.c
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Sun 07 Dec 2014 10:38:56 PM CST
 ************************************************************************/

#include "expression_evaluation.h"

//获取操作符的优先级
//return 1: left > right
//return 0: left = right
//return -1: left < right
int priority(char left, char right)
{
    char op[OP_NUM] = {'+', '-', '*', '/', '(', ')'};
    int l = 0, r = 0;
    int i = 0;
    char priority_table[OP_NUM][OP_NUM] = 
    {
        { 0,  0, -1, -1, -1, 1}, 
        { 0,  0, -1, -1, -1, 1}, 
        { 1,  1,  0,  0, -1, 1}, 
        { 1,  1,  0,  0, -1, 1}, 
        { 1,  1,  1,  1,  0, 1},
        {-1, -1, -1, -1, -1, 0}
    };

    while (i++ < OP_NUM) 
    {
        if (op[i] == left)
        {
            l = i;
        }
        if (op[i] == right)
        {
            r = i;
        }
    }

    return priority_table[l][r];
}

//将表达式由中缀表达式转化为后缀表达式
void infix_to_suffix(char * exp_infix, char * exp_suffix)
{
    char stack[MAX_LEN];
    int top = -1;
    int i = 0, j = 0;
    while (exp_infix[i] != '\0')
    {
        if (exp_infix[i] >= '0' && exp_infix[i] <= '9')
        {
            exp_suffix[j++] = exp_infix[i];
        }
        else if (-1 == top || exp_infix[i] == '(')
        {
            stack[++top] = exp_infix[i];
        }
        else if (exp_infix[i] == ')')
        {
            while(stack[top] != '(')
            {
                exp_suffix[j++] = stack[top--];
            }
            --top;//pop the '('
        }
        else if ((priority(stack[top], exp_infix[i]) == 1) 
                || (priority(stack[top], exp_infix[i]) == 0))
        {
            while (stack[top] != '(' 
                    && ((priority(stack[top], exp_infix[i]) == 1) 
                        || (priority(stack[top], exp_infix[i]) == 0)) && top != -1)
            {

                exp_suffix[j++] = stack[top--];
            }
            stack[++top] = exp_infix[i];
        }
        else
        {
            stack[++top] = exp_infix[i];
        }
        ++i;
    }
    while (top != -1)
    {
        exp_suffix[j++] = stack[top--];
    }
    exp_suffix[j] = '\0';
}

//计算表达式的值
int get_value(char * exp_suffix)
{
    int i = 0;
    int  stack[MAX_LEN];
    int top = -1;
    int a, b;

    while (exp_suffix[i] != '\0')
    {
        if (exp_suffix[i] >= '0' && exp_suffix[i] <= '9')
        {
            stack[++top] = exp_suffix[i++] - '0';       
        }
        else
        {
            a = stack[top--];
            b = stack[top--];
            stack[++top] = op(b, a, exp_suffix[i++]);
        }
    }

    return stack[top--];
}

//运算符
int op(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return -1;
    }
}
