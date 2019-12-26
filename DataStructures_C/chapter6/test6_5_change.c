/*
 * @Author: junhuizhou
 * @Date: 2019-12-26 20:21:43
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-26 22:38:27
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\test6_5_change.c
 */

#include <stdio.h>
#include "binheap.h"

int main()
{
    #define testnum (15)
    PriorityQueue heap;
    int testarray[testnum] = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};
    int i;

    heap = Initialize(testnum*2);
    heap = buildHeapByUp(heap, testarray, testnum);
    printHeap(heap);

    increaseKey(heap, 1, 10);
    printHeap(heap);

    decreaseKey(heap, 14, 9);
    printHeap(heap);

    Destory(heap);
    return 0;
}
