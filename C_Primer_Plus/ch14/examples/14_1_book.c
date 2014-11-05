/*************************************************************************
	> File Name: 14_1_book.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Wed 05 Nov 2014 11:53:28 PM CST
 ************************************************************************/

#include <stdio.h>

#define MAXTITL 41
#define MAXAUTL 31

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library;
    printf("Please enter the book title.\n");
    //fgets(library.title, MAXTITL, stdin);
    gets(library.title);
    printf("Now enter the author.\n");
    //fgets(library.author, MAXAUTL, stdin);
    gets(library.author);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");

    return 0;
}
