/*
 * @Author: junhuizhou
 * @Date: 2020-01-19 20:36:05
 * @LastEditor: junhuizhou
 * @LastEditTime: 2020-02-24 20:14:20
 * @Description: header
 * @FilePath: \DataStructures_C\chapter9\graph.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void CreatAjaGraph(AjaGraph* graph)
{
    int i, j, k;
    char a;
    EdgeNode* edgenode;
    printf("intput the numbers of vertex and edge: ");
    scanf("%d %d", &graph->numvertexes, &graph->numedges);
    getchar();
    for(i=0; i<graph->numvertexes; i++)
    {
        printf("int vertex %d: ", i);
        scanf("%c", &graph->graphlist[i].element);
        getchar();
        printf("%c\n", a);
        graph->graphlist[i].firstedge = NULL;
    }
    for(k=0; k<graph->numedges; k++)
    {
        printf("intput index of vi and vj: ");
        scanf("%d %d", &i, &j);
        // vi->vj
        // edgenode类似栈，后来者在前面
        edgenode = malloc(sizeof(EdgeNode));
        edgenode->index = j;
        edgenode->next = graph->graphlist[i].firstedge;
        graph->graphlist[i].firstedge = edgenode;
    }
}
