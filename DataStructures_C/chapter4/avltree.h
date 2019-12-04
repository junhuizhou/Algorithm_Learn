/*
 * @Author: junhuizhou
 * @Date: 2019-12-04 15:36:59
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-04 15:47:05
 * @Description: header
 * @FilePath: \DataStructures_C\chapter4\avltree.h
 */

#ifndef DS_CHAP4_AVLTREE_H_
#define DS_CHAP4_AVLTREE_H_

struct AvlNode;
typedef struct AvlNode* AvlTree;
typedef struct AvlNode* Position;
typedef int ElementType;

AvlTree makeEmpty(AvlTree tree);
Position Find(ElementType x, AvlTree tree);
Position findMin(AvlTree tree);
Position findMax(AvlTree tree);
AvlTree Insert(ElementType x, AvlTree tree);
AvlTree Delete(ElementType x, AvlTree tree);
ElementType Retrieve(Position position);

#endif
