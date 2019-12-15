/*
 * @Author: junhuizhou
 * @Date: 2019-12-13 16:36:27
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-15 21:18:38
 * @Description: header
 * @FilePath: \DataStructures_C\chapter5\hashquad.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashquad.h"

#define MIN_TABLE_SIZE (10)

enum KindOfEntry {kLegitimate, kEmpty, kDeleted};

struct HashEntry
{
    ElementType element;
    enum KindOfEntry info;
};
typedef struct HashEntry Cell;

struct HashTbl
{
    int tablesize;
    Cell* thecells;
};

/**
 * @description: 产生比num大的第一个质数
 * @param {type} 
 * @return: 
 */
static int nextPrime(int num)
{
    if(num&1 == 0)
    {
        num += 1;
    }
    int i;
    int isprime = 0;
    for(; ; num+=2)
    {
        for(i=3; i*i<=num; i+=2)
        {
            if(num%i == 0)
            {
                isprime = 1;
                break;
            }
        }
        if(isprime)
        {
            return num;
        }
    }
}

/*ElementType == int*/
static Index Hash(ElementType key, int tablesize)
{
    return key % tablesize;
}
/*ElementTypt == "char"*/
// static Index Hash(const char* key, int tablesize)
// {
//     unsigned int hashval = 0;
//     while(*key != '\0')
//     {
//         hashval = (hashval<<5) + *key++;
//     }
//     return hashval % tablesize;
// }

HashTable initializeTable(int tablesize)
{
    HashTable hashtable;
    int i;

    if(tablesize < MIN_TABLE_SIZE)
    {
        printf("Table size is too small\n");
        return NULL;
    }
    /*Allocate table*/
    hashtable = malloc(sizeof(struct HashTbl));
    if(hashtable == NULL)
    {
        printf("Out of memory!\n");
        exit(1);
    }
    hashtable->tablesize = nextPrime(tablesize);
    /*Allocate array of cells*/
    hashtable->thecells = malloc(sizeof(Cell)*hashtable->tablesize);
    if(hashtable->thecells == NULL)
    {
        printf("Out of memory!!\n");
        exit(1);
    }
    for(i=0; i<hashtable->tablesize; i++)
    {
        hashtable->thecells[i].info = kEmpty;
    }

    return hashtable;
}

HashTable Rehash(HashTable hashtable)
{
    int i, oldsize;
    Cell* oldcells;

    oldcells = hashtable->thecells;
    oldsize = hashtable->tablesize;
    /*Get a new, empty table*/
    hashtable = initializeTable(2*oldsize);
    /*Scan through old table, reinserting into new*/
    for(i=0; i<oldsize; i++)
    {
        if(oldcells[i].info == kLegitimate)
        {
            Insert(oldcells[i].element, hashtable);
        }
    }
    free(oldcells);
    return hashtable;
}

Position Find(ElementType key, HashTable hashtable)
{
    Position currentpos;
    int collisionnum;

    collisionnum = 0;
    currentpos = Hash(key, hashtable->tablesize);
    while(hashtable->thecells[currentpos].info!=kEmpty && \
        hashtable->thecells[currentpos].element!=key)   //Probably need strcmp
    {
        currentpos += 2* ++collisionnum - 1;
        if(currentpos >= hashtable->tablesize)
        {
            currentpos -= hashtable->tablesize;
        }
    }
    return currentpos;
}

void Insert(ElementType key, HashTable hashtable)
{
    Position pos;

    pos = Find(key, hashtable);
    if(hashtable->thecells[pos].info != kLegitimate)
    {
        hashtable->thecells[pos].info = kLegitimate;
        hashtable->thecells[pos].element = key;     //Probably need strcpy
    }
}

void destroyTable(HashTable hashtable)
{
    free(hashtable->thecells);
    free(hashtable);
}

ElementType Retrieve(Position position, HashTable hashtable)
{
    return hashtable->thecells[position].element;
}
