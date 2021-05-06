/*
 * @Author: junhuizhou
 * @Date: 2020-03-27 21:22:42
 * @LastEditor: junhuizhou
 * @LastEditTime: 2020-03-27 21:31:04
 * @Description: header
 * @FilePath: \DataStructures_C\chapter12\redblacktree.h
 */

#ifndef DS_CHAP12_REDBLACKTREE_H_
#define DS_CHAP12_REDBLACKTREE_H_

struct RedBlackNode;
typedef struct RedBlackNode* RedBlackTree;
typedef struct RedBlackNode* Position;
typedef int ElementType;

RedBlackTree Initialize(void);
RedBlackTree MakeEmpty(RedBlackTree tree);
RedBlackTree Insert(ElementType x, RedBlackTree tree);
RedBlackTree Remove(ElementType x, RedBlackTree tree);
Position Find(ElementType x, RedBlackTree tree);
Position FindMin(RedBlackTree tree);
Position FindMax(RedBlackTree tree);
ElementType Retrieve(Position position);
void PrintTree(RedBlackTree tree);

#endif
