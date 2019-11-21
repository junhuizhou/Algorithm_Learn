/*
 * @Author: junhuizhou
 * @Date: 2019-11-21 10:31:17
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-21 15:34:33
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\MaxSubsequenceSum.c
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * @description: 最大子序列和，fig2_5，for*3
 * @param A[] 原序列
 * @param N 序列長度 
 * @return: MaxSum 最大序列和
 */
int MaxSubsequenceSum1(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;
    MaxSum = 0;
    for(i=0; i<N; i++)
    {        
        for(j=i; j<N; j++)
        {
            ThisSum = 0;
            for(k=i; k<=j; k++)
            {
                ThisSum += A[k];
            }            
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

/**
 * @description: 最大子序列和，fig2_6，for*2
 * @param A[] 原序列
 * @param N 序列长度 
 * @return: MaxSum 最大序列和
 */
int MaxSubsequenceSum2(const int A[], int N)
{
    int ThisSum, MaxSum, i, j;
    MaxSum = 0;
    for(i=0; i<N; i++)
    {
        ThisSum = 0;
        for(j=i; j<N; j++)
        {
            ThisSum += A[j];
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

/**
 * @description: 最大序列和，fig2_7，二分法
 * @param {type} 
 * @return: 
 */
static int MaxSubSum(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int Center, i;
    // 二分递归求解左右两边的最大序列和     
    if(Left == Right)
    {
        if(A[Left] > 0)
        {
            return A[Left];
        }
        else
        {
            return 0;
        }
    }
    Center = (Left+Right)/2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center+1, Right);
    // 从中间出发求解中左和中右的最大序列和，再相加即为中间最大序列和
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for(i=Center; i>=Left; i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for(i=Center+1; i<=Right; i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;
        }
    }
    // 比较三大序列和
    MaxLeftSum = MaxLeftSum>MaxRightSum ? MaxLeftSum:MaxRightSum;
    MaxLeftSum = MaxLeftSum>MaxLeftBorderSum+MaxRightBorderSum ? MaxLeftSum:MaxLeftBorderSum+MaxRightBorderSum;
    return MaxLeftSum;
}
int MaxSubsequenceSum3(const int A[], int N)
{
    return MaxSubSum(A, 0, N-1);
}

/**
 * @description: 最大序列和，fig2_8，保证左边不为负即可获得局部最优解，用MaxSum进行各局部比较
 * @param {type} 
 * @return: 
 */
int MaxSubsequenceSum4(const int A[], int N)
{
    int ThisSum, MaxSum;
    ThisSum = 0;
    for(int i=0; i<N; i++)
    {
        ThisSum += A[i];
        if(ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
        }        
    }
    return MaxSum;
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
    printf("MaxSum = %d\n", MaxSubsequenceSum1(a, n));
    end = clock();
    printf("time of subcode1 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("MaxSum = %d\n", MaxSubsequenceSum2(a, n));
    end = clock();
    printf("time of subcode2 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("MaxSum = %d\n", MaxSubsequenceSum3(a, n));
    end = clock();
    printf("time of subcode3 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    begin = clock();
    printf("MaxSum = %d\n", MaxSubsequenceSum4(a, n));
    end = clock();
    printf("time of subcode4 is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}
