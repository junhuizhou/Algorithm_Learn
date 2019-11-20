/*
 * @Author: junhuizhou
 * @Date: 2019-11-20 20:48:28
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-20 22:05:29
 * @Description: header
 * @FilePath: /DataStructures_C/chapter1/fig1_2.c
 */
#include <stdio.h>
#include <time.h>

/**
 * @description: 简单递归demo
 * @param 
 * @return: 
 */
int F(int x)
{
    if(x == 0)
    {
        return 0;
    }
    else
    {
        return 2*F(x-1) + x*x;
    }    
}

int main()
{
    clock_t begin,end;
    int x;
    scanf("%d", &x);
    begin = clock();
    printf("x = %d\n", x);
    printf("F(%d) = %d\n", x, F(x));
    end = clock();
    printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}