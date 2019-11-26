/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 21:19:40
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-26 21:58:03
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
        printf("Out of memory");
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
        printf("Must use creeatStack first");
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
        printf("Out of memory");
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
        printf("Empty stack");
        return 0;
    }
}

void Pop(Stack stack)
{
    PtrToNode firstcell;
    if(isEmpty(stack))
    {
        printf("Empty stack");
    }
    else
    {
        firstcell = stack->next;
        stack->next = firstcell->next;
        free(firstcell);
    }
}
