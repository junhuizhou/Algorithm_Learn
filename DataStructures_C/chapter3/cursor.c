/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 17:21:32
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 15:26:38
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\cursor.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "cursor.h"

struct Node
{
    ElementType element;
    Position next;
};

/*
 * CursorSpace数组可分为两部分，一部分为链表（即已经储存数据的那一部分），另一部分为freelist（即未储存数据的那一部分）。
 * 执行malloc功能时，从开头（0下标后开始算）取空间，被取出的元素从freelist中删除，成为链表的一部分。
 * 执行free功能时，将元素放回开头（0下标后开始算），被放回的元素从链表中删除，成为freelist的一部分。
 */
struct Node cursorspace[spacesize];

static Position cursorAlloc(void)
{
    Position p;
    p = cursorspace[0].next;
    cursorspace[0].next = cursorspace[p].next;
    return p;
}

static void cursorFree(Position p)
{
    cursorspace[p].next = cursorspace[0].next;
    cursorspace[0].next = p;
}

void initializeCursorSpace(void)
{
    for(int i=0; i<spacesize; i++)
    {
        cursorspace[i].next = i+1;
    }
    cursorspace[spacesize-1].next = 0;
}

List makeEmpty(List list)
{
    if(list != 0)
    {
        deleteList(list);
    }
    list = cursorAlloc();
    if(list == 0)
    {
        printf("Out of memory\n");
        exit(1);
    }
    cursorspace[list].next = 0;
}

int isEmpty(List list)
{
    return cursorspace[list].next == 0;
}

int isLast(Position position, List list)
{
    return cursorspace[position].next == 0;
}

Position Find(ElementType x, List list)
{
    Position p;
    p = cursorspace[list].next;
    while(p && cursorspace[p].element != x)
    {
        p = cursorspace[p].next;
    }
    return p;
}

void Delete(ElementType x, List list)
{
    Position p, tmpcell;
    p = findPrevious(x, list);
    if(!isLast(p, list))
    {
        tmpcell = cursorspace[p].next;
        cursorspace[p].next = cursorspace[tmpcell].next;
        cursorFree(tmpcell);
    }
}

Position findPrevious(ElementType x, List list)
{
    Position p;
    p = list;
    while(cursorspace[p].next &&
            cursorspace[cursorspace[p].next].element != x)
    {
        p = cursorspace[p].next;
    }    
    return p;
}

void Insert(ElementType x, List list, Position position)
{
    Position tmpcell;
    tmpcell = cursorAlloc();
    if(tmpcell == 0)
    {
        printf("Out of memory\n");
        exit(1);
    }
    cursorspace[tmpcell].element = x;
    cursorspace[tmpcell].next = cursorspace[position].next;
    cursorspace[position].next = tmpcell;
}

void deleteList(List list)
{
    Position p, tmp;
    p = cursorspace[list].next;
    cursorspace[list].next = 0;
    while(p != 0)
    {
        tmp = cursorspace[p].next;
        cursorFree(p);
        p = tmp;
    }
}

Position Header(List list)
{
    return list;
}

Position First(List list)
{
    return cursorspace[list].next;
}

Position Advance(Position position)
{
    return cursorspace[position].next;
}

ElementType Retrieve(Position position)
{
    return cursorspace[position].element;
}

void printList(List list)
{
    if(list == 0)
    {
        printf("Empty list\n");
        return;
    }
    Position p;
    p = cursorspace[list].next;
    while(p != 0)
    {
        printf("%d ", cursorspace[p].element);
        p = cursorspace[p].next;
    }
    printf("\n");
}
