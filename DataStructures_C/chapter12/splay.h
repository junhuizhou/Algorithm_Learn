/*
 * @Author: junhuizhou
 * @Date: 2020-03-27 10:39:15
 * @LastEditor: junhuizhou
 * @LastEditTime: 2020-03-27 13:34:05
 * @Description: header
 * @FilePath: \DataStructures_C\chapter12\splay.h
 */

#ifndef DS_CHAP12_SPLAY_H_
#define DS_CHAP12_SPLAY_H_

struct SplayNode;
typedef struct SplayNode* SplayTree;
typedef struct SplayNode* Position;
typedef int ElementType;

SplayTree Initialize(void);
SplayTree MakeEmpty(SplayTree tree);
SplayTree Insert(ElementType x, SplayTree tree);
SplayTree Remove(ElementType x, SplayTree tree);
SplayTree Find(ElementType x, SplayTree tree);
SplayTree FindMin(SplayTree tree);
SplayTree FindMax(SplayTree tree);
ElementType Retrieve(SplayTree tree);   // gets root item
void PrintTree(SplayTree tree);

#endif
