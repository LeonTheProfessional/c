/*************************************************************************
  > File Name: matrix_operation.h
  > Author: Hui Wang
  > Mail: ncepuwanghui@gmail.com 
  > Created Time: Fri 24 Oct 2014 12:24:56 AM CST
 ************************************************************************/

#ifndef MATRIX_OPERATION_H
#define MATRIX_OPERATION_H

#define MAX_ROW_NUM 10
#define MAX_COL_NUM 10

//矩阵相乘
int matrix_multiplication(int a[][MAX_COL_NUM], int ra, int ca, 
        int b[][MAX_COL_NUM], int rb, int cb, 
        int c[][MAX_COL_NUM], int * rc, int * cc);

//矩阵转置
void matrix_transposition(int a[][MAX_COL_NUM], int dim);

void input_matrix(int a[][MAX_COL_NUM], int *ra, int * ca);

void print_matrix(int a[][MAX_COL_NUM], int ra, int ca);

#endif
