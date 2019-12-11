/*
 * @Author: junhuizhou
 * @Date: 2019-12-02 21:52:45
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-11 16:26:11
 * @Description: header
 * @FilePath: \DataStructures_C\chapter4\binarysearchtree.h
 */

#ifndef DS_CHAP4_BINARYSEARCHTREE_H_
#define DS_CHAP4_BINARYSEARCHTREE_H_

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;

SearchTree makeEmpty(SearchTree tree);
Position Find(ElementType x, SearchTree tree);
Position findMin(SearchTree tree);
Position findMax(SearchTree tree);
SearchTree Insert(ElementType x, SearchTree tree);
SearchTree Delete(ElementType x, SearchTree tree);
ElementType Retrieve(Position position);
void printTree(SearchTree tree);
/*from Exercises*/
int countNodes(SearchTree tree);
int countLeaves(SearchTree tree);
int countFull(SearchTree tree);
SearchTree makeRandomTree(int num);
SearchTree perfectTree(int height);
void printRange(ElementType lower, ElementType upper, SearchTree tree);
void printLevelOrder(SearchTree tree);

#endif
