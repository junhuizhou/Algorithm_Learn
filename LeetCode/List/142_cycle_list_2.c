/*
 * @Author: junhuizhou
 * @Date: 2021-06-03 19:10:48
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 20:24:08
 * @Description: header
 * @FilePath: \LeetCode\List\142_cycle_list_2.c
 */

// 找到链表环的入口

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) 
{
    if (head == NULL || head->next == NULL) return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode* index1 = head;
            struct ListNode* index2 = fast;
            while (index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    
    return NULL;
}
