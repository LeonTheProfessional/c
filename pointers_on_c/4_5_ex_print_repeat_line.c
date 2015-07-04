/*************************************************************************
	> File Name: 4_5_ex_print_repeat_line.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 15 Dec 2014 05:32:10 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 128

int main(void)
{
    char last_line[MAX] = { 0 };
    char cur_line[MAX];
    FILE * fp;
    const char * filename = "4_5_ex_text.dat";
    bool flag = false;//标识重复行

    fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Can't open the file %s!\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(cur_line, MAX, fp) != NULL) {
        if (strncmp(last_line, cur_line, MAX) == 0) {
            flag = true;
        } else {
            if (flag) {
                printf("%s", last_line);
                flag = false;
            }
        }
        strncpy(last_line, cur_line, MAX);
    }

    return 0;
}
