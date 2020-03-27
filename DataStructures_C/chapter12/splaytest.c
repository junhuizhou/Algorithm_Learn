/*
 * @Author: junhuizhou
 * @Date: 2020-03-27 12:12:40
 * @LastEditor: junhuizhou
 * @LastEditTime: 2020-03-27 13:35:49
 * @Description: header
 * @FilePath: \DataStructures_C\chapter12\splaytest.c
 */

#include <stdio.h>
#include "time.h"
#include "splay.h"

int RandInt(int min, int max)
{
    srand((int)time(0));
    return rand()%(max-min+1) + min;
}

void Swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    #define num (50)
    int A[num];
    int i;
    // 先生成num个不同的数
    for(i=0; i<num; i++)
    {
        A[i] = i;
    }
    // 再将所有数打乱
    for(i=1; i<num; i++)
    {
        Swap(&A[i], &A[RandInt(0, i)]);
    }

    SplayTree tree;
    int j = 0;
    tree = Initialize();
    tree = MakeEmpty(tree);
    for(i=0; i<num; i++)
    {
        tree = Insert(A[i], tree);
    }
    PrintTree(tree);
    printf("\n");

    for(i=0; i<num; i++)
    {
        tree = Find(i, tree);
        if(Retrieve(tree) != i)
        {
            printf("Error1 at %d\n", i);
        }
    }
    printf("Entering remove\n");

    for(i=0; i<num; i+=2)
    {
        tree = Remove(i, tree);
    }
    PrintTree(tree);
    printf("\n");
    
    for(i=1; i<num; i+=2)
    {
        tree = Find(i, tree);
        if(Retrieve(tree) != i)
        {
            printf("Error2 at %d\n", i);
        }
    }
    for(i=0; i<num; i+=2)
    {
        tree = Find(i, tree);
        if(Retrieve(tree) == i)
        {
            printf("Erroe3 at %d\n", i);
        }
    }

    printf("Min is %d\n", Retrieve(tree = FindMin(tree)));
    printf("Max is %d\n", Retrieve(tree = FindMax(tree)));

    tree = MakeEmpty(tree);
    return 0;
}
