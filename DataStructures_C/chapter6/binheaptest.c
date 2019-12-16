/*
 * @Author: junhuizhou
 * @Date: 2019-12-16 15:51:32
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-16 20:40:00
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\binheaptest.c
 */

#include <stdio.h>
#include <time.h>
#include "binheap.h"

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
    #define num (50)
    PriorityQueue heap;
    // 生成heap中需要的数
    int A[num];
    int i;
    // 先生成num个不同的数
    for(i=0; i<num; i++)
    {
        A[i] = i+1;
    }
    // 再将所有数打乱
    for(i=1; i<num; i++)
    {
        swap(&A[i], &A[randInt(0, i)]);
    }

    heap = Initialize(num*2);
    heap = buildHeapByDown(heap, A, num);
    printf("isfull: %d\n", isFull(heap));
    printf("isempty: %d\n", isEmpty(heap));
    printHeap(heap);
    printf("min is %d\n", deleteMin(heap));
    printHeap(heap);
    Insert(1, heap);
    printHeap(heap);
    Destory(heap);

    return 0;
}