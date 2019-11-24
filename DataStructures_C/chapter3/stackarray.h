/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 21:20:31
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-24 23:10:42
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\stackarray.h
 */

#ifndef DS_CHAP3_STACKARRAY_H_
#define DS_CHAP3_STACKARRAY_H_

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int isEmpty(Stack stack);
int isFull(Stack stack);
Stack createStack(int maxelements);
void makeEmpty(Stack stack);
void disposeStack(Stack stack);
void Push(ElementType x,Stack stack);
ElementType Top(Stack stack);
void Pop(Stack stack);
ElementType topAndPop(Stack stack);

#endif
