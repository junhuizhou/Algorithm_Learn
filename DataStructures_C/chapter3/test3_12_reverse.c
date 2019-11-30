/*
 * @Author: junhuizhou
 * @Date: 2019-11-30 14:48:48
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-30 16:04:51
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_12.c
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
 * @description: 倒着生成list,先NULL，...，最后Hearder,话说CSDN上一些操作的链表是不带表头的，注意修改
 * @param {type} 
 * @return: 
 */
List reverseList(List list)
{
    Position p, tmp;
    List newlist = creatList();
    // 跳过表头
    p = list->next;
    while(p != NULL)
    {
        tmp = p;
        p = p->next;
        tmp->next = newlist->next;
        newlist->next = tmp;
    }
    return newlist;
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
    list = reverseList(list);
    printList(list);
    deleteList(list);
    return 0;
}
