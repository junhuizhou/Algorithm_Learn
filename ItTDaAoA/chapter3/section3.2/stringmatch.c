/*
 * @Author: junhuizhou
 * @Date: 2019-12-09 16:49:58
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-09 17:02:36
 * @Description: header
 * @FilePath: \Algorithm_Learn\ItTDaAoA\chapter3\section3.2\stringmatch.c
 */

#include <stdio.h>

/**
 * @description: 蛮力字符串匹配
 * @param {type} 
 * @return: 
 */
int main()
{
    #define n 18
    #define m 3
    char text[n+1] = "NOBODY_NOTICED_HIM";
    char pattern[m+1] = "NOT";
    int i,j;
    for(i=0; i<=n-m; i++)
    {
        j = 0;
        while(j<m && pattern[j]==text[i+j])
        {
            j += 1;
            if(j == m)
            {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    printf("match failed\n");
    return -1;
}
