/*
 * @Author: junhuizhou
 * @Date: 2019-11-27 17:31:22
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-27 18:56:38
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_3_swap.c
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int element;
    struct Node* next;
};

typedef int ElementType;
typedef struct Node* Position;
typedef struct Node* List;

List creatList()
{
    List list;
    list = malloc(sizeof(struct Node));
    if(list == NULL)
    {
        printf("Out of memory\n");
    }
    list->next = NULL;
    return list;
}

Position findEnd(List list)
{
    while(list->next != NULL)
    {
        list = list->next;
    }
    return list;
}

void Insert(List list, ElementType x)
{
    Position tmpcell, endcell;
    tmpcell = malloc(sizeof(struct Node));
    if(tmpcell == NULL)
    {
        printf("Out of memory\n");
        return;
    }
    endcell = findEnd(list);
    tmpcell->element = x;
    tmpcell->next = NULL;
    endcell->next = tmpcell;
}

void printList(List list)
{
    Position position;
    position = list->next;
    while(position != NULL)
    {
        printf("%d ",position->element);
        position = position->next;
    }
    printf("\n");
}

void Swap(List list, Position beforep)
{
    Position p, afterp;
    p = beforep->next;
    afterp = p->next;

    p->next = afterp->next;
    beforep->next = afterp;
    afterp->next = p;
}

int main()
{
    List list;
    list = creatList();
    for(int i=1; i<10; i++)
    {
        Insert(list,i);
    }
    printList(list);
    Swap(list, list->next->next);
    printList(list);
    return 0;
}
