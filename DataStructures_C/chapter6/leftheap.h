/*
 * @Author: junhuizhou
 * @Date: 2019-12-17 18:53:17
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-17 19:55:36
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\leftheap.h
 */

#ifndef DS_CHAP6_LEFTHEAP_H_
#define DS_CHAP6_LEFTHEAP_H_

struct TreeNode;
typedef struct TreeNode* PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(void);
int isEmpty(PriorityQueue heap);
ElementType findMin(PriorityQueue heap);
PriorityQueue Merge(PriorityQueue heap1, PriorityQueue heap2);

#define Insert(x, heap) (heap = Insert1((x), heap))
// TODO: define deletMin
PriorityQueue Inser1(ElementType x, PriorityQueue heap);
PriorityQueue deleteMin1(PriorityQueue heap);

#endif
