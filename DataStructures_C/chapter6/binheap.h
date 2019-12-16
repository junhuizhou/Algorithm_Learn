/*
 * @Author: junhuizhou
 * @Date: 2019-12-16 14:50:17
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-16 20:24:02
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\binheap.h
 */

#ifndef DS_CHAP6_BINHEAP_H_
#define DS_CHAP6_BINHEAP_H_

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(int maxelement);
PriorityQueue buildHeapByDown(PriorityQueue heap, ElementType array[], int arraysize);
PriorityQueue buildHeapByUp(PriorityQueue heap, ElementType array[], int arraysize);
void makeEmpty(PriorityQueue heap);
void Insert(ElementType x, PriorityQueue heap);
void Destory(PriorityQueue heap);
ElementType deleteMin(PriorityQueue heap);
ElementType findMin(PriorityQueue heap);
int isEmpty(PriorityQueue heap);
int isFull(PriorityQueue heap);
void printHeap(PriorityQueue heap);

#endif
