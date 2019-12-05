/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 11:12:07
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 14:33:02
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\list.h
 */

#ifndef DS_CHAP3_LIST_H_
#define DS_CHAP3_LIST_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;         // List是表头，也指整个表
typedef PtrToNode Position;     // Position是一个Node，在表中移动
typedef int ElementType;

List makeEmpty(List list);
int isEmpty(List list);
int isLast(Position position, List list);
Position Find(ElementType x, List list);
void Delete(ElementType x, List list);
Position findPrevious(ElementType x, List list);
void Insert(ElementType x, List list, Position position);
void deleteList(List list);
Position Header(List list);
Position First(List list);
Position Advance(Position position);
ElementType Retrieve(Position position);
void printList(List list);

#endif
