/*
 * @Author: junhuizhou
 * @Date: 2019-12-13 17:18:47
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-13 18:49:25
 * @Description: header
 * @FilePath: \DataStructures_C\chapter5\hashtest.c
 */

/* Define the appropriate hash algorithm */
#define SepChain    

#ifdef SepChain
#include "hashsep.h"
#endif
#ifdef QuadProb
#include "hashquad.h"
#endif

#include <stdio.h>

int main()
{
    #define NUM_ITEMS (400)
    HashTable hashtable;
    Position pos;
    int i;
    int j = 0;
    int currentsize = 13;

    hashtable = initializeTable(currentsize);
    for(i=0; i<NUM_ITEMS; i++,j+=71)
    {
        #ifdef QuadProb
            if(i > currentsize/2)
            {
                hashtable = ReHash(hashtable);
                printf("Rehashing...\n");
                currentsize *= 2;
            }
        #endif
        Insert(j ,hashtable);
    }

    for(i=0,j=0; i<NUM_ITEMS; i++,j+=71)
    {
        #ifdef SepChain
            if((pos=Find(j,hashtable))==NULL || Retrieve(pos)!=j)
        #endif
        #ifdef QuadProb
            if(Retrieve((pos=Find(j,hashtable)),hashtable) != j)
        #endif
            {
                printf("Error at %d\n", j);
            }
    }
    printf("End of program\n");
    return 0;
}
