/*************************************************************************
	> File Name: 4_6_ex_substr.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 15 Dec 2014 10:55:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define NUL 0
#define MAX 32

//从src数组起始位置向后偏移start个字符的位置开始,最多复制len个非NUL字符到dst数组
int substr(char dst[], char src[], int start, int len);

int main(void)
{
   char src[MAX];
   char dst[MAX];
   int start = 0;
   int len = 0;

   printf("Enter the source string:");
   fgets(src, MAX, stdin);
   printf("Enter the start index and length:");
   scanf("%d%d", &start, &len);
   substr(dst, src, start, len);
   printf("%s\n", dst);

   return 0;
}

//从src数组起始位置向后偏移start个字符的位置开始,最多复制len个非NUL字符到dst数组
int substr(char dst[], char src[], int start, int len)
{
    int i, j;
    int src_len = strlen(src);

    if (start < 0 || len < 0 || start > src_len) {
        dst[0] = NUL;
        return 0;
    }
    
    for (i = start, j = 0; i < src_len && j < len; ++i, ++j) {
        dst[j] = src[i];
    }
    dst[j] = NUL;
    
    return j;
}
