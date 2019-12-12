/*
 * @Author: junhuizhou
 * @Date: 2019-12-09 14:39:49
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-12 20:25:16
 * @Description: header
 * @FilePath: \ItTDaAoA\chapter3\section3.1\bubblesort.c
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
 * @description: 冒泡排序，从小到大
 * @param {type} 
 * @return: 
 */
void bubbleSort(int array[], int len)
{
    int i,j,tmp;
    for(i=0; i<len; i++)
    {
        for(j=0; j<len-1-i; j++)
        {
            if(array[j+1] < array[j])
            {
                Swap(&array[j+1], &array[j]);
            }
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
    /*冒泡排序*/
    bubbleSort(A, num);
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
