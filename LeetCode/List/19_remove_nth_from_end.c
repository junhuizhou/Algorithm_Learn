/*
 * @Author: junhuizhou
 * @Date: 2021-06-03 13:59:40
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 14:29:59
 * @Description: header
 * @FilePath: \LeetCode\List\19_remove_nth_from_end.c
 */

// 移除倒数第N个数

#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* fast = dummyHead;
    struct ListNode* slow = dummyHead;
    
    while (n--)
    {
        fast = fast->next;
    }
    fast = fast->next;

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* tmp = slow->next;
    slow->next = slow->next->next;
    head = dummyHead->next;
    free(tmp);
    free(dummyHead);
    return head;
}
