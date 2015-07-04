/*************************************************************************
	> File Name: text_processing.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 04 Jan 2015 09:21:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SRC_FILE "src_file.txt"
#define DST_FILE "dst_file.txt"

int main(void)
{
    int ch;
    FILE *fp_src, *fp_dst;

    if ((fp_src = fopen(SRC_FILE, "r")) == NULL 
        || (fp_dst = fopen(DST_FILE, "w")) == NULL)
    {
        perror("fopen:");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp_src)) != EOF)
    {
        if (ispunct(ch))
        {
            fputc(' ', fp_dst);
        }
        else if (isupper(ch))
        {
            fputc(tolower(ch), fp_dst);
        }
        else
        {
            fputc(ch, fp_dst);
        }
    }

    fclose(fp_src);
    fclose(fp_dst);

    return 0;
}
