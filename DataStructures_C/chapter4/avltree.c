/*
 * @Author: junhuizhou
 * @Date: 2019-12-04 15:36:48
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-04 20:01:17
 * @Description: header
 * @FilePath: \DataStructures_C\chapter4\avltree.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

/*AvlTree和binarysearchtree差不多，改变的是Insert和Delete*/

struct AvlNode
{
    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
};

AvlTree makeEmpty(AvlTree tree)
{
    if(tree != NULL)
    {
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

Position Find(ElementType x, AvlTree tree)
{
    if(tree == NULL)
    {
        return NULL;
    }
    else if(x < tree->element)
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

Position findMin(AvlTree tree)
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

Position findMax(AvlTree tree)
{
    if(tree != NULL)
    {
        while(tree->right != NULL)
        {
            tree = tree->right;
        }
    }
    return tree;
}


/* ********************内部static函数******************* */
/* ***********static start********* */

static int Height(Position p)
{
    if(p == NULL)
    {
        return -1;
    }
    else
    {
        return p->height;
    }
}

static int Max(int leftheight, int rightheight)
{
    return leftheight>rightheight ? leftheight:rightheight;
}

/**
 * @description: 由插入左外点引起不平衡的单旋转
 * @param Position 不平衡节点alpha
 * @return: Position 替代alpha的新节点，为原儿子
 */
static Position singleRotateWithLeft(Position k2)
{
    Position k1;
    /*单旋转，k1替代k2*/
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    /*更新height*/
    k2->height = Max(Height(k2->left),Height(k2->right));
    k1->height = Max(Height(k1->left),k2->height);
    return k1;
}

/**
 * @description: 由插入右外点引起不平衡的单旋转
 * @param Position 不平衡节点alpha 
 * @return: Position 替代alpha的新节点，为原儿子
 */
static Position singleRotateWithRight(Position k1)
{
    Position k2;
    /*单旋转，k2代替k1*/
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    /*更新height*/
    k1->height = Max(Height(k1->left),Height(k1->right));
    k2->height = Max(Height(k2->right),k1->height);
    return k2;
}

/**
 * @description: 由插入左内点引起不平衡的双旋转
 * @param Position 不平衡节点alpha 
 * @return: Position 替代alpha的新节点，为原孙子
 */
static Position doubleRotateWithLeft(Position k3)
{
    /*单旋转k1和k2，k1为儿子，k2为孙子*/
    k3->left = singleRotateWithRight(k3->left);
    /*单旋转k3和k2*/
    return singleRotateWithLeft(k3);
}

/**
 * @description: 由插入右内点引起不平衡的双旋转
 * @param Position 不平衡节点alpha 
 * @return: Position 替代alpha的新节点，为原孙子
 */
static Position doubleRotateWithRight(Position k1)
{
    /*单旋转k2和k3，k2为孙子，k3为儿子*/
    k1->right = singleRotateWithLeft(k1->right);
    /*单旋转k1和k2*/
    return singleRotateWithRight(k1);
}

/* **********static end********** */


AvlTree Insert(ElementType x, AvlTree tree)
{
    if(tree == NULL)
    {
        tree = malloc(sizeof(struct AvlNode));
        if(tree == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
        else
        {
            tree->element = x;
            tree->height = 0;
            tree->left = tree->right = NULL;
        }
    }
    else if(x < tree->element)
    {
        tree->left = Insert(x, tree->left);
        /*检查一下是否高度失衡*/
        if(Height(tree->left)-Height(tree->right) == 2)
        {
            /*判断失衡的插入类型*/
            if(x < tree->left->element)
            {
                tree = singleRotateWithLeft(tree);
            }
            else
            {
                tree = doubleRotateWithLeft(tree);
            }
        }
    }
    else if(x > tree->element)
    {
        tree->right = Insert(x, tree->right);
        /*检查一下是否高度失衡*/
        if(Height(tree->right)-Height(tree->left) == 2)
        {
            /*判断失衡的插入类型*/
            if(x < tree->right->element)
            {
                tree = singleRotateWithRight(tree);
            }
            else
            {
                tree = doubleRotateWithRight(tree);
            }
        }
    }
    else
    {
        printf("do not insert the value that exit\n");
    }

    tree->height = Max(Height(tree->left),Height(tree->right));
    return tree;
}

AvlTree Delete(ElementType x, AvlTree tree) //还没写平衡
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
