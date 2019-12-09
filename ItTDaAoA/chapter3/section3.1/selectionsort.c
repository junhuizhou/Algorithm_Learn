/*
 * @Author: junhuizhou
 * @Date: 2019-12-09 14:39:34
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-09 15:12:56
 * @Description: header
 * @FilePath: \ItTDaAoA\chapter3\section3.1\selectionsort.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt(int min, int max)
{
    srand((int)time(0));
    return rand()%(max-min+1) + min;
}

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @description: 选择排序，一次扫描确定一个位置，多次扫描从最小起逐个确定
 * @param {type} 
 * @return: 
 */
void selectionSort(int array[], int len)
{
    int i,j;
    for(i=0; i<len-1; i++)
    {
        int minpos = i;
        for(j=i+1; j<len; j++)
        {
            if(array[j] < array[minpos])
            {
                minpos = j;
            }
        }
        swap(&array[minpos], &array[i]);
    }
}

int main()
{
    clock_t begin,end;
    /*乱序数组生成*/
    #define num 50
    int A[num];
    int i;
    for(i=0; i<num; i++)
    {
        A[i] = i+1;
    }
    for(i=1; i<num; i++)
    {
        swap(&A[i], &A[randInt(0, i)]);
    }
    /*打印数组*/
    for(i=0; i<num; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    begin = clock();
    /*选择排序*/
    selectionSort(A, num);
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
