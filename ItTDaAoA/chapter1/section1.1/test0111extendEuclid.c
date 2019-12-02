/*
 * @Author: junhuizhou
 * @Date: 2019-12-02 11:10:42
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-02 12:38:53
 * @Description: header
 * @FilePath: \ItTDaAoA\chapter1\test010111extendEuclid.c
 */

#include <stdio.h>

/**
 * @description: https://blog.csdn.net/yoer77/article/details/69568676
 * @param {type} 
 * @return: 
 */
int exEuclid(int a, int b, int *x, int *y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    int gcd = exEuclid(b, a%b, x, y);
    int tmp = *x;
    *x = *y;
    *y = tmp - a/b*(*y);
    return gcd;
}

/**
 * @description:不定方程的特解 https://blog.csdn.net/AAMahone/article/details/79320635
 * @param {type} 
 * @return: 1 找到整数解， 0 未找到整数解
 */
int Diophantus(int a, int b, int c,int *x, int *y, int *gcd)
{
    *gcd = exEuclid(a,b,x,y);
    if(c%(*gcd) == 0)
    {
        int k = c/(*gcd);
        *x *= k;
        *y *= k;
        return 1;
    }
    else
    {
        return 0;
    }  
}

int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    int tmp;
    if(a < b)
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    int x, y, gcd;
    if(Diophantus(a,b,c,&x,&y,&gcd))
    {
        printf("%d*%d + %d*%d = %d\n", a, x, b, y, c);
    }
    else
    {
        printf("Fail to slove\n");
    }
    printf("%d*%d + %d*%d = %d\n", a, x, b, y, gcd);
    return 0;   
}
