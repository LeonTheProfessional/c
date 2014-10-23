/*************************************************************************
	> File Name: main.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Fri 24 Oct 2014 12:33:06 AM CST
 ************************************************************************/

#include "matrix_operation.h"

int main(int argc, char const * argv[])
{
	int a[MAX_ROW_NUM][MAX_COL_NUM];
	int b[MAX_ROW_NUM][MAX_COL_NUM];
	int c[MAX_ROW_NUM][MAX_COL_NUM];
	int ra, ca, rb, cb, rc, cc;

	printf("Please input the firse matrix:\n");
	input_matrix(a, &ra, &ca);
	print_matrix(a, ra, ca);
	printf("Please input the second matrix:\n");
	input_matrix(b, &rb, &cb);
	print_matrix(b, rb, cb);
    
	if (0 == (matrix_multiplication(a, ra, ca, b, rb, cb, c, &rc, &cc)))
	{
		print_matrix(c, rc, cc);
	}
	else
	{
		printf("Error! \nThe col-num of first matrix is not equal to \
                the row-num of second matrix! \n");
	}

	printf("The transposition of first matrix:\n");
	matrix_transposition(a, ra);
	print_matrix(a, ra, ra);

	printf("The transposition of second matrix:\n");
	matrix_transposition(b, rb);
	print_matrix(b, rb, rb);

	return 0;
}
