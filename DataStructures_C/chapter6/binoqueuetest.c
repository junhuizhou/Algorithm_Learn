/*
 * @Author: junhuizhou
 * @Date: 2019-12-18 17:45:45
 * @LastEditor: junhuizhou
 * @LastEditTime : 2019-12-18 17:47:42
 * @Description: header
 * @FilePath: \DataStructures_C\chapter6\binoqueuetest.c
 */

#include <stdio.h>
#include "binomialqueue.h"

#define MaxSize (12000)

int main( )
{
    BinQueue H;
    int i, j;
    ElementType AnItem;

    H = Initialize( );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
    {
      // printf( "Inserting %d\n", j );
      H = Insert( j, H );
    }

    j = 0;
    while( !isEmpty( H ) )
    {
      if( deleteMin( H ) != j++ )
      {
         printf( "Error in DeleteMin, %d\n", j );
      }       
    }
    if( j != MaxSize )
    {
      printf( "Error in counting\n" );
    }
    printf( "Done...\n" );
    return 0;
}
