/*
 * @Author: junhuizhou
 * @Date: 2021-05-29 11:46:49
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-01 13:58:26
 * @Description: header
 * @FilePath: \LeetCode\List\203_remove_element.c
 */

// 移除所有值为val的node
// 解法很多，不用空表头的分类移除，添加空表头的统一移除，递归解法

#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* curnode = dummyHead;

    while (curnode->next != NULL)
    {
        if (curnode->next->val == val)
        {
            struct ListNode* tmp = curnode->next;
            curnode->next = curnode->next->next;
            free(tmp);
        }
        else
        {
            curnode = curnode->next;
        }
    }

    head = dummyHead->next;
    free(dummyHead);
    return head;
}