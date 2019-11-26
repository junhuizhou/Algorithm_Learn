/*
 * @Author: junhuizhou
 * @Date: 2019-11-26 20:12:00
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-26 21:11:03
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\queuearray.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "queuearray.h"

#define MIN_QUEUE_SIZE 5

struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *array;
};

int isEmpty(Queue queue)
{
    return queue->size == 0;
}

int isFull(Queue queue)
{
    return queue->size == queue->capacity;
}

Queue createQueue(int maxelements)
{
    Queue queue;
    if(maxelements < MIN_QUEUE_SIZE)
    {
        printf("Queue size is too small");
    }
    queue = malloc(sizeof(struct QueueRecord));
    if(queue == NULL)
    {
        printf("Out of memory");
    }
    queue->array = malloc(sizeof(ElementType)*maxelements);
    if(queue->array == NULL)
    {
        printf("Out of memory");
    }
    queue->capacity = maxelements;
    makeEmpty(queue);
    return queue;
}

void makeEmpty(Queue queue)
{
    queue->size = 0;
    queue->front = 1;
    queue->rear = 0;
}

void disposeQueue(Queue queue)
{
    if(queue != NULL)
    {
        free(queue->array);
        free(queue);
    }
}

static int Succ(int value, Queue queue)
{
    if(++value == queue->capacity)
    {
        value = 0;
    }
    return value;
}

void Enqueue(ElementType x, Queue queue)
{
    if(isFull(queue))
    {
        printf("Queue is full");
    }
    else
    {
        queue->size++;
        // queue->rear++;   要处理回环情况
        queue->rear = Succ(queue->rear, queue);  
        queue->array[queue->rear] = x;
    }    
}

ElementType Front(Queue queue)
{
    if(!isEmpty(queue))
    {
        return queue->array[queue->front];
    }
    else
    {
        printf("Empty queue");
        return 0;
    }
}

void Dequeue(Queue queue)
{
    if(isEmpty(queue))
    {
        printf("Empty queue");
    }
    else
    {
        queue->size--;
        queue->front = Succ(queue->front,queue);
    }    
}

ElementType frontAndDequeue(Queue queue)
{
    ElementType x = 0;
    if(isEmpty(queue))
    {
        printf("Empty queue");
    }
    else
    {
        queue->size--;
        x = queue->array[queue->front];
        queue->front = Succ(queue->front,queue);
    }
    return x;
}
