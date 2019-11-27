/*
 * @Author: junhuizhou
 * @Date: 2019-11-27 14:21:53
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-27 18:58:21
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_1_printlist.c
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

int main()
{
    List list;
    list = creatList();
    for(int i=1; i<10; i++)
    {
        Insert(list,i);
    }
    printList(list);
    return 0;
}
