/*
 * @Author: junhuizhou
 * @Date: 2020-03-27 21:22:30
 * @LastEditor: junhuizhou
 * @LastEditTime: 2020-03-27 23:03:02
 * @Description: header
 * @FilePath: \DataStructures_C\chapter12\redblacktree.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "redblacktree.h"

#define NEG_INFINITY (-10000)
#define INFINITY (10000)

typedef enum ColorType
{
    Red, Black
}ColorType;

struct RedBlackNode
{
    ElementType element;
    RedBlackTree left;
    RedBlackTree right;
    ColorType color;
};

static Position NullNode = NULL;    // Needs initialization
static Position X, P, GP, GGP;

RedBlackTree Initialize(void)
{
    RedBlackTree tree;
    
    if(NullNode == NULL)
    {
        NullNode = malloc(sizeof(struct RedBlackNode));
        if(NullNode == NULL)
        {
            printf("Out of space\n");
            exit(1);
        }
        NullNode->left = NullNode->right = NullNode;
        NullNode->color = Black;
        NullNode->element = INFINITY;
    }

    // create the header node
    tree = malloc(sizeof(struct RedBlackNode));
    if(tree == NULL)
    {
        printf("Out of space\n");
        exit(1);
    }
    tree->left = tree->right = NullNode;
    tree->color = Black;
    tree->element = NEG_INFINITY;

    return tree;
}

static RedBlackTree MakeEmptyRec(RedBlackTree tree)
{
    if(tree != NullNode)
    {
        MakeEmptyRec(tree->left);
        MakeEmptyRec(tree->right);
        free(tree);
    }
    return NullNode;
}

RedBlackTree MakeEmpty(RedBlackTree tree)
{
    tree->right = MakeEmptyRec(tree->right);
    return  tree;
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

static Position Rotate(ElementType x, Position parent)
{
    if(x < parent->element)
    {
        return parent->left = x < parent->left->element ? \
            SingleRotateWithLeft(parent->left) : \
            SingleRotateWithRight(parent->left);
    }
    else
    {
        return parent->right = x < parent->right->element ? \
            SingleRotateWithLeft(parent->right) : \
            SingleRotateWithRight(parent->right);
    }
}

static void HandleReorient(ElementType item, RedBlackTree tree)
{
    X->color = Red;     //do the color flip
    X->left->color = Black;
    X->right->color = Black;

    if(P->color == Red)     //have to rotate
    {
        GP->color = Red;
        if((item < GP->element) != (item < P->element))
        {
            P = Rotate(item, GP);   //start double rotation
        }
        X = Rotate(item, GGP);
        X->color = Black;
    }
    tree->right->color = Black;     //make root black
}

RedBlackTree Insert(ElementType item, RedBlackTree tree)
{
    X = P = GP = tree;
    NullNode->element = item;
    while(X->element != item)   //descend down the tree
    {
        GGP = GP;
        GP = P;
        P = X;
        if(item < X->element)
        {
            X = X->left;
        }
        else
        {
            X = X->right;
        }
        if(X->left->color==Red && X->right->color==Red)
        {
            HandleReorient(item, tree);
        }
    }

    if(X != NullNode)
    {
        return NullNode;    //duplicate
    }

    X = malloc(sizeof(struct RedBlackNode));
    if(X == NULL)
    {
        printf("Out of space\n");
        exit(1);
    }
    X->element = item;
    X->left = X->right = NullNode;

    if(item < P->element)   //attach to its parent
    {
        P->left = X;
    }
    else
    {
        P->right = X;
    }
    HandleReorient(item, tree);     //color red; maybe rotate

    return tree;
}

// TODO: implement of function Remove
RedBlackTree Remove(ElementType x, RedBlackTree tree)
{
    return tree;
}

Position Find(ElementType x, RedBlackTree tree)
{
    if(tree == NullNode)
    {
        return NullNode;
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

Position FindMin(RedBlackTree tree)
{
    tree = tree->right;
    while(tree->left != NullNode)
    {
        tree = tree->left;
    }
    return tree;
}

Position FindMax(RedBlackTree tree)
{
    while(tree->right != NullNode)
    {
        tree = tree->right;
    }
    return tree;
}

ElementType Retrieve(Position position)
{
    return position->element;
}

static void DoPrint(RedBlackTree tree)
{
    if(tree != NullNode)
    {
        DoPrint(tree->left);
        printf("%d\n", tree->element);
        DoPrint(tree->right);
    }
}

void PrintTree(RedBlackTree tree)
{
    DoPrint(tree->right);
}
