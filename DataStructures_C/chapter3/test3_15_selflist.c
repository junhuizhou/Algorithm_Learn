/*
 * @Author: junhuizhou
 * @Date: 2019-11-30 19:53:27
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-30 20:41:25
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_15_selflist.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node* List;
typedef struct Node* Position;
typedef int ElementType;
struct Node
{
    ElementType element;
    Position next;
};

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

void deleteList(List list)
{
    if(list == NULL)
    {
        printf("Use creatList first\n");
    }
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

/**
 * @description: 头插
 * @param {type} 
 * @return: 
 */
void Insert(List list, ElementType x)
{
    Position tmp = malloc(sizeof(struct Node));
    if(tmp == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    tmp->element = x;
    tmp->next = list->next;
    list->next = tmp;
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

/**
 * @description: 查而头插
 * @param {type} 
 * @return: 
 */
Position Find(List list, ElementType x)
{
    Position p, prepos;
    prepos = findPrevious(x, list);
    if(prepos->next == NULL)
    {
        return NULL;
    }
    else
    {
        p = prepos->next;
        prepos->next = p->next;
        p->next = list->next;
        list->next = p;
        return p;
    }   
}

int main()
{
    List list;
    list = creatList(list);
    for(int i=0; i<10; i++)
    {
        Insert(list, i+1);
    }
    Position p =  Find(list, 5);
    printList(list);
    deleteList(list);
    return 0;
}
