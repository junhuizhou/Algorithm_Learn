/*
 * @Author: junhuizhou
 * @Date: 2019-12-12 21:41:55
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-12 22:07:32
 * @Description: header
 * @FilePath: \ItTDaAoA\chapter4\section4.1\shellsort.c
 */

#include <stdio.h>
#include <time.h>

int randInt(int min, int max)
{
    srand((int)time(0));
    return rand()%(max-min+1) + min;
}

void Swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @description: shell排序，改进版
 * @param {type} 
 * @return: 
 */
void shellSort(int array[], int len)
{
    int i,j,gap;
    int tmp;
    for(gap=len>>1; gap>0; gap>>=1)
    {
        for(i=gap; i<len; i++)
        {
            tmp = array[i];
            j = i-gap;
            while(j>=0 && array[j]>tmp)
            {
                array[j+gap] = array[j];
                j -= gap;
            }
            array[j+gap] = tmp;
        }
    }
}

int main()
{
    clock_t begin,end;
    /*乱序数组生成*/
    #define num (50)
    int A[num];
    int i;
    for(i=0; i<num; i++)
    {
        A[i] = i+1;
    }
    for(i=1; i<num; i++)
    {
        Swap(&A[i], &A[randInt(0, i)]);
    }
    /*打印数组*/
    for(i=0; i<num; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    begin = clock();
    /*shell排序*/
    shellSort(A, num);
    /*运行时间*/
    end = clock();
    printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    /*打印数组*/
    for(i=0; i<num; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
