/*
 * @Author: junhuizhou
 * @Date: 2019-11-21 21:17:48
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-21 21:52:10
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\test2_9.c
 */

#include <stdio.h>
#include <time.h>

long int PowN(long int X, unsigned int N)
{
    if(N == 0)
    {
        return 1;
    }
    if((N&1) == 0)  // 和1“与”之后为0则是偶数，为1则是奇数
    {
        return PowN(X*X, N/2);
    }
    else
    {
        return PowN(X*X, N/2)*X;
    }
    
}

int main()
{
    clock_t begin,end;
    int x = 2;
    long int sum = 0;
    int n;  //long int PowN的X只能到2^31
    scanf("%d", &n);
    begin = clock();
    for(int i=1; i<=n; i++)
    {
        sum += PowN(x,i);
    }
    printf("sum of 2^%d is %ld\n", n, sum);
    end = clock();
    printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}