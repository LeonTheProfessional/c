/*************************************************************************
	> File Name: 0009_getchar_to_file.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 04 Jan 2015 09:06:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "output.dat"

void getchar_to_file(FILE * fp);

int main(void)
{
    FILE * fp;

    fp = fopen(FILENAME, "w");
    if (fp == NULL)
    {
        perror("fopen:");
        exit(EXIT_FAILURE);
    }

    getchar_to_file(fp);
    fclose(fp);

    return 0;
}

void getchar_to_file(FILE * fp)
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        fputc(ch, fp);
        while ((ch = getchar()) != '\n')
        {
            ;
        }
    }
}
