/*
 * @Author: junhuizhou
 * @Date: 2019-12-02 10:11:48
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-02 12:16:03
 * @Description: header
 * @FilePath: \ItTDaAoA\chapter1\test010106gcd.c
 */

#include <stdio.h>

/**
 * @description: Euclid
 * @param a a>b eg: 31415
 * @param b b<a eg: 14142 
 * @return: 
 */
int gcd(int a, int b)
{
    int tmp;
    while(b != 0)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int gcdRecur(int a, int b)
{
    return b==0 ? a:gcdRecur(b,a%b);
}

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    int tmp;
    if(a < b)
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    printf("gcd of %d and %d is %d\n", a, b, gcd(a,b));
    printf("gcdRecur is %d", gcdRecur(a, b));
    return 0;
}
