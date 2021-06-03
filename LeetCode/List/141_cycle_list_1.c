/*
 * @Author: junhuizhou
 * @Date: 2021-06-03 18:53:43
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 19:48:51
 * @Description: header
 * @FilePath: \LeetCode\List\141_cycle_list_1.c
 */

// 判断链表是否有环

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) 
{
    if (head == NULL || head->next == NULL) return false;

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}