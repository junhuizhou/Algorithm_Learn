/*
 * @Author: junhuizhou
 * @Date: 2021-06-01 14:04:32
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-01 14:18:13
 * @Description: header
 * @FilePath: \LeetCode\List\206_reverse_list.c
 */

// 翻转链表

#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prenode = NULL;
    struct ListNode* curnode = head;
    struct ListNode* tmp;

    while (curnode != NULL)
    {
        tmp = curnode->next;
        curnode->next = prenode;
        prenode = curnode;
        curnode = tmp;
    }

    return prenode;
}
