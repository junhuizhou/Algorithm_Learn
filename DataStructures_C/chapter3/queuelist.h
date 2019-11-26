/*
 * @Author: junhuizhou
 * @Date: 2019-11-26 21:18:46
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-26 21:39:00
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\queuelist.h
 */

#ifndef DS_CHAP3_QUEUELIST_H_
#define DS_CHAP3_QUEUELIST_H_

struct Node;
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef struct Node *QueueNode;
typedef int ElementType;

int isEmpty(Queue queue);
Queue createQueue(int maxelements);
void makeEmpty(Queue queue);
void disposeQueue(Queue queue);
void Enqueue(ElementType x, Queue queue);
ElementType Front(Queue queue);
void Dequeue(Queue queue);
ElementType frontAndDequeue(Queue queue);

#endif
