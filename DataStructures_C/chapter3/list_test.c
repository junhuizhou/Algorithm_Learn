/*
 * @Author: junhuizhou
 * @Date: 2019-12-05 11:27:13
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-05 14:45:58
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\list_test.c
 */

#include <stdio.h>
#include "list.h"

int main()
{
    List list;
    Position p;
    int i;

    list = makeEmpty(NULL);
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
        if((i&1 == 0) == (Find(i,list)!=NULL))
        {
            printf("Find fails\n");
        }
    }
    printf("Finished deletions\n");
    printList(list);
    deleteList(list);
    return 0;
}
