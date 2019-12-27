/*
 * @Author: junhuizhou
 * @Date: 2019-12-16 14:50:25
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-27 20:20:24
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\binheap.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "binheap.h"

#define MIN_PQ_SIZE (10)
#define MIN_DATA (-32767)

struct HeapStruct
{
    int capacity;
    int size;
    ElementType* elements;
};

PriorityQueue Initialize(int maxelement)
{
    PriorityQueue heap;

    if(maxelement < MIN_PQ_SIZE)
    {
        printf("PriorityQueue size is too small\n");
        exit(1);
    }
    heap = malloc(sizeof(struct HeapStruct));
    if(heap == NULL)
    {
        printf("Out of memory!\n");
        exit(1);
    }
    /*Allocate the array plus one extra for sentinel*/
    heap->elements = malloc(sizeof(ElementType)*(maxelement+1));
    if(heap->elements == NULL)
    {
        printf("Out of memory!!\n");
        exit(1);
    }
    heap->capacity = maxelement;
    heap->size = 0;
    heap->elements[0] = MIN_DATA;

    return heap;
}

void makeEmpty(PriorityQueue heap)
{
    heap->size = 0;
}

void Insert(ElementType x, PriorityQueue heap)
{
    int i;
    if(isFull(heap))
    {
        printf("PriorityQueue is full\n");
        return;
    }
    /*heap->size refresh here*/
    for(i=++heap->size; heap->elements[i>>1]>x; i>>=1)
    {
        heap->elements[i] = heap->elements[i>>1];
    }
    heap->elements[i] = x;
}

static void percolateDown(ElementType array[], int len, int father)
{
    int key = array[father];
    int leftchild = father*2;
    int minchild;

    while(leftchild<=len)
    {
        minchild = leftchild;
        if(leftchild < len)
        {
            if(array[leftchild] > array[leftchild+1])
            {
                minchild = leftchild+1;
            }
        }
        if(key <= array[minchild])
        {
            break;
        }
        else
        {
            array[father] = array[minchild];
            father = minchild;
            leftchild = father*2;
        }
    }
    array[father] = key;
}

static void percolateUp(ElementType array[], int len, int child)
{
    int key = array[child];
    int father = child>>1;

    while(father)
    {
        if(key < array[father])
        {
            array[child] = array[father];
            child = father;
            father = child>>1;
        }
        else
        {
            break;
        }
    }
    array[child] = key;
} 

PriorityQueue buildHeapByDown(PriorityQueue heap, ElementType array[], int arraysize)
{
    if(heap == NULL)
    {
        printf("Initialize PriorityQueue first\n");
        exit(1);
    }
    if(arraysize >= heap->capacity)
    {
        printf("Array size is too big\n");
        exit(1);
    }
    heap->size = arraysize;
    while(arraysize--)
    {
        heap->elements[arraysize+1] = array[arraysize];
    }
    /*Percolate down*/
    for(int i=heap->size>>1; i>0; i--)
    {
        percolateDown(heap->elements, heap->size, i);    
    }
    return heap;
}

PriorityQueue buildHeapByUp(PriorityQueue heap, ElementType array[], int arraysize)
{
    if(heap == NULL)
    {
        printf("Initialize PriorityQueue first!\n");
        exit(1);
    }
    if(arraysize >= heap->capacity)
    {
        printf("Array size is too big\n");
        exit(1);
    }
    for(int i=0; i<arraysize; i++)
    {
        Insert(array[i],heap);
    }
    return heap;
}

void Destory(PriorityQueue heap)
{
    /*free对应malloc*/
    free(heap->elements);
    free(heap);
}

void increaseKey(PriorityQueue heap, int position, ElementType delta)
{
    heap->elements[position] += delta;
    percolateDown(heap->elements, heap->size, position);
}
void decreaseKey(PriorityQueue heap, int position, ElementType delta)
{
    heap->elements[position] -= delta;
    percolateUp(heap->elements, heap->size, position);
}

ElementType deleteMin(PriorityQueue heap)
{
    int i, child;
    ElementType minelement, lastelement;
    
    if(isEmpty(heap))
    {
        printf("PriorityQueue is empty\n");
        return heap->elements[0];
    }
    minelement = heap->elements[1];
    /*heap->size refresh here*/
    lastelement = heap->elements[heap->size--];

    for(i=1; i*2<=heap->size; i=child)
    {
        /*Find smaller child*/
        child = i*2;
        if(child!=heap->size && heap->elements[child+1]
                                <heap->elements[child])
        {
            child++;
        }
        /*Percolate one level*/
        if(lastelement > heap->elements[child])
        {
            heap->elements[i] = heap->elements[child];
        }
        else
        {
            break;
        }
    }
    heap->elements[i] = lastelement;
    return minelement;
}

ElementType findMin(PriorityQueue heap)
{
    if(isEmpty(heap))
    {
        printf("PriorityQueue is empty\n");
        return heap->elements[0];
    }
    else
    {
        return heap->elements[1];
    }
}

ElementType Delete(PriorityQueue heap, int position)
{
    int delta = heap->elements[position] - heap->elements[1] + 1;
    decreaseKey(heap, position, delta);
    return deleteMin(heap);
}

int isEmpty(PriorityQueue heap)
{
    return heap->size == 0;
}

int isFull(PriorityQueue heap)
{
    return heap->size == heap->capacity;
}

void printHeap(PriorityQueue heap)
{
    if(isEmpty(heap))
    {
        printf("PriorityQueue is empty!\n");
        return;
    }
    else
    {
        for(int i=1,j=1; i<=heap->size; i++)
        {
            printf("%d ", heap->elements[i]);
            // 到了层末
            if(i == j)
            {
                printf("\n");
                j = 2*i + 1;
            }
        }
        printf("\n");
    }
}

/* **********Exercise 6.9********** */
/* **********func start********** */
/**
 * @description: print all key that less than x
 * @algorithm: 对堆进行前序遍历，把堆当做数组就好
 * @param {type} 
 * @return: 
 */
void printLessX(PriorityQueue heap, ElementType x)
{
    int i = 0;
    while(i++ < heap->size)
    {
        if(heap->elements[i] < x)
        {
            printf("%d ", heap->elements[i]);
        }
    }
    printf("\n");
}
/* **********func end********** */
