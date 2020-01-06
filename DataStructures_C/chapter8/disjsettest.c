/*
 * @Author: junhuizhou
 * @Date: 2020-01-06 17:32:27
 * @LastEditor: junhuizhou
 * @LastEditTime : 2020-01-06 20:06:26
 * @Description: header
 * @FilePath: \DataStructures_C\chapter8\disjsettest.c
 */
#include <stdio.h>
#include "disjset.h"

int main()
{
    DisjSet ds;
    SetType set1, set2;
    int i, j, k;

    Initialize(ds);
    j = k = 1;
    while(k <= 8)
    {
        j = 1;
        while(j < NUMSETS)
        {
            set1 = Find(j, ds);
            set2 = Find(j + k, ds);
            setUnion(ds, set1, set2);
            j += 2*k;
        }
        k *= 2;
    }
    i = 1;
    for(i=1; i<=NUMSETS; i++)
    {
        set1 = Find(i, ds);
        printf("%d**", set1);
    }
    printf("\n");
    return 0;
}
