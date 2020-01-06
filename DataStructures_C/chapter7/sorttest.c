/*
 * @Author: junhuizhou
 * @Date: 2020-01-05 16:12:53
 * @LastEditor: junhuizhou
 * @LastEditTime : 2020-01-06 11:36:23
 * @Description: header
 * @FilePath: \DataStructures_C\chapter7\sorttest.c
 */

#include <stdio.h>
#include <time.h>
#include "sort.h"

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

int main()
{
    #define num (500000)
    int A[num];
    int i;

    /*乱序数组生成*/
    for(i=0; i<num; i++)
    {
        A[i] = i+1;
    }
    for(i=1; i<num; i++)
    {
        swap(&A[i], &A[randInt(0, i)]);
    }
    
    /*测试排序*/
    clock_t begin,end;
    begin = clock();    
    // insertionSort(A, num);
    // shellSort(A, num);
    // heapSort(A, num);
    // mergeSort(A, num);
    // quickSort(A, num);
    bucketSort(A, num);
    end = clock();
    printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    
    /*打印部分数组*/
    int printnum = num > 100 ? 100 : num;
    for(i=0; i<printnum; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
