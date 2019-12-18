/*
 * @Author: junhuizhou
 * @Date: 2019-12-18 16:00:57
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-18 16:10:12
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\binomialqueue.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "binomialqueue.h"

struct BinNode
{
    ElementType element;
    Position leftchild;
    Position nextsibling;
};

struct Collection
{
    int currentsize;
    BinTree thetrees[MAX_TREES];
};

BinQueue Initialize(void)
{
    BinQueue heap;
    int i;

    heap = malloc(sizeof(struct Collection));
    if(heap == NULL)
    {
        printf("OUt of memory\n");
        exit(1);
    }
    heap->currentsize = 0;
    for(i=0; i<MAX_TREES; i++)
    {
        heap->thetrees[i] = NULL;
    }
    return heap;
}

static void destroyTree(BinTree tree)
{
    if(tree != NULL)
    {
        destroyTree(tree->leftchild);
        destroyTree(tree->nextsibling);
        free(tree);
    }
}

BinQueue makeEmpty(BinQueue heap)
{
    int i;
    for(i=0; i<MAX_TREES; i++)
    {
        destroyTree(heap->thetrees[i]);
    }
    heap->currentsize = 0;
    return heap;
}

int isEmpty(BinQueue heap)
{
    return heap->currentsize == 0;
}

int isFull(BinQueue heap)
{
    return heap->currentsize == CAPACITY;
}

BinQueue Insert(ElementType x, BinQueue heap)
{
    BinTree newnode;
    BinQueue oneitem;

    newnode = malloc(sizeof(struct BinNode));
    if(newnode == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    newnode->leftchild = newnode->nextsibling = NULL;
    newnode->element = x;

    oneitem = Initialize();
    oneitem->currentsize = 1;
    oneitem->thetrees[0] = newnode;

    return Merge(heap, oneitem);
}
static BinTree combineTrees(BinTree tree1, BinTree tree2)
{
    if(tree1->element > tree2->element)
    {
        return combineTrees(tree2, tree1);
    }
    tree2->nextsibling = tree1->leftchild;
    tree1->leftchild = tree2;
    return tree1;
}

BinQueue Merge(BinQueue heap1, BinQueue heap2)
{
    BinTree tree1, tree2, carry = NULL;
    int i, j;

    if(heap1->currentsize + heap2->currentsize > CAPACITY)
    {
        printf("Merge would exceed capacity\n");
        exit(1);
    }

    heap1->currentsize += heap2->currentsize;
    for(i=0,j=1; j<=heap1->currentsize; i++,j*=2)
    {
        tree1 = heap1->thetrees[i];
        tree2 = heap2->thetrees[i];
        switch(!!tree1 + 2*!!tree2 + 4*!!carry)
        {
            case 0: break;
            case 1: break;
            case 2:
                heap1->thetrees[i] = tree2;
                heap2->thetrees[i] = NULL;
                break;
            case 4:
                heap1->thetrees[i] = carry;
                carry = NULL;
                break;
            case 3:
                carry = combineTrees(tree1, tree2);
                heap1->thetrees[i] = NULL;
                heap2->thetrees[i] = NULL;
                break;
            case 5:
                carry = combineTrees(tree1,carry);
                heap1->thetrees[i] = NULL;
                break;
            case 6:
                carry = combineTrees(tree2,carry);
                heap2->thetrees[i] = NULL;
                break;
            case 7:
                heap1->thetrees[i] = carry;
                carry = combineTrees(tree1,tree2);
                heap2->thetrees[i] = NULL;
                break;
        }
    }

    return heap1;
}

ElementType findMin(BinQueue heap)
{
    int i;
    ElementType minitem;

    if(isEmpty(heap))
    {
        printf("BinomialQueue is empty\n");
        return 0;
    }
    minitem = INFINITY;
    for(i=0; i<MAX_TREES; i++)
    {
        if(heap->thetrees[i] && heap->thetrees[i]->element < minitem)
        {
            minitem = heap->thetrees[i]->element;
        }
    }
}

ElementType deleteMin(BinQueue heap)
{
    int i, j;
    int mintree;
    BinQueue deletequeue;
    Position deletetree, oldroot;
    ElementType minitem;

    /*find minitem and mintree*/
    if(isEmpty(heap))
    {
        printf("BinomialQueue is empty\n");
        return -INFINITY;
    }
    minitem = INFINITY;
    for(i=0; i<MAX_TREES; i++)
    {
        if(heap->thetrees[i] && heap->thetrees[i]->element < minitem)
        {
            minitem = heap->thetrees[i]->element;
            mintree = i;
        }
    }

    /*delete minitem*/
    deletetree = heap->thetrees[mintree];
    oldroot = deletetree;
    deletetree = deletetree->leftchild;
    free(oldroot);

    /*collect deletetree*/
    deletequeue = Initialize();
    deletequeue->currentsize = (1<<mintree) - 1;
    for(j=mintree-1; j>=0; j--)
    {
        deletequeue->thetrees[j] = deletetree;
        deletetree = deletetree->nextsibling;
        deletequeue->thetrees[j]->nextsibling = NULL;
    }

    /*edit heap and merge*/
    heap->thetrees[mintree] = NULL;
    heap->currentsize -= deletequeue->currentsize + 1;
    Merge(heap, deletequeue);
    return minitem;
}

void Destroy(BinQueue heap)
{
    makeEmpty(heap);
    free(heap);
}
