/*
 * @Author: junhuizhou
 * @Date: 2019-12-12 15:57:43
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-12 18:57:46
 * @Description: header
 * @FilePath: \DataStructures_C\chapter5\hashsep.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashsep.h"

#define MIN_TABLE_SIZE (10)

struct ListNode
{
    ElementType element;
    Position next;
};

struct HashTbl
{
    int tablesize;
    List* thelists;
};

/**
 * @description: 生成稍大于num的质数
 * @param {type} 
 * @return: 
 */
static int nextPrime(int num)
{
    
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
        printf("Out of memory\n");
        exit(1);
    }
    hashtable->tablesize = nextPrime(tablesize);
    /*Allocate array of lists*/
    hashtable->thelists = malloc(sizeof(List)*hashtable->tablesize);
    if(hashtable->thelists == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    /*Allocate list headers*/
    hashtable->thelists = malloc(sizeof(struct ListNode)*hashtable->tablesize);
    for(i=0; i<hashtable->tablesize; i++)
    {
        if(hashtable->thelists[i] == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
        else
        {
            hashtable->thelists[i]->next = NULL;
        }
    }

    return hashtable;
}

Position Find(ElementType key, HashTable hashtable)
{
    Position p;
    List list;
    list = hashtable->thelists[Hash(key,hashtable->tablesize)];
    p = list->next;
    while(p!=NULL && p->element!=key) //Probably need strcmp
    {
        p = p->next;
    }
    return p;
}

void Insert(ElementType key, HashTable hashtable)
{
    Position p, newcell;
    List list;
    p = Find(key, hashtable);
    if(p == NULL)
    {
        newcell = malloc(sizeof(struct ListNode));
        if(newcell == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
        else
        {
            list = hashtable->thelists[Hash(key,hashtable->tablesize)];
            newcell->element = key; //Probably needstrcpy
            newcell->next = list->next;
            list->next = newcell;
        }
    }
}

void destroyTable(HashTable hashtable)
{
    Position p, tmp;
    int i;
    for(i=0; i<hashtable->tablesize; i++)
    {
        p = hashtable->thelists[i];
        while(p != NULL)
        {
            tmp = p->next;
            free(p);
            p = tmp;
        }
    }
    free(hashtable->thelists);
    free(hashtable);
}

ElementType Retrieve(Position position)
{
    return position->element;
}
