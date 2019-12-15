/*
 * @Author: junhuizhou
 * @Date: 2019-12-13 16:36:37
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-15 18:49:48
 * @Description: header
 * @FilePath: \DataStructures_C\chapter5\hashquad.h
 */

#ifndef DS_CHAP5_HASHQUAD_H_
#define DS_CHAP5_HASHQUAD_H_

struct HashTbl;
typedef struct HashTbl* HashTable;
typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;

HashTable initializeTable(int tablesize);
HashTable Rehash(HashTable hashtable);
Position Find(ElementType key, HashTable hashtable);
void Insert(ElementType key, HashTable hashtable);
void destroyTable(HashTable hashtable);
ElementType Retrieve(Position position, HashTable hashtable);

#endif
