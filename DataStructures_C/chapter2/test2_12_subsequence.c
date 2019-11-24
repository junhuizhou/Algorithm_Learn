/*
 * @Author: junhuizhou
 * @Date: 2019-11-22 20:07:49
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-23 16:17:38
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\test2_12_subsequence.c
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @description: 最小序列和，联机算法，保证左边不为正即可
 * @param {type} 
 * @return: 
 */
int minSubsequenceSum(const int a[], int n)
{
    int thissum, minsum;
    thissum = minsum = 0;
    for(int i=0; i<n; i++)
    {
        thissum += a[i];
        if(thissum < minsum)
        {
            minsum = thissum;
        }
        else if(thissum > 0)
        {
            thissum = 0;
        }
    }
    return minsum;
}

/**
 * @description: 最小正子序列和，联机算法，"最小正"要么是thissum要么是a[i]
 * @param {type} 
 * @return: 
 */
int minPositiveSubSum(const int a[], int n)
{
    int thissum, minpositivesum;
    thissum = 0;
    minpositivesum = __INT_MAX__;
    for(int i=0; i<n; i++)
    {
        if(a[i] < minpositivesum && a[i] > 0)
        {
            minpositivesum = a[i];
        }
        thissum += a[i];        
        if(thissum < minpositivesum && thissum > 0)
        {
            minpositivesum = thissum;
        }   
    }   
    return minpositivesum; 
}

/**
 * @description: 最大序列乘，联机算法，定两列一路乘过去，出现负数交换一下两列的值就行
 * @param {type} 
 * @return: 
 */
int maxSubsequenceMul(const int a[], int n)
{
    int imax, imin, maxmul;
    imax = imin = 1;
    maxmul = -1*__INT_MAX__;
    for(int i=0; i<n; i++)
    {
        if(a[i] < 0)
        {
            int tmp = imin;
            imin = imax;
            imax = tmp;
        }
        imax *= a[i];
        imin *= a[i];
        if(imax < a[i])
        {
            imax = a[i];
        }
        if(imin > a[i])
        {
            imin = a[i];
        }
        if(imax > maxmul)
        {
            maxmul = imax;
        }
    }
    return maxmul;
}

int main()
{
    clock_t begin,end;
    #define n 100000
    int a[n];
    srand((int)time(0));
    for(int i=0; i<n; i++)
    {
        a[i] = rand()%100 - 50;
    }
    // int n = 7;
    // int a[7] = {-3, 4, 5, -1, 0, -1, -2};
    begin = clock();
    printf("minSum = %d\n", minSubsequenceSum(a, n));
    end = clock();
    printf("time of subcode1 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("minSum = %d\n", minPositiveSubSum(a, n));
    end = clock();
    printf("time of subcode2 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("maxMul = %d\n", maxSubsequenceMul(a, n));
    end = clock();
    printf("time of subcode2 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    printf("intmax = %d", __INT_MAX__);
    return 0;
}
