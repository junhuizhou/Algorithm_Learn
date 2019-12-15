/*
 * @Author: junhuizhou
 * @Date: 2019-12-02 21:52:58
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-15 21:37:27
 * @Description: header
 * @FilePath: \DataStructures_C\chapter4\binarysearchtree.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarysearchtree.h"

struct TreeNode
{
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree makeEmpty(SearchTree tree)
{
    if(tree != NULL)
    {
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

Position Find(ElementType x, SearchTree tree)
{
    if(tree == NULL)
    {
        return NULL;
    }
    if(x < tree->element)
    {
        return Find(x, tree->left);
    }
    else if(x > tree->element)
    {
        return Find(x, tree->right);
    }
    else
    {
        return tree;
    }
}

Position findMin(SearchTree tree)
{
    if(tree == NULL)
    {
        return NULL;
    }
    else if(tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return findMin(tree->left);
    }
}

Position findMax(SearchTree tree)
{
    /*采用递归方式*/
    // if(tree == NULL)
    // {
    //     return NULL;
    // }
    // else if(tree->right == NULL)
    // {
    //     return tree;
    // }
    // else
    // {
    //     return findMax(tree->right);
    // }

    /*采用非递归方式*/
    if(tree != NULL)
    {
        while(tree->right != NULL)
        {
            tree = tree->right;
        }
    }
    return tree;
}

SearchTree Insert(ElementType x, SearchTree tree)
{
    if(tree == NULL)
    {
        tree = malloc(sizeof(struct TreeNode));
        if(tree == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
        else
        {
            tree->element = x;
            tree->left = tree->right = NULL;
        }
    }
    else if(x < tree->element)
    {
        tree->left = Insert(x, tree->left);
    }
    else if(x > tree->element)
    {
        tree->right = Insert(x, tree->right);
    }
    
    return tree;
}

SearchTree Delete(ElementType x, SearchTree tree)
{
    Position tmpcell;
    if(tree == NULL)
    {
        printf("Element not found\n");
    }
    else if(x < tree->element)
    {
        tree->left = Delete(x, tree->left);
    }
    else if(x > tree->element)
    {
        tree->right = Delete(x, tree->right);
    }
    else
    {
        if(tree->left && tree->right)   /* two children */
        {
            tmpcell = findMin(tree->right);
            tree->element = tmpcell->element;
            tree->right = Delete(tree->element, tree->right);
        }
        else                            /* one or zero children */
        {
            tmpcell = tree;
            if(tree->left == NULL)
            {
                tree = tree->right;
            }
            else if(tree->right == NULL)
            {
                tree = tree->left;
            }
            free(tmpcell);
        }
    }
    
    return tree;
}

ElementType Retrieve(Position position)
{
    return position->element;
}

void printTree(SearchTree tree)
{
    if(tree != NULL)
    {
        printTree(tree->left);
        printf("%d ", tree->element);
        printTree(tree->right);
    }
}

/* **********Exercise 4.28********** */
/* **********func start********** */
int countNodes(SearchTree tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        return 1+countNodes(tree->left)+countNodes(tree->right);
    }
}

int countLeaves(SearchTree tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else if(tree->left==NULL && tree->right== NULL)
    {
        return 1;
    }
    else
    {
        return countLeaves(tree->left)+countLeaves(tree->right);
    }
}

int countFull(SearchTree tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        return (tree->left!=NULL && tree->right!=NULL)+ \
                countFull(tree->left)+countFull(tree->right);
    }

    /*alternative method*/
    /*规律：满节点个数+1 = 非空二叉树树叶个数*/
    // if(tree == NULL)
    // {
    //     return 0;
    // }
    // else
    // {
    //     return countLeaves(tree)-1;
    // }
    
}
/* *********func end********** */

/* **********Exercise 4.29********** */
/* **********func start********** */
static int randInt(int min, int max)
{
    srand((int)time(0));
    return rand()%(max-min+1) + min;
}

static SearchTree makeRandomTree1(int low, int up)
{
    SearchTree tree;
    tree = NULL;
    int randomvalue;

    if(low <= up)
    {
        tree = malloc(sizeof(struct TreeNode));
        if(tree == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
        else
        {
            tree->element = randomvalue = randInt(low,up);
            tree->left = makeRandomTree1(low, randomvalue-1);
            tree->right = makeRandomTree1(randomvalue+1,up);
        }
    }
}

/**
 * @description: 生成num个节点的随机二叉查找树
 * @param {type} 
 * @return: 
 */
SearchTree makeRandomTree(int num)
{
    return makeRandomTree1(1, num);
}
/* **********func end********** */

/* **********Exercise 4.31********** */
/* **********func start********** */
static SearchTree genTree(int height, int* lastnode)
{
    SearchTree tree = NULL;
    if(height >= 0)
    {
        tree = malloc(sizeof(struct TreeNode));
        if(tree == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
        tree->left = genTree(height-1, lastnode);
        tree->element = ++*lastnode;
        tree->right = genTree(height-1, lastnode);
        return tree;
    }
    else
    {
        return NULL;
    }
}

/**
 * @description: 生成key为1到2^(H+1)-1的高H的理想平衡二叉查找树
 * @param {type} 
 * @return: 
 */
SearchTree perfectTree(int height)
{
    int lastnodeassigned = 0;
    return genTree(height, &lastnodeassigned);
}
/* **********func end********** */

/* **********Exercise 4.32********** */
/* **********func start********** */
/**
 * @description: 打印(lower,upper)之间的key值，又称搜索区间
 * @param {type} 
 * @return: 
 */
void printRange(ElementType lower, ElementType upper, SearchTree tree)
{
    if(tree!= NULL)
    {
        /*移动到最接近lower的key1*/
        if(lower < tree->element)
        {
            printRange(lower, upper, tree->left);
        }
        /*移动到key1后开始打印，移动到key2停止打印*/
        if(lower<=tree->element && tree->element<=upper)
        {
            printf("%d ", tree->element);
        }
        /*由key1开始移动到最接近upper的key2*/
        if(tree->element < upper)
        {
            printRange(lower, upper, tree->right);
        }
        /*递归最后退回到根部，根部执行到这里，并最终走向终结*/
    }
}
/* **********func end********** */

// TODO: 以层序打出二叉树节点
/* **********Exercise 4.35********** */
/* **********func start********** */
/**
 * @description: 以层序打出二叉树节点，eg:先打印深度为1的节点，再打印深度2的节点
 * @method: 将根放在空队列，不断从队列中弹出节点并把该节点的左右儿子压入队列，直到队列空
 * @param {type} 
 * @return: 
 */
void printLevelOrder(SearchTree tree)
{

}
/* **********func end********** */
