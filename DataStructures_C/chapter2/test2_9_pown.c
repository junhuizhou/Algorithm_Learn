/*
 * @Author: junhuizhou
 * @Date: 2019-11-21 21:17:48
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-23 21:34:42
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\test2_9_pown.c
 */

#include <stdio.h>
#include <time.h>

long int powN(long int x, unsigned int n)
{
    if(n == 0)
    {
        return 1;
    }
    if((n&1) == 0)  // &1 == %2，&n == %(n+1)
    {
        return powN(x*x, n/2);
    }
    else
    {
        return powN(x*x, n/2)*x;
    }
    
}

int main()
{
    clock_t begin,end;
    int x = 2;
    long int sum = 0;
    int n;  //long int powN的x只能到2^31
    scanf("%d", &n);
    begin = clock();
    for(int i=1; i<=n; i++)
    {
        sum += powN(x,i);
    }
    printf("sum of 2^%d is %ld\n", n, sum);
    end = clock();
    printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}
