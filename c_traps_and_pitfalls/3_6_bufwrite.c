/*************************************************************************
	> File Name: 3_6_bufwrite.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Wed 12 Nov 2014 05:17:10 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 128

static char buffer[BUF_SIZE];
static char *bufptr = buffer;

//void memcpy(char *dest, const char *source, int k);
void bufwrite(char *p, int n);
void flush_buffer();

int main(void)
{
    char *str;
    char *cur;
    char ch;
    unsigned int len = 0;

    const unsigned int STR_MAX_LEN = 1024;

    str = (char *)malloc(sizeof(char) * STR_MAX_LEN + 1);
    if (str == NULL) {
        printf("Memory allocate failed!\n");
        exit(EXIT_FAILURE);
    }

    cur = str;
    puts("Enter a string: ");
    while (EOF != (ch = getchar()) && len < STR_MAX_LEN) {
       *cur++ = ch; 
       len++;
    }
    str[len] = '\0';

    bufwrite(str, len);
    free(str);
    
    return 0;
}
/*
void bufwrite(char *p, int n)
{
    while (--n >= 0) {
        if (bufptr == &buffer[BUF_SIZE]) {//只有buffer满时才将缓冲写入文件
            fprintf(stdout, "flush buffer!\n");
            flush_buffer();
            bufptr = buffer;
        }
        *bufptr++ = *p++;
    }
}
*/
/*
void memcpy(char *dest, const char *source, int k)
{
    while (--k >= 0)
    {
        *dest++ = *source++;
    }
}
*/
void bufwrite(char *p, int n)
{
    while (n > 0)
    {
        int k = 0;
        int rem = 0;
        if (bufptr == &buffer[BUF_SIZE])
        {
            fprintf(stdout, "flush buffer!\n");
            flush_buffer();
            bufptr = buffer;
        }
        rem = BUF_SIZE - (bufptr - buffer);
        k = n > rem ? rem : n;
        memcpy(bufptr, p, k);
        bufptr += k;
        p += k;
        n -= k;
    }
}
void flush_buffer()
{
    FILE *fp;
    
    fp = fopen("buffer.dat", "a+b");

    if (NULL == fp) {
        fprintf(stderr, "Can't open file buffer.dat");
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, 1, BUF_SIZE, fp);
    fclose(fp);
}
