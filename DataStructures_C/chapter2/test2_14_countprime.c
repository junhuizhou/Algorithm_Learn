/*
 * @Author: junhuizhou
 * @Date: 2019-11-23 16:30:35
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-24 10:45:23
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\test2_14_erotosthenes.c
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @description: eratosthenes筛法求0-n内质数个数
 * @param n  范围上限，包含n本身共n+1个数
 * @return: 
 */
int eratosthenes(int n)
{
    int* prime;
    prime = (int *)malloc(sizeof(int)*(n+1));    
    // 首先0,1非质数也非合数，不管了，故从2开始，默认其他数是合数置1，确定为质数时置0
    int i, j, count=0;
    for(i=2; i<n+1; i++)
    {
        prime[i] = 1;
    }
    // 从2开始将质数的倍数都定为合数，其中合数前面肯定有个小于它的质数将该合数定为合数
    for(i=2; i<n+1; i++)
    {
        if(prime[i])
        {
            count++;
            for(j=i+i; j<n+1; j+= i)
            {
                prime[j] = 0;
            }
        }
    }
    free(prime);
    prime = NULL;
    return count;
}

/**
 * @description: 将eratosthenes算法用bit计数代替int计数，win10中测试int=4byte=32bit
 * @others: 
 * @param {type} 
 * @return: 
 */
int bitMap(int n)
{
    int* prime;
    // 还是先计算出sizeof(int)再按移位操作，使用sizeint的除法性能反而下降
    // int sizeint = sizeof(int)*8;
    prime = (int *)malloc(sizeof(int) * ((n+1)/32 + 1));
    // 为计数方便，质数置1，合数置0，先默认合数故置0
    int i, j, count=0;
    for(i=2; i<n+1; i++)
    {
        prime[i>>5] = 0;
    }
    for(i=2; i<n+1; i++)
    {
        // prime[i/sizeint][i&(sizeint-1)]没登记时为0，登记为质数则为1，用&(1<<(i&(sizeint-1)))判断是否登记
        if((prime[i>>5] & (1<<(i&(31)))) == 0)    
        {
            count++;
            for(j=i+i; j<n+1; j+=i)
            {
                // 或运算置1进行登记
                prime[j>>5] |= 1<<(j&(31));
            }
        }
    }
    free(prime);
    prime = NULL;
    return count;
}

int main()
{
    clock_t begin,end;
    printf("intmax = %d\n", __INT_MAX__);
    int n;
    scanf("%d",&n);
    begin = clock();
    printf("count of prime between 0 to %d is %d\n", n, eratosthenes(n));
    end = clock();
    printf("time of eratosthenes is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("count of prime between 0 to %d is %d\n", n, bitMap(n));
    end = clock();
    printf("time of bitMap is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}
