/*
 * @Author: junhuizhou
 * @Date: 2019-11-21 10:31:17
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-22 20:58:46
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\maxsubsequencesum.c
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @description: 最大子序列和，fig2_5，for*3
 * @param a[] 原序列
 * @param n 序列長度 
 * @return: maxsum 最大序列和
 */
int maxSubsequenceSum1(const int a[], int n)
{
    int thissum, maxsum, i, j, k;
    maxsum = 0;
    for(i=0; i<n; i++)
    {        
        for(j=i; j<n; j++)
        {
            thissum = 0;
            for(k=i; k<=j; k++)
            {
                thissum += a[k];
            }            
            if(thissum > maxsum)
            {
                maxsum = thissum;
            }
        }
    }
    return maxsum;
}

/**
 * @description: 最大子序列和，fig2_6，for*2
 * @param a[] 原序列
 * @param n 序列长度 
 * @return: maxsum 最大序列和
 */
int maxSubsequenceSum2(const int a[], int n)
{
    int thissum, maxsum, i, j;
    maxsum = 0;
    for(i=0; i<n; i++)
    {
        thissum = 0;
        for(j=i; j<n; j++)
        {
            thissum += a[j];
            if(thissum > maxsum)
            {
                maxsum = thissum;
            }
        }
    }
    return maxsum;
}

/**
 * @description: 最大序列和，fig2_7，二分法
 * @param {type} 
 * @return: 
 */
static int maxSubSum(const int a[], int left, int right)
{
    int maxleftsum, maxrightsum;
    int center, i;
    // 二分递归求解左右两边的最大序列和     
    if(left == right)
    {
        if(a[left] > 0)
        {
            return a[left];
        }
        else
        {
            return 0;
        }
    }
    center = (left+right)/2;
    maxleftsum = maxSubSum(a, left, center);
    maxrightsum = maxSubSum(a, center+1, right);
    // 从中间出发求解中左和中右的最大序列和，再相加即为中间最大序列和
    int max_left_border_sum, max_right_border_sum;
    int leftbordersum, rightbordersum;
    max_left_border_sum = 0;
    leftbordersum = 0;
    for(i=center; i>=left; i--)
    {
        leftbordersum += a[i];
        if(leftbordersum > max_left_border_sum)
        {
            max_left_border_sum = leftbordersum;
        }
    }
    max_right_border_sum = 0;
    rightbordersum = 0;
    for(i=center+1; i<=right; i++)
    {
        rightbordersum += a[i];
        if(rightbordersum > max_right_border_sum)
        {
            max_right_border_sum = rightbordersum;
        }
    }
    // 比较三大序列和
    maxleftsum = maxleftsum>maxrightsum ? maxleftsum:maxrightsum;
    maxleftsum = maxleftsum>max_left_border_sum+max_right_border_sum ? maxleftsum:max_left_border_sum+max_right_border_sum;
    return maxleftsum;
}
int maxSubsequenceSum3(const int a[], int n)
{
    return maxSubSum(a, 0, n-1);
}

/**
 * @description: 最大序列和，fig2_8，保证左边不为负即可获得局部最优解，用maxsum进行各局部比较，似乎叫联机算法
 * @param {type} 
 * @return: 
 */
int maxSubsequenceSum4(const int a[], int n)
{
    int thissum, maxsum;
    thissum = maxsum = 0;
    for(int i=0; i<n; i++)
    {
        thissum += a[i];
        if(thissum > maxsum)
        {
            maxsum = thissum;
        }
        else if (thissum < 0)
        {
            thissum = 0;
        }        
    }
    return maxsum;
}

int main()
{
    clock_t begin,end;
    #define n 1000
    int a[n];
    srand((int)time(0));
    for(int i=0; i<n; i++)
    {
        a[i] = rand()%100 - 50;
    }
    begin = clock();
    printf("maxsum = %d\n", maxSubsequenceSum1(a, n));
    end = clock();
    printf("time of subcode1 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("maxsum = %d\n", maxSubsequenceSum2(a, n));
    end = clock();
    printf("time of subcode2 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("maxsum = %d\n", maxSubsequenceSum3(a, n));
    end = clock();
    printf("time of subcode3 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("maxsum = %d\n", maxSubsequenceSum4(a, n));
    end = clock();
    printf("time of subcode4 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}
