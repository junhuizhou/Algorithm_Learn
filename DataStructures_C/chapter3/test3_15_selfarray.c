/*
 * @Author: junhuizhou
 * @Date: 2019-11-30 18:33:28
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-30 20:42:11
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_15_selfadjustarray.c
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 5
typedef struct Record * SelfAdjust;
typedef int ElementType;
typedef int Position;
struct Record
{
    int capacity;
    int rear;
    ElementType *array;
};

SelfAdjust creatList(int space)
{
    if(space < MIN_SIZE)
    {
        printf("space is too small\n");
        exit(1);
    }
    SelfAdjust s = malloc(sizeof(struct Record));
    if(s == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    s->array = malloc(sizeof(ElementType)*space);
    if(s->array == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    s->capacity = space;
    s->rear = -1;
    return s;
}

/**
 * @description: 头插
 * @param {type} 
 * @return: 
 */
void Insert(SelfAdjust s, ElementType x)
{
    if(s->rear+1 == s->capacity)
    {
        printf("Out of memory\n");
        return;
    }
    // 将前面的值赋值给后面
    for(int i=s->rear+1; i>=1; i--)
    {
        s->array[i] = s->array[i-1];
    }
    s->array[0] = x;
    s->rear++;
}

/**
 * @description: 查而头插
 * @param {type} 
 * @return: 
 */
Position Find(SelfAdjust s, ElementType x)
{
    Position p = -1;
    // 先找到x
    for(int i=0; i<=s->rear; i++)
    {
        if(s->array[i] == x)
        {
            p = i;
            break;
        }
    }
    if(p != -1)
    {
        ElementType tmp = s->array[p];
        // 前面的往后挪，腾出首位
        for(int i=p; i>=1; i--)
        {
            s->array[i] = s->array[i-1];
        }
        s->array[0] = tmp;
        return 0;
    }
    else
    {
        return -1;
    }
}

void deleteList(SelfAdjust s)
{
    if(s != NULL)
    {
        free(s->array);
        free(s);
    }    
}

int main()
{
    #define n 60
    SelfAdjust s = creatList(n);
    for(int i=0; i<10; i++)
    {
        Insert(s, i+1);
    }
    printf("where: %d", Find(s, 5));
    for(int i=0; i<10; i++)
    {
        printf("%d ", s->array[i]);
    }
    printf("\n");
    deleteList(s);
    return 0;
}
