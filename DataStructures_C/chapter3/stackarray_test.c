/*
 * @Author: junhuizhou
 * @Date: 2019-12-05 11:28:39
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 15:48:07
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\stackarray_test.c
 */

#include <stdio.h>
#include "stackarray.h"

int main()
{
    Stack stack;
    int i;

    stack = createStack(12);
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
