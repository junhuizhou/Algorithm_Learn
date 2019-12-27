/*
 * @Author: junhuizhou
 * @Date: 2019-12-26 23:05:54
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-27 19:31:46
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\test6_9_lessx.c
 */

#include <stdio.h>
#include "binheap.h"

int main()
{
    #define testnum (15)
    PriorityQueue heap;
    int testarray[testnum] = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};
    int x;

    printf("Input: ");
    scanf("%d", &x);

    heap = Initialize(testnum*2);
    heap = buildHeapByDown(heap, testarray, testnum);
    printHeap(heap);

    printLessX(heap, x);
    
    return 0;
}
