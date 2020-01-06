/*
 * @Author: junhuizhou
 * @Date: 2020-01-05 16:12:38
 * @LastEditor: junhuizhou
 * @LastEditTime : 2020-01-06 15:46:33
 * @Description: header
 * @FilePath: \DataStructures_C\chapter7\sort.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * @description: 小程序
 * @algorithm: 
 * @param {type} 
 * @return: 
 */
static void Swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @description: 插入排序
 * @algorithm: 从后往前比较，大的往后挪，比较值插入新位置
 * @param {type} 
 * @return: 
 */
void insertionSort(ElementType array[], int length)
{
    int i, j;
    ElementType key;
    for(i=1; i<length; i++)
    {
        key = array[i];
        for(j=i; j>0 && array[j-1]>key; j--)
        {
            array[j] = array[j-1];
        }
        array[j] = key;
    }
}

/**
 * @description: 希尔排序
 * @algorithm: 分组插入排序
 * @param {type} 
 * @return: 
 */
void shellSort(ElementType array[], int length)
{
    int i, j, increment;
    ElementType key;
    for(increment=length>>1; increment>0; increment>>=1)
    {
        //改为Hibbard增量，Sedgewick增量太麻烦了不整了
        if(increment&1 == 0)
        {
            increment++;
        }
        for(i=increment; i<length; i++)
        {
            key = array[i];
            for(j=i; j>=increment && array[j-increment]>key; j-=increment)
            {
                array[j] = array[j-increment];
            }
            array[j] = key;
        }
    }
}

/**
 * @description: 堆排
 * @algorithm: Max堆的多次deleteMax操作再下滤
 * @param {type} 
 * @return: 
 */
/* **********func start********** */
static void percDown(ElementType array[], int father, int length)
{
    int child;
    ElementType key;
    for(key=array[father]; 2*father+1 < length; father=child)
    {
        child = 2*father+1;
        /*find max child*/
        if(child!=length-1 && array[child+1]>array[child])
        {
            child++;
        }
        /*percolate down*/
        if(key < array[child])
        {
            array[father] = array[child];
        }
        else
        {
            break;
        }
    }
    array[father] = key;
}

void heapSort(ElementType array[], int length)
{
    int i;
    /*Build max heap by down*/
    for(i=length>>1; i>=0; i--)
    {
        percDown(array, i, length);
    }
    /*DeleteMax*/
    ElementType tmp;
    for(i=length-1; i>0; i--)
    {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        percDown(array, 0, i);
    }
}
/* **********func end********** */

/**
 * @description: 归并排序
 * @algorithm: 分而排序，再合并两排好的表
 * @param {type} 
 * @return: 
 */
/* **********func start********** */
static void Merge(ElementType array[], ElementType tmparray[], int lpos, int rpos, int rightend)
{
    int i, leftend, numelements, tmppos;
    leftend = rpos-1;
    tmppos = lpos;
    numelements = rightend-lpos+1;
    /*Main loop*/
    while(lpos<=leftend && rpos<=rightend)
    {
        if(array[lpos] <= array[rpos])
        {
            tmparray[tmppos++] = array[lpos++];
        }
        else
        {
            tmparray[tmppos++] = array[rpos++];
        }
    }
    /*Copy rest of first half*/
    while(lpos <= leftend)
    {
        tmparray[tmppos++] = array[lpos++];
    }
    /*Copy rest of second half*/
    while(rpos <= rightend)
    {
        tmparray[tmppos++] = array[rpos++];
    }
    /*Copy tmparray back*/
    for(i=0; i<numelements; i++,rightend--)
    {
        array[rightend] = tmparray[rightend];
    }
}

static void mSort(ElementType array[], ElementType tmparray[], int left, int right)
{
    int center;
    if(left < right)
    {
        center = (left+right)>>1;
        /*分治法，分而排序，最后合并左右*/
        mSort(array, tmparray, left, center);
        mSort(array, tmparray, center+1, right);
        Merge(array, tmparray, left, center+1, right);
    }
}

void mergeSort(ElementType array[], int length)
{
    ElementType* tmparray;
    tmparray = malloc(sizeof(ElementType)*length);
    if(tmparray == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    else
    {
        mSort(array, tmparray, 0, length-1);
        free(tmparray);
    }
}

// 非递归实现
void mergeSort2(ElementType array[], int length)
{
    ElementType* tmparray;
    int sublistsize, part1start, part2start, part2end;
    tmparray = malloc(sizeof(ElementType)*length);
    if(tmparray == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    else
    {
        for(sublistsize=1; sublistsize<length; sublistsize<<=1)
        {
            part1start = 0;
            while(part1start+sublistsize < length-1)
            {
                part2start = part1start+sublistsize;
                part2end = length < (part2start+sublistsize-1) ? length : (part2start+sublistsize-1);
                Merge(array, tmparray, part1start, part2start, part2end);
                part1start = part2end+1;
            }
        }
    }
    free(tmparray);
}
/* **********func end********** */

/**
 * @description: 快排
 * @algorithm: 
 * @param {type} 
 * @return: 
 */
/* **********func start********** */
ElementType Median3(ElementType array[], int left, int right)
{
    int center = (left+right)>>1;
    if(array[left] > array[center])
    {
        Swap(&array[left], &array[center]);
    }
    if(array[left] > array[right])
    {
        Swap(&array[left], &array[right]);
    }
    if(array[center] > array[right])
    {
        Swap(&array[center], &array[right]);
    }
    /*Hide pivot*/
    Swap(&array[center], &array[right-1]);
    return array[right-1];
}

void qSort(ElementType array[], int left, int right)
{
    int i, j, tmp;
    int cutoff = 3;
    ElementType pivot;
    if(left+cutoff <= right)
    {
        pivot = Median3(array, left, right);
        i = left;
        j = right-1;
        for(;;)
        {
            while(array[++i] < pivot){}
            while(array[--j] > pivot){}
            if(i < j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            else
            {
                break;
            }
        }
        /*Restore pivot*/
        tmp = array[i];
        array[i] = array[right-1];
        array[right-1] = tmp;

        qSort(array, left, i-1);
        qSort(array, i+1, right);
    }
    else
    {
        insertionSort(array+left, right-left+1);
    }
}

void quickSort(ElementType array[], int length)
{
    qSort(array, 0, length-1);    
}
/* **********func end********** */

/**
 * @description: 桶式排序
 * @algorithm: 知道array元素都小于某个数的情况下，本题假设元素介于1-length
 * @param {type} 
 * @return: 
 */
void bucketSort(ElementType array[], int length)
{
    ElementType* tmparray;
    tmparray = malloc(sizeof(ElementType)*(length+1));
    if(tmparray == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    else
    {
        /*bucket sorting*/
        int i = length;
        int j = 0;
        while(i)
        {
            tmparray[i] = 0;
            i--;
        }
        i = length;
        while(i--)
        {
            tmparray[array[i]] = array[i];
        }
        i = 0;
        while(++i <= length)
        {
            if(tmparray[i])
            {
                array[j++] = tmparray[i];
            }
        }
        free(tmparray);
    }
}
