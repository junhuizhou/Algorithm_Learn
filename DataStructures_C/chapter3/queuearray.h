/*
 * @Author: junhuizhou
 * @Date: 2019-11-26 20:12:07
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-26 20:57:55
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\queuearray.h
 */

#ifndef DS_CHAP3_QUEUEARRAY_H_
#define DS_CHAP3_QUEUEARRAY_H_

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int isEmpty(Queue queue);
int isFull(Queue queue);
Queue createQueue(int maxelements);
void makeEmpty(Queue queue);
void disposeQueue(Queue queue);
void Enqueue(ElementType x, Queue queue);
ElementType Front(Queue queue);
void Dequeue(Queue queue);
ElementType frontAndDequeue(Queue queue);

#endif
