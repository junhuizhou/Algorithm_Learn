/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 11:12:01
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-15 21:15:25
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\list.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node
{
    ElementType element;
    Position next;
};

List makeEmpty(List list)
{
    if(list != NULL)
    {
        deleteList(list);
    }
    list = malloc(sizeof(struct Node));
    if(list == NULL)
    {
        printf("Out of memory\n");
    }
    list->next = NULL;
    return list;
    
}

int isEmpty(List list)
{
    return list->next == NULL;
}

int isLast(Position position, List list)
{
    return position->next == NULL;
}

Position Find(ElementType x, List list)
{
    Position p;
    p = list->next; 
    while(p != NULL && p->element != x)
    {
        p = p->next;
    }
    return p;
}

void Delete(ElementType x, List list)
{
    Position p, tmpcell;
    p = findPrevious(x, list);
    if(!isLast(p, list))
    {
        tmpcell = p->next;
        p->next = tmpcell->next;
        free(tmpcell);
    }
}

Position findPrevious(ElementType x, List list)
{
    Position p;
    p = list;   
    while(p->next != NULL && p->next->element != x)
    {
        p = p->next;
    }
    return p;    
}

void Insert(ElementType x, List list, Position position)
{
    Position tmpcell;
    tmpcell = malloc(sizeof(struct Node));
    if(tmpcell == NULL)
    {
        printf("Out of memory\n");
    }
    tmpcell->element = x;
    tmpcell->next = position->next;
    position->next = tmpcell;
}

void deleteList(List list)
{
    Position p, tmp;
    p = list->next;
    list->next = NULL;
    while(p != NULL)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

Position Header(List list)
{
    return list;
}

Position First(List list)
{
    return list->next;
}

Position Advance(Position position)
{
    return position->next;
}

ElementType Retrieve(Position position)
{
    return position->element;
}

void printList(List list)
{
    if(list == NULL)
    {
        printf("Empty list\n");
        return;
    }
    Position p;
    p = list->next;
    while(p != NULL)
    {
        printf("%d ", p->element);
        p = p->next;
    }
    printf("\n");
}
