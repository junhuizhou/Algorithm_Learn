/*
 * @Author: junhuizhou
 * @Date: 2019-12-26 18:08:36
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-26 22:38:37
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\test6_2_3_build.c
 */

#include <stdio.h>
#include "binheap.h"

int main()
{
    #define testnum (15)
    PriorityQueue heap1, heap2;
    int testarray[testnum] = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};
    int i;

    /*build heap by Insert*/
    printf("build heap by Insert\n");
    heap1 = Initialize(testnum*2);
    for(i=0; i<testnum; i++)
    {
        Insert(testarray[i], heap1);
    }
    printHeap(heap1);

    /*build heap by down*/
    printf("build heap by down\n");
    heap2 = Initialize(testnum*2);
    heap2 = buildHeapByDown(heap2, testarray, testnum);
    printHeap(heap2);

    /*deletemin x 3*/
    printf("deletemin x 3\n");
    i = 3;
    while(i--)
    {
        deleteMin(heap1);
        deleteMin(heap2);
    }
    printHeap(heap1);
    printHeap(heap2);

    Destory(heap1);
    Destory(heap2);
    
    return 0;
}
