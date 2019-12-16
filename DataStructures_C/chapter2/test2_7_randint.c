/*
 * @Author: junhuizhou
 * @Date: 2019-11-21 20:00:56
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-16 16:08:59
 * @Description: header
 * @FilePath: \DataStructures_C\chapter2\test2_7_randint.c
 */

/*test2_7 生成前N个自然数的一个随机置换*/

#include <stdio.h>
#include <time.h>

int randInt(int min, int max)
{
    srand((int)time(0));
    return rand()%(max-min+1) + min;
}

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    #define num (100000)
    int A[num];
    int i;
    clock_t begin,end;
    begin = clock();
    // 先生成num个不同的数
    for(i=0; i<num; i++)
    {
        A[i] = i+1;
    }
    // 再将所有数打乱
    for(i=1; i<num; i++)
    {
        swap(&A[i], &A[randInt(0, i)]);
    }    
    end = clock();
    printf("time of this code is %lf ms\n",(double)(end-begin)/CLOCKS_PER_SEC*1000);
    return 0;
}
