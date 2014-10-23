/*************************************************************************
	> File Name: matrix_operation.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 24 Oct 2014 12:27:53 AM CST
 ************************************************************************/

#include "matrix_operation.h"

int matrix_multiplication(int a[][MAX_COL_NUM], int ra, int ca, 
        int b[][MAX_COL_NUM], int rb, int cb, 
        int c[][MAX_COL_NUM], int * rc, int * cc)
{
	int i = 0, j = 0, k = 0;
	if (ca != rb)
	{
		return -1;
	}
	for (i = 0; i < ra; ++i)
	{
		for (j = 0; j < cb; ++j)
		{
			c[i][j] = 0;
			for (k = 0; k < ca; ++k)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	*rc = ra;
	*cc = cb;
	return 0;
}

void swap(int * a, int * b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void matrix_transposition(int a[][MAX_COL_NUM], int dim)
{
	int i, j;
	for (i = 0; i < dim; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			swap(&a[i][j], &a[j][i]);	
		}
	}
}

void input_matrix(int a[][MAX_COL_NUM], int *ra, int * ca)
{
	int row, col;
	int i = 0, j = 0;
	printf("Row number of matrix: ");
	scanf("%d", &row);
	printf("Col number of matrix: ");
	scanf("%d", &col);
	printf("Elements of matrix:\n");
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	*ra = row;
	*ca = col;
}

void print_matrix(int a[][MAX_COL_NUM], int ra, int ca)
{
	int i, j;
	for (i = 0; i < ra; ++i)
	{
		for (j = 0; j < ca; ++j)
		{
			printf("%-4d", a[i][j]);
		}
		printf("\n");
	}
}
