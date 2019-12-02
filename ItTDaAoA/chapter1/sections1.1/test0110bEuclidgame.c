/*
 * @Author: junhuizhou
 * @Date: 2019-12-02 10:49:59
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-02 12:17:49
 * @Description: header
 * @FilePath: \ItTDaAoA\chapter1\test010110bEuclidgame.c
 */

#include <stdio.h>

/**
 * @description: 出现在地板上的个数就是地板上的最大值除以他的最大公约数，如何证明？
 * @param {type} 
 * @return: 
 */
void EuclidGame(int a, int b)
{
    int tmp;
    if(a < b)
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    int max = a;
    while(b != 0)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    if((max/a)&1)
    {
        printf("the first one will win this game\n");
    }
    else
    {
        printf("the second one will win this game\n");
    }
    
}

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    EuclidGame(a, b);    
    return 0;
}
