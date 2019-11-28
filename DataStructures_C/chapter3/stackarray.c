/*
 * @Author: junhuizhou
 * @Date: 2019-11-24 21:20:17
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-28 17:12:24
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\stackarray.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackarray.h"

#define EMPTY_ST -1 
#define MIN_STACK_SIZE 5

struct StackRecord
{
    int capacity;
    int stacktop;
    ElementType *array;
};

int isEmpty(Stack stack)
{
    return stack->stacktop == EMPTY_ST;
}

int isFull(Stack stack)
{
    return stack->stacktop == stack->capacity-1;
}

Stack createStack(int maxelements)
{
    Stack stack;
    if(maxelements < MIN_STACK_SIZE)
    {
        printf("Stack size is too small\n");
        exit(1);
    }
    stack = malloc(sizeof(struct StackRecord));
    if(stack == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    stack->array = malloc(sizeof(ElementType)*maxelements);
    if(stack->array == NULL)
    {
        printf("Out if memory\n");
        exit(1);
    }
    stack->capacity = maxelements;
    makeEmpty(stack);
    return stack;
}

void makeEmpty(Stack stack)
{
    stack->stacktop = EMPTY_ST;
}

void disposeStack(Stack stack)
{
    if(stack != NULL)
    {
        free(stack->array);
        free(stack);
    }
}

void Push(ElementType x,Stack stack)
{
    if(isFull(stack))
    {
        printf("Full stack\n");
        return;
    }
    else
    {
        stack->array[++stack->stacktop] = x;
    }
}

ElementType Top(Stack stack)
{
    if(!isEmpty(stack))
    {
        return stack->array[stack->stacktop];
    }
    else
    {
        printf("Empty stack\n");
        return 0;
    }   
}

void Pop(Stack stack)
{
    if(!isEmpty(stack))
    {
        stack->stacktop--;
    }
}

ElementType topAndPop(Stack stack)
{
    if(!isEmpty(stack))
    {
        return stack->array[stack->stacktop--];
    }
    else
    {
        printf("Empty stack\n");
    }
}
