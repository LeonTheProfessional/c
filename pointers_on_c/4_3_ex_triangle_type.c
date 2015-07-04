/*************************************************************************
	> File Name: 4_3_ex_triangle_type.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 05:08:38 PM CST
 ************************************************************************/

/*
 * 输入三条边长，判断能否构成三角形，并判断其类型
 */

#include <stdio.h>
#include <stdbool.h>

enum Triangle {
    EQUILATERAL, ISOSCELES, SCALENE, NONE
};

//判断能否构成三角形
static bool is_triangel(const int a, const int b, const int c);
//判断三角形类型
enum Triangle which_triangle(const int a, const int b, const int c);

int main(void)
{
    int a, b, c;

    printf("Enter per side  of a triangle: ");
    scanf("%d%d%d", &a, &b, &c);
    switch (which_triangle(a, b, c)) {
        case EQUILATERAL:
            printf("Equilateral Triangle\n");
            break;
        case ISOSCELES:
            printf("Isosceles Triangle\n");
            break;
        case SCALENE:
            printf("Scalene Triangle\n");
            break;
        default:
            printf("No Triangle\n");
            break;
    }

    return 0;
}

//判断能否构成三角形
static bool is_triangel(const int a, const int b, const int c)
{
    //三角形的任意两边之和大于第三边
    if (a + b > c && b + c > a && c + a > b) {
        return true;
    } else {
        return false;
    }
}

//判断三角形类型
enum Triangle which_triangle(const int a, const int b, const int c)
{
    int cnt = 0; //统计任意两边相等的次数

    if (!is_triangel(a, b, c)) {
        return NONE;
    }

    if (a == b) {
        ++cnt;
    }
    if (b == c) {
        ++cnt;
    }
    if (a == c) {
        ++cnt;
    }

    switch (cnt) {
        case 0:
            return SCALENE;
        case 1:
            return ISOSCELES; 
        case 2:
        case 3:
            return EQUILATERAL;
        default:
            return SCALENE;
    }
}
