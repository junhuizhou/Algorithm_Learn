/*
 * @Author: junhuizhou
 * @Date: 2019-12-16 14:50:17
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-27 20:13:30
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
void increaseKey(PriorityQueue heap, int position, ElementType delta);
void decreaseKey(PriorityQueue heap, int position, ElementType delta);
ElementType deleteMin(PriorityQueue heap);
ElementType findMin(PriorityQueue heap);
ElementType Delete(PriorityQueue heap, int position);
int isEmpty(PriorityQueue heap);
int isFull(PriorityQueue heap);
void printHeap(PriorityQueue heap);
/*from Exercises*/
void printLessX(PriorityQueue heap, ElementType x);

#endif
