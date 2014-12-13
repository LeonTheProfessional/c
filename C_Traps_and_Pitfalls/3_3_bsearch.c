/*************************************************************************
	> File Name: 3_3_bsearch.c
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sat 13 Dec 2014 07:42:49 AM CST
 ************************************************************************/

#include <stdio.h>

#define N 10

int * bsearch(int * list, int n, int x);

int main(void)
{
    int arr[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int input = 0;
    int * result = NULL;

    printf("Enter a integer to search: ");
    scanf("%d", &input);

    result = bsearch(arr, N, input);
    if (result) {
        printf("Result: %d\n", *result);
    } else {
        printf("No found!\n");
    }

    return 0;
}

int * bsearch(int * t, int n, int x)
{
    int low = 0; 
    int high = n;//采用不对称边界

    while (low < high) {
        int mid = (low + high) / 2;
        if (x == t[mid]) {
            return t + mid;
        } else if (x < t[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return NULL;
}
/*
 * 将t[mid]改写成指针形式保存，避免多次计算
int * bsearch(int * t, int n, int x)
{
    int low = 0; 
    int high = n;//采用不对称边界

    while (low < high) {
        int mid = (low + high) / 2;
        int * p = t + mid;
        if (x == *p) {
            return p;
        } else if (x < *p) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return NULL;
}
*/

/*
 * 全部用指针来实现
int * bsearch (int * t, int n, int x)
{
    int * low = t;
    int * high = t + n;

    while (low < high) {
        int * mid = low + (high - low) / 2;
        //int * mid = low + ((high - low) >> 1);//用移位运算代替除法
        if (x == *mid) {
            return mid;
        } else if (x < *mid) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return NULL;
}
*/

/*
 * 二分查找通常采用对称边界(非指针实现)
int * bsearch (int * t, int n, int x)
{
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x < t[mid]) {
            high = mid - 1;
        } else if (x > t[mid]) {
            low = mid + 1;
        } else {
            return t + mid;
        }
    }

    return NULL;
}
 */
