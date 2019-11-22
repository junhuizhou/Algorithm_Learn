/*
 * @Author: junhuizhou
 * @Date: 2019-11-22 19:28:11
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-22 20:45:54
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\test2_16_pown2.c
 */

#include <stdio.h>
#include <time.h>

/**
 * @description: 不需递推的求幂程序，类似test2_9中将指数拆开，此处使用二进制的方式拆开
 * @others: 参考https://www.cnblogs.com/XiangfeiAi/p/4738087.html
 * @param x 底数
 * @param n 指数 
 * @return: pownresult 幂
 */
long int powN2(int x, unsigned int n)
{
    long int pownresult = 1;
    while (n)
    {
        if(n&1)
        {
            pownresult *= x;
        }
        n >>= 1;    // 即n = n>>1，其中n>>1表示n二进制右移1位
        x *= x;
    }
    return pownresult;    
}

int main()
{
    clock_t begin,end;
    int x = 2;
    int n;  //long int PowN的X只能到2^31
    scanf("%d", &n);
    begin = clock();
    printf("sum of 2^%d is %ld\n", n, powN2(x,n));
    end = clock();
    printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}
