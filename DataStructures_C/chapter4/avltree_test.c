/*
 * @Author: junhuizhou
 * @Date: 2019-12-04 15:37:14
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-08 19:44:03
 * @Description: header
 * @FilePath: \DataStructures_C\chapter4\avltree_test.c
 */

#include <stdio.h>
#include "avltree.h"

int main()
{
    AvlTree tree;
    Position p;
    int i;
    int j = 0;

    tree = makeEmpty(NULL);
    for(i=0; i<50; i++,j=(j+7)%50)
    {
        tree = Insert(j, tree);
    }
    for(i=0; i<50; i++)
    {
        if((p=Find(i,tree))==NULL || Retrieve(p)!=i)
        {
            printf("Error at %d\n", i);
        }
    }

    for( i=0; i<50; i+=2 )
        tree = Delete(i, tree);

    for( i=1; i<50; i+=2 )
        if( (p=Find(i,tree)) == NULL || Retrieve(p) != i )
            printf( "Error at %d\n", i );

    for( i=0; i<50; i+=2 )
        if( (p=Find(i,tree)) != NULL )
            printf( "Error at %d\n", i );

    printf("Min is %d, Max is %d\n", Retrieve(findMin(tree)),
                                    Retrieve(findMax(tree)));
                                    
    printTree(tree);
    printf("\n");
    
    if(makeEmpty(tree) == NULL)
    {
        printf("Finish destory\n");
    }
    
    return 0;
}
