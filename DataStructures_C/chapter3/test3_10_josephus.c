/*
 * @Author: junhuizhou
 * @Date: 2019-11-28 18:50:37
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-12-15 21:16:57
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_10_josephus.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node* LoopList;
typedef struct Node* Position;
struct Node
{
    int element;
    Position next;
};

LoopList creatLoopList()
{
    LoopList looplist;
    looplist = malloc(sizeof(struct Node));
    if(looplist == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    // 用0标记表头
    looplist->element = 0;
    looplist->next = looplist;
    return looplist;
}

LoopList insertLoop(LoopList looplist, int n)
{
    if(looplist == NULL)
    {
        printf("Creat looplist first\n");
        exit(1);
    }
    int x = 1;
    Position rear;
    rear = looplist;
    while(n)
    {
        Position tmp = malloc(sizeof(struct Node));
        if(tmp == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
        rear->next = tmp;
        tmp->element = x;
        tmp->next = looplist;
        rear = tmp;
        x++;
        n--;
    }
    return looplist;
}

void printLoopList(LoopList looplist)
{
    Position p;
    p = looplist->next;
    while(p->element != 0)
    {
        printf("%d ", p->element);
        p = p->next;
    }
    printf("\n");
}

void deleteLoopList(LoopList looplist)
{
    Position p, tmp;
    p = looplist->next;
    looplist->next = NULL;
    while(p->element != 0)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(p);
}

Position findPrevious(LoopList looplist, int x)
{
    Position p;
    p = looplist;
    while(p->next->element !=0 && p->next->element != x)
    {
        p = p->next;
    }
    return p;
}

void deleteElement(LoopList looplist, int element)
{
    Position p, tmp;
    p = findPrevious(looplist, element);
    tmp = p->next;
    p->next = tmp->next;
    free(tmp);
}

void josephus(LoopList looplist, int n, int m)
{
    int i;
    Position potato, tmp;
    potato = looplist->next;
    while(n--)
    {
        i = m;
        while(--i)
        {
            if(potato->element == 0)
            {
                potato = potato->next;
            }
            potato = potato->next;
            if(potato->element == 0)
            {
                potato = potato->next;
            } 
        }
        printf("potato is %d\n", potato->element);
        tmp = potato->next;
        deleteElement(looplist, potato->element);
        potato = tmp;
    }
}

int main()
{
    int m,n;
    scanf("%d %d", &n, &m);
    printf("People are %d, skippotato is %d\n", n, m);
    LoopList looplist;
    looplist = creatLoopList();
    looplist = insertLoop(looplist, n);
    josephus(looplist, n, m);
    deleteLoopList(looplist);
    return 0;
}
