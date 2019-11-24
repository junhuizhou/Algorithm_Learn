/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 21:19:57
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-24 21:31:25
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\stacklist.h
 */

#ifndef DS_CHAP3_STACKLIST_H_
#define DS_CHAP3_STACKLIST_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int isEmpty(Stack stack);
Stack createStack(void);
void makeEmpty(Stack stack);
void disposeStack(Stack stack);
void Push(ElementType x, Stack stack);
ElementType Top(Stack stack);
void Pop(Stack stack);

#endif
