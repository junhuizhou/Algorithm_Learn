/*
 * @Author: junhuizhou
 * @Date: 2019-11-26 21:18:38
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 17:04:12
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\queuelist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

/*queue是没有list那种表头的，有元素时front由NULL跳到第一个元素*/

struct Node
{
    ElementType element;
    QueueNode next;
};

struct QueueRecord
{
    QueueNode front;
    QueueNode rear;
};

int isEmpty(Queue queue)
{
    return queue->front == NULL;
}

Queue createQueue()
{
    Queue queue;
    queue = malloc(sizeof(struct QueueRecord));
    if(queue == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
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
        p = queue->front;
        while(!isEmpty(queue))
        {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    queue->front = queue->rear = NULL;
}

void disposeQueue(Queue queue)
{
    if(queue != NULL)
    {
        makeEmpty(queue);
        free(queue);
    }
}

void Enqueue(ElementType x, Queue queue)
{
    QueueNode tmp;
    tmp = malloc(sizeof(struct Node));
    if(tmp == NULL)
    {
        printf("Out of memory\n");
    }
    tmp->element = x;
    tmp->next = NULL;
    if(queue->front == NULL)
    {
        queue->front = tmp;
    }
    if(queue->rear == NULL)
    {
        queue->rear = tmp;
    }
    else
    {
        queue->rear->next = tmp;    // 先将tmp连到队尾，
        queue->rear = tmp;          // 然后再移动队尾指针到新队尾
    }
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
        return queue->front->element;
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
        tmp = queue->front;
        if(tmp == queue->rear)
        {
            queue->front = queue->rear = NULL;
        }
        else
        {
            queue->front = tmp->next;
        }
        free(tmp);
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
        ElementType tmp = queue->front->element;
        Dequeue(queue);
        return tmp;
    }
}
