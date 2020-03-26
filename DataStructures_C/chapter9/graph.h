/*
 * @Author: junhuizhou
 * @Date: 2020-01-19 20:35:56
 * @LastEditor: junhuizhou
 * @LastEditTime: 2020-02-24 20:14:38
 * @Description: header
 * @FilePath: \DataStructures_C\chapter9\graph.h
 */

#ifndef DS_CHAP9_GRAPH_H_
#define DS_CHAP9_GRAPH_H_

#define MAXVEX (100)

typedef char VertexType;
typedef int EdgeType;

// 有向邻接表图
typedef struct EdgeNode
{
    int index;
    EdgeType weight;
    struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode
{
    VertexType element;
    struct EdgeNode* firstedge;
}GraphList[MAXVEX];

typedef struct AjaGraph
{
    GraphList graphlist;
    int numvertexes;
    int numedges;
}AjaGraph;

void CreatAjaGraph(AjaGraph* graph);
void PrintDeepthAjaGraph(AjaGraph graph, int i);

#endif
