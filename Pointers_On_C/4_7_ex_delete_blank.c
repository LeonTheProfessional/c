/*************************************************************************
	> File Name: 4_7_ex_delete_blank.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Mon 15 Dec 2014 11:15:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 64
//从一个字符串中去除多余的空格
void deblank(char string[]);

int main(void)
{
    char str[MAX];

    printf("Enter a string:");
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    deblank(str);
    printf("%s\n", str);
    printf("%d\n", strlen(str));

    return 0;
}

//从一个字符串中去除多余的空格
void deblank(char string[])
{ 
    int cnt = 0;//空格计数器
    int i = 0;
    int j = 0;

    while (string[i] != '\0') {
        if (' ' == string[i]) {
            ++cnt;//统计连续空格个数
        } else { 
            if (cnt > 1) {//从当前位置向前移动后续字符覆盖多余空格
                j = i;
                while (string[j] != '\0') {
                    string[j - cnt + 1] = string[j];
                    ++j;
                }
                string[j - cnt + 1] = '\0';//移动字符串结束符
                i = i - cnt + 1;//回退至当前扫描字符
            }
            cnt = 0;
        }
        ++i;
    }
}
