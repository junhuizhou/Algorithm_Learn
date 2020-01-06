/*
 * @Author: junhuizhou
 * @Date: 2020-01-06 17:22:03
 * @LastEditor: junhuizhou
 * @LastEditTime : 2020-01-06 20:19:57
 * @Description: header
 * @FilePath: \DataStructures_C\chapter8\disjset.c
 */

#include "disjset.h"

void Initialize(DisjSet ds)
{
    int i;
    for(i=NUMSETS; i>0; i--)
    {
        ds[i] = 0;
    }
}

void setUnion(DisjSet ds, SetType root1, SetType root2)
{
    if(ds[root1] > ds[root2])
    {
        ds[root1] = root2;
    }
    else
    {
        if(ds[root1] == ds[root2])
        {
            ds[root1]--;
        }
        ds[root2] = root1;
    }
}

SetType Find(ElementType x, DisjSet ds)
{
    if(ds[x] <= 0)
    {
        return x;
    }
    else
    {
        return ds[x] = Find(ds[x], ds);
    }
}
