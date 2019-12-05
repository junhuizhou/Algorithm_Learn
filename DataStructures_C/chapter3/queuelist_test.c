/*
 * @Author: junhuizhou
 * @Date: 2019-12-05 15:48:50
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 17:08:07
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\queuelist_test.c
 */

#include <stdio.h>
#include "queuelist.h"

int main()
{
    Queue queue;
    int i;

    queue = createQueue();
    for(i=0; i<10; i++)
    {
        Enqueue(i, queue);
    }
    while(!isEmpty(queue))
    {
        printf("%d ", Front(queue));
        Dequeue(queue);
    }
    printf("\n");
    
    for(i=0; i<10; i++)
    {
        Enqueue(9-i, queue);
    }
    while(!isEmpty(queue))
    {
        printf("%d ", frontAndDequeue(queue));
    }
    printf("\n");
    
    disposeQueue(queue);
    return 0;
}
