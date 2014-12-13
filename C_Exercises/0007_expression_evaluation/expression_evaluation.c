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

}

//将表达式由中缀表达式转化为后缀表达式
void infix_to_suffix(char * exp_infix, char * exp_suffix);

//计算表达式的值
int get_value(char * exp_suffix);

//运算符
int op(int a, int b, char op);
