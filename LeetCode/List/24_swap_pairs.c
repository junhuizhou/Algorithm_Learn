/*
 * @Author: junhuizhou
 * @Date: 2021-06-01 14:33:16
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 13:41:37
 * @Description: header
 * @FilePath: \LeetCode\List\24_swap_pairs.c
 */

// 两两交换节点

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* curnode = dummyHead;
    
    while (curnode->next != NULL && curnode->next->next != NULL)
    {
        struct ListNode* tmp1 = curnode->next;
        struct ListNode* tmp2 = curnode->next->next->next;

        curnode->next = curnode->next->next;
        curnode->next->next = tmp1;
        curnode->next->next->next = tmp2;

        curnode = curnode->next->next;
    }

    head = dummyHead->next;
    free(dummyHead);
    return head;
}