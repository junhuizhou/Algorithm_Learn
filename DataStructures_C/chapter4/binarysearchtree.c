/*
 * @Author: junhuizhou
 * @Date: 2019-12-02 21:52:58
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-03 15:36:23
 * @Description: header
 * @FilePath: \DataStructures_C\chapter4\binarysearchtree.c
 */

#include <stdio.h>
#include <stdlib.h>
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
