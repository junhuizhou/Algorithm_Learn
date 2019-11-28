/*
 * @Author: junhuizhou
 * @Date: 2019-11-27 16:46:22
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-28 16:11:07
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_2_printlots.c
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

/**
 * @description: 根据p输出l，p\l都是升序排列
 * @param {type} 
 * @return: 
 */
void printLots(List l, List p)
{
    Position lpos, ppos;
    lpos = l->next;
    ppos = p->next;
    int count = 1;
    while(lpos!=NULL && ppos!=NULL)
    {
        if(ppos->element == count++)
        {
            printf("%d ", lpos->element);
            ppos = ppos->next;
        }
        lpos = lpos->next;
    }
    printf("\n");
}

void deleteList(List list)
{
    if(list == NULL)
    {
        printf("Use creatList first");
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

int main()
{
    #define n 10
    int a[5] = {1,2,6,7,9};
    List list1, list2;
    list1 = creatList();
    list2 = creatList();
    for(int i=0; i<n; i++)
    {
        Insert(list1, 2*i+1);
    }
    for(int i=0; i<5; i++)
    {
        Insert(list2, a[i]);
    }
    printList(list1);
    printList(list2);
    printLots(list1, list2);
    deleteList(list1);
    deleteList(list2);
    return 0;
}
