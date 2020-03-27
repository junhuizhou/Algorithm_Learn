/*
 * @Author: junhuizhou
 * @Date: 2020-03-27 10:39:23
 * @LastEditor: junhuizhou
 * @LastEditTime: 2020-03-27 13:34:26
 * @Description: header
 * @FilePath: \DataStructures_C\chapter12\splay.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "splay.h"

#define INFINITY (30000)
#define NEG_INFINITY (-30000)

struct SplayNode
{
    ElementType element;
    SplayTree left;
    SplayTree right;
};

static Position NullNode = NULL;    // needs initialization

SplayTree Initialize(void)
{
    if(NullNode == NULL)
    {
        NullNode = malloc(sizeof(struct SplayNode));
        if(NullNode == NULL)
        {
            printf("Out of space\n");
            exit(1);
        }
        NullNode->left = NullNode->right = NullNode;
    }
}

SplayTree MakeEmpty(SplayTree tree)
{
    if(tree != NullNode)
    {
        MakeEmpty(tree->left);
        MakeEmpty(tree->right);
        free(tree);
    }
    return NullNode;
}

static Position SingleRotateWithLeft(Position k2)
{
    Position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
}

static Position SingleRotateWithRight(Position k1)
{
    Position k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    return k2;
}

static SplayTree Splay(ElementType x, Position position)
{
    static struct SplayNode Header;
    Position lefttreemax, righttreemin;

    Header.left = Header.right = NullNode;
    lefttreemax = righttreemin = &Header;
    NullNode->element = x;

    while(x != position->element)
    {
        if(x < position->element)
        {
            if(x < position->left->element)
            {
                position = SingleRotateWithLeft(position);
            }
            if(position->left == NullNode)
            {
                break;
            }
            // link right
            righttreemin->left = position;
            righttreemin = position;
            position = position->left;
        }
        else
        {
            if(x > position->right->element)
            {
                position = SingleRotateWithRight(position);
            }
            if(position->right == NullNode)
            {
                break;
            }
            // link left
            lefttreemax->right = position;
            lefttreemax = position;
            position = position->right;
        }
    }

    // reassemble
    lefttreemax->right = position->left;
    righttreemin->left = position->right;
    position->left = Header.right;
    position->right = Header.left;

    return position;
}

SplayTree Insert(ElementType x, SplayTree tree)
{
    static Position newnode = NULL;
    if(newnode == NULL)
    {
        newnode = malloc(sizeof(struct SplayNode));
        if(newnode == NULL)
        {
            printf("Out of space\n");
            exit(1);
        }
    }
    newnode->element = x;

    if(tree == NullNode)
    {
        newnode->left = newnode->right = NullNode;
        tree = newnode;
    }
    else
    {
        tree = Splay(x, tree);
        if(x < tree->element)
        {
            newnode->left = tree->left;
            newnode->right = tree;
            tree->left = NullNode;
            tree = newnode;
        }
        else if(x > tree->element)
        {
            newnode->right = tree->right;
            newnode->left = tree;
            tree->right = NullNode;
            tree = newnode;
        }
        else
        {
            return tree;
        }
    }

    newnode = NULL;
    return tree;
}

SplayTree Remove(ElementType x, SplayTree tree)
{
    Position newtree;

    if(tree != NullNode)
    {
        tree = Splay(x, tree);
        if(x == tree->element)
        {
            if(tree->left == NullNode)
            {
                newtree = tree->right;
            }
            else
            {
                newtree = tree->left;
                newtree = Splay(x, newtree);
                newtree->right = tree->right;
            }
            free(tree);
            tree = newtree;
        }
    }

    return tree;
}

SplayTree Find(ElementType x, SplayTree tree)
{
    return Splay(x, tree);
}

SplayTree FindMin(SplayTree tree)
{
    return Splay(NEG_INFINITY, tree);
}

SplayTree FindMax(SplayTree tree)
{
    return Splay(INFINITY, tree);
}

ElementType Retrieve(SplayTree tree)
{
    return tree->element;
}

void PrintTree(SplayTree tree)
{
    if(tree != NullNode)
    {
        PrintTree(tree->left);
        printf("%d ", tree->element);
        PrintTree(tree->right);
    }
}
