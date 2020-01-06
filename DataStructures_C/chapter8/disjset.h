/*
 * @Author: junhuizhou
 * @Date: 2020-01-06 17:21:53
 * @LastEditor: junhuizhou
 * @LastEditTime : 2020-01-06 17:28:04
 * @Description: header
 * @FilePath: \DataStructures_C\chapter8\disjset.h
 */

#ifndef DS_CHAP8_DISJSET_H_
#define DS_CHAP8_DISJSET_H_

#define NUMSETS (128)
typedef int DisjSet[NUMSETS+1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet ds);
void setUnion(DisjSet ds, SetType root1, SetType root2);
SetType Find(ElementType x, DisjSet ds);

#endif
