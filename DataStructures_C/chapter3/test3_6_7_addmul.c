/*
 * @Author: junhuizhou
 * @Date: 2019-11-27 19:46:36
 * @LastEditor: junhuizhou
 * @LastEditTime: 2019-11-28 17:16:23
 * @Description: header
 * @FilePath: \DataStructures_C\chapter3\test3_6&7._addmul.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node* Position;
typedef struct Node* Polynomial;
struct Node
{
    int coef;
    int expon;
    Position next;
};

void Insert(int c, int e, Position *rear)
{
    Position tmp = malloc(sizeof(struct Node));
    if(tmp == NULL)
    {
        printf("Out of memory\n");
    }
    tmp->coef = c;
    tmp->expon = e;
    tmp->next = NULL;
    (*rear)->next = tmp;
    *rear = tmp;
}

Polynomial readPoly()
{
    Polynomial p;
    Position rear;
    int n;
    int c,e;
    p = malloc(sizeof(struct Node));
    p->next = NULL;
    rear = p;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d", &c, &e);
        Insert(c, e, &rear);
    }
    return p;
}

void printPoly(Polynomial p)
{
    if(p == NULL)
    {
        printf("0 0\n");
        return;
    }
    p = p->next;
    while(p)
    {
        printf("%dX^%d ", p->coef, p->expon);
        p = p->next;
    }
    printf("\n");
}

void deleteList(Polynomial list)
{
    if(list == NULL)
    {
        printf("Use creatList first\n");
    }
    Position p, tmp;
    p = list->next;
    list->next = NULL;
    while(p != NULL)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

Polynomial addPoly(Polynomial p1, Polynomial p2)
{
    Position tmp1,tmp2,rear,tmp;
    tmp1 = p1->next;
    tmp2 = p2->next;
    Polynomial p = malloc(sizeof(struct Node));
    if(p == NULL)
    {
        printf("Out of momory\n");
        exit(0);
    }
    p->next = NULL;
    rear = p;
    while(tmp1 && tmp2)
    {
        if(tmp1->expon == tmp2->expon)
        {
            if(tmp1->coef + tmp2->coef)
            {
                Insert(tmp1->coef+tmp2->coef, tmp1->expon, &rear);
        
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        else if(tmp1->expon > tmp2->expon)
        {
            Insert(tmp1->coef, tmp1->expon, &rear);
            tmp1 = tmp1->next;
        }
        else
        {
            Insert(tmp2->coef, tmp2->expon, &rear);
            tmp2 = tmp2->next;
        }
    }
    while(tmp1)
    {
        Insert(tmp1->coef, tmp1->expon, &rear);
        tmp1 = tmp1->next;
    }
    while(tmp2)
    {
        Insert(tmp2->coef, tmp2->expon, &rear);
        tmp2 = tmp2->next;
    }
    return p;
}

Polynomial mulPoly(Polynomial p1, Polynomial p2)
{

}

/*
 * 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔
 * 4 3 4 -5 2 6 1 -2 0
 * 3 5 20 -7 4 3 1
 * 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0
 */
int main()
{
    Polynomial p1, p2;
    p1 = readPoly();
    p2 = readPoly();
    printPoly(p1);
    printPoly(p2);
    Polynomial p;
    p = addPoly(p1, p2);
    printPoly(p);
    deleteList(p1);
    deleteList(p2);
    deleteList(p);
    return 0;
}
