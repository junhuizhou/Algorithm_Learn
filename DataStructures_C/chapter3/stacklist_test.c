/*
 * @Author: junhuizhou
 * @Date: 2019-12-05 11:28:51
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 15:43:37
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\stacklist_test.c
 */

#include <stdio.h>
#include "stacklist.h"

int main()
{
    Stack stack;
    int i;

    stack = createStack();
    for(i=0; i<10; i++)
    {
        Push(i, stack);
    }
    while(!isEmpty(stack))
    {
        printf("%d ", Top(stack));
        Pop(stack);
    }
    disposeStack(stack);
    return 0;
}
