/*
 * @Author: junhuizhou
 * @Date: 2019-12-18 16:01:09
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-18 16:02:29
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\binomialqueue.h
 */

#ifndef DS_CHAP6_BINOMIALQUEUE_H_
#define DS_CHAP6_BINOMIALQUEUE_H_

#define MAX_TREES (14)
#define CAPACITY (16383)
#define INFINITY (30000L)

struct BinNode;
struct Collection;
typedef struct BinNode* BinTree;
typedef struct BinNode* Position;
typedef struct Collection* BinQueue;
typedef long ElementType;

BinQueue Initialize(void);
BinQueue makeEmpty(BinQueue heap);
int isEmpty(BinQueue heap);
int isFull(BinQueue heap);
BinQueue Insert(ElementType x, BinQueue heap);
BinQueue Merge(BinQueue heap1, BinQueue heap2);
ElementType findMin(BinQueue heap);
ElementType deleteMin(BinQueue heap);
void Destroy(BinQueue heap);

#endif
