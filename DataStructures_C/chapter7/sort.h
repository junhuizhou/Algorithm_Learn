/*
 * @Author: junhuizhou
 * @Date: 2020-01-05 16:12:44
 * @LastEditor: junhuizhou
 * @LastEditTime : 2020-01-06 14:58:48
 * @Description: header
 * @FilePath: \DataStructures_C\chapter7\sort.h
 */

#ifndef DS_CHAP7_SORT_H_
#define DS_CHAP7_SORT_H_

typedef int ElementType;

void insertionSort(ElementType array[], int length);
void shellSort(ElementType array[], int length);
void heapSort(ElementType array[], int length);
void mergeSort(ElementType array[], int length);
void mergeSort2(ElementType array[], int length);
void quickSort(ElementType array[], int length);
void bucketSort(ElementType array[], int length);

#endif
