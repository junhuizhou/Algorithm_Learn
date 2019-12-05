/*
 * @Author: junhuizhou
 * @Date: 2019-12-05 11:26:59
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 15:27:37
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\cursor_test.c
 */

#include <stdio.h>
#include "cursor.h"

int main()
{
    List list;
    Position p;
    int i;

    initializeCursorSpace();
    list = makeEmpty(0);
    p = Header(list);
    printList(list);

    for(i=0; i<10; i++)
    {
        Insert(i, list, p);
        p = Advance(p);
    }
    printList(list);

    for(i=0; i<10; i+=2)
    {
        Delete(i, list);
    }
    for(i=0; i<10; i++)
    {
        if((i&1 == 0) == (Find(i,list) != 0))
        {
            printf("Find failed\n");
        }
    }
    printf("Delete finished\n");
    printList(list);
    deleteList(list);
    return 0;
}
