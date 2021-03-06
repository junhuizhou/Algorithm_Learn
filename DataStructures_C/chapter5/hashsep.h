/*
 * @Author: junhuizhou
 * @Date: 2019-12-12 15:57:33
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-15 21:53:12
 * @Description: header
 * @FilePath: \DataStructures_C\chapter5\hashsep.h
 */

#ifndef DS_CHAP5_HASHSEP_H_
#define DS_CHAP5_HASHSEP_H_

struct ListNode;
typedef struct ListNode* Position;
typedef struct ListNode* List;
struct HashTbl;
typedef struct HashTbl* HashTable; 
typedef int ElementType;    // TODO: 写个typdef char ElementType版本
typedef unsigned int Index;

HashTable initializeTable(int tablesize);
Position Find(ElementType key, HashTable hashtable);
void Insert(ElementType key, HashTable hashtable);
void destroyTable(HashTable hashtable);
ElementType Retrieve(Position position);

#endif
