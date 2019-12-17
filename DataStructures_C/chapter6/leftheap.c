/*
 * @Author: junhuizhou
 * @Date: 2019-12-17 18:53:28
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-17 19:52:05
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\leftheap.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "leftheap.h"

struct TreeNode
{
    ElementType element;
    PriorityQueue left;
    PriorityQueue right;
    int Npl;
};

PriorityQueue Initialize(void)
{
    return NULL;
}

int isEmpty(PriorityQueue heap)
{
    return heap == NULL;
}

ElementType findMin(PriorityQueue heap)
{
    if(isEmpty(heap))
    {
        printf("PriorityQueue is empty\n");
        return 0;
    }
    else
    {
        return heap->element;
    }
}

static PriorityQueue Merge1(PriorityQueue heap1, PriorityQueue heap2)
{
    if(heap1->left == NULL)
    {
        heap1->left = heap2;
    }
    else
    {
        heap1->right = Merge(heap1->right, heap2);
        if(heap1->left->Npl < heap1->right->Npl)
        {
            PriorityQueue tmp;
            tmp = heap1->left;
            heap1->left = heap1->right;
            heap1->right = tmp;
        }
        heap1->Npl = heap1->right->Npl + 1;
    }
    return heap1;
}

PriorityQueue Merge(PriorityQueue heap1, PriorityQueue heap2)
{
    if(heap1 == NULL)
    {
        return heap2;
    }
    if(heap2 == NULL)
    {
        return heap1;
    }
    if(heap1->element < heap2->element)
    {
        return Merge1(heap1, heap2);
    }
    else
    {
        return Merge1(heap2, heap1);
    }
}

PriorityQueue Inser1(ElementType x, PriorityQueue heap)
{
    PriorityQueue singlenode;
    singlenode = malloc(sizeof(struct TreeNode));
    if(singlenode == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    else
    {
        singlenode->element = x;
        singlenode->left = singlenode->right = NULL;
        heap = Merge(heap, singlenode);
    }
    return heap;
}

PriorityQueue deleteMin1(PriorityQueue heap)
{
    PriorityQueue leftheap, rightheap;
    if(isEmpty(heap))
    {
        printf("PriorityQueue is empty\n");
        return heap;
    }
    else
    {
        leftheap = heap->left;
        rightheap = heap->right;
        free(heap);
        return Merge(leftheap, rightheap);
    }
}
