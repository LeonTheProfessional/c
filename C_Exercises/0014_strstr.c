/*************************************************************************
	> File Name: 0014_strstr.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Tue 13 Jan 2015 07:12:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 128

char * strstr(const char *string, const char *charset);

int main(void)
{
    char *string = (char *) malloc(sizeof(char) * MAX);
    char *charset = (char *) malloc(sizeof(char) * MAX);
    const char *index = NULL;

    printf("Input source string:\n");
    fgets(string, MAX, stdin);
    printf("Input charset:\n");
    fgets(charset, MAX, stdin);
    index = strstr(string, charset);
    if (index != NULL)
    {
        printf("%s\n", index);
    }
    else
    {
        printf("NULL\n");
    }

    return 0;
}

char * strstr(const char *string, const char *charset)
{
    int begin, end;
    int i;
    char *p;

    p = (char *) string;
    if (charset == NULL)
    {
        return p;
    }
    
    i = 0;
    begin = end = 0;
    while (p[i] != '\0')
    {
        if (p[i] == charset[end])
        {
            if (charset[end + 1] == '\0')
            {
                return &(p[begin]);
            }
            ++end;
            ++i;
        }
        else if (end == 0)
        {
            ++i;
            begin = i;
        }
        else
        {
            end = 0;
            begin = i;
        }
    }

    return NULL;
}
