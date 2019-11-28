/*
 * @Author: junhuizhou
 * @Date: 2019-11-26 21:18:38
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-28 17:10:17
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\queuelist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

#define MIN_QUEUE_SIZE 5

struct Node
{
    ElementType element;
    QueueNode next;
};

struct QueueRecord
{
    int size;
    QueueNode front;
    QueueNode rear;
};

int isEmpty(Queue queue)
{
    return queue->size == 0;
}

Queue createQueue(int maxelements)
{
    Queue queue;
    if(maxelements < MIN_QUEUE_SIZE)
    {
        printf("Queue size is too small\n");
        exit(1);
    }
    queue = malloc(sizeof(struct QueueRecord));
    if(queue == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    queue->front = malloc(sizeof(struct Node));
    if(queue->front == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    makeEmpty(queue);
    return queue;
}

void makeEmpty(Queue queue)
{
    if(queue == NULL)
    {
        printf("Use creatQueue first\n");
        return;
    }
    else
    {
        QueueNode p, tmp;
        while(!isEmpty(queue))
        {
            p = queue->front->next;
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    queue->front->next = NULL;
    queue->rear = queue->front;
    queue->size = 0;
}

void disposeQueue(Queue queue)
{
    makeEmpty(queue);
    free(queue->front);
    free(queue);
}
void Enqueue(ElementType x, Queue queue)
{
    QueueNode tmp;
    tmp = malloc(sizeof(struct Node));
    tmp->element = x;
    tmp->next = NULL;
    queue->size++;
    queue->rear->next = tmp;    // 先将tmp连到队尾，
    queue->rear = tmp;          // 然后再移动队尾指针到新队尾
}

ElementType Front(Queue queue)
{
    if(isEmpty(queue))
    {
        printf("Empty queue\n");
        return 0;
    }
    else
    {
        return queue->front->next->element;
    }    
}

void Dequeue(Queue queue)
{
    if(isEmpty(queue))
    {
        printf("Empty queue\n");
        return;
    }
    else
    {
        QueueNode tmp;
        tmp = queue->front->next;
        if(tmp == queue->rear)
        {
            queue->rear = queue->front;
        }
        queue->front->next = tmp->next;
        free(tmp);
        queue->size--;
    }
}
ElementType frontAndDequeue(Queue queue)
{
    if(isEmpty(queue))
    {
        printf("Empty queue\n");
        return 0;
    }
    else
    {
        ElementType tmp = queue->front->next->element;
        Dequeue(queue);
        return tmp;
    }
}
