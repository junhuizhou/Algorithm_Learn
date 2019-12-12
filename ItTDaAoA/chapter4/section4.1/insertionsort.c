/*
 * @Author: junhuizhou
 * @Date: 2019-12-12 22:00:25
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-12 22:13:49
 * @Description: header
 * @FilePath: \ItTDaAoA\chapter4\section4.1\insertionsort.c
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
 * @description: 插入排序
 * @param {type} 
 * @return: 
 */
void insertionSort(int array[], int len)
{
    int i,j,key;
    for (i=1; i<len; i++)
    {
        key = array[i];
        j = i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
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
    /*插入排序*/
    insertionSort(A, num);
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
