/*
 * @Author: junhuizhou
 * @Date: 2019-12-03 15:37:30
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-03 16:09:17
 * @Description: header
 * @FilePath: \DataStructures_C\chapter4\bstree_test.c
 */

#include <stdio.h>
#include "binarysearchtree.h"

int main()
{
    SearchTree tree;
    Position p;
    int i;
    int j = 0;

    tree = makeEmpty( NULL );
    for( i=0; i<50; i++, j=(j+7)%50 )
        tree = Insert(j, tree);

    for( i=0; i<50; i++ )
        if( (p=Find(i,tree)) == NULL || Retrieve(p) != i )
            printf( "Error at %d\n", i );

    for( i=0; i<50; i+=2 )
        tree = Delete(i, tree);

    for( i=1; i<50; i+=2 )
        if( (p=Find(i,tree)) == NULL || Retrieve(p) != i )
            printf( "Error at %d\n", i );

    for( i=0; i<50; i+=2 )
        if( (p=Find(i,tree)) != NULL )
            printf( "Error at %d\n", i );

    printf("Min is %d, Max is %d\n", Retrieve(findMin(tree)),
               Retrieve(findMax(tree)) );

    return 0;
}
