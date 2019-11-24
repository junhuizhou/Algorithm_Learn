/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 17:21:20
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-24 18:23:05
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\cursor.h
 */

#ifndef DS_CHAP3_CURSOR_H_
#define DS_CHAP3_CURSOR_H_

struct Node;
typedef int PtrToNode;
typedef PtrToNode List;         // List是表头，也指整个表
typedef PtrToNode Position;     // Position是一个Node，在表中移动
typedef int ElementType;
#define spacesize 100

void initializeCursorSpace(void);
List makeEmpty(List list);
int isEmpty(const List list);
int isLast(const Position position, const List list);
Position Find(ElementType x, const List list);
void Delete(ElementType x, List list);
Position findPrevious(ElementType x, const List list);
void Insert(ElementType x, List list, Position position);
void deleteList(List list);
// private?
Position Header(const List list);
Position First(const List list);
Position Advance(const Position position);
ElementType Retrieve(const Position position);

#endif
