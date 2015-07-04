/*************************************************************************
    > File Name: expression_evaluation.h
    > Author: Hui Wang
    > Mail: ncepuwanghui@gmail.com 
    > Created Time: Sun 07 Dec 2014 10:33:04 PM CST
 ************************************************************************/

#ifndef EXPRESSION_EVALUATION_H_
#define EXPRESSION_EVALUATION_H_

#define MAX_LEN 100
#define OP_NUM 10

//获取操作符的优先级
int priority(char left, char right);

//将表达式由中缀表达式转化为后缀表达式
void infix_to_suffix(char * exp_infix, char * exp_suffix);

//计算表达式的值
int get_value(char * exp_suffix);

//运算符
int op(int a, int b, char op);

#endif
