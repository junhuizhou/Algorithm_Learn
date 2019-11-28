/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 21:19:40
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-28 17:15:39
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\stacklist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

struct Node
{
    ElementType element;
    PtrToNode   next;
};

int isEmpty(Stack stack)
{
    return stack->next == NULL;
}

Stack createStack(void)
{
    Stack stack;
    stack = malloc(sizeof(struct Node));
    if(stack == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    stack->next = NULL;
    makeEmpty(stack);
    return stack;
}

/**
 * @description: 因只能操作top，不像list操作header，只能不断Pop
 * @param {type} 
 * @return: 
 */
void makeEmpty(Stack stack)
{
    if(stack == NULL)
    {
        printf("Must use creeatStack first\n");
        return;
    }
    else
    {
        while(!isEmpty(stack))
        {
            Pop(stack);
        }
    }    
}

void disposeStack(Stack stack)
{
    makeEmpty(stack);
    free(stack);
}

void Push(ElementType x, Stack stack)
{
    PtrToNode tmpcell;
    tmpcell = malloc(sizeof(struct Node));
    if(tmpcell == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    else
    {
        tmpcell->element = x;
        tmpcell->next = stack->next;
        stack->next = tmpcell;
    }
}

ElementType Top(Stack stack)
{
    if(!isEmpty(stack))
    {
        return stack->next->element;
    }
    else
    {
        printf("Empty stack\n");
        return 0;
    }
}

void Pop(Stack stack)
{
    PtrToNode firstcell;
    if(isEmpty(stack))
    {
        printf("Empty stack\n");
    }
    else
    {
        firstcell = stack->next;
        stack->next = firstcell->next;
        free(firstcell);
    }
}
