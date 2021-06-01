/*
 * @Author: junhuizhou
 * @Date: 2021-05-29 11:46:39
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-01 13:43:04
 * @Description: header
 * @FilePath: \LeetCode\List\203_remove_element.cpp
 */

// 移除所有值为val的node
// 解法很多，不用空表头的分类移除，添加空表头的统一移除，递归解法

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curnode = dummyHead;

        while (curnode->next != nullptr)
        {
            if (curnode->next->val == val)
            {
                ListNode* tmp = curnode->next;
                curnode->next = curnode->next->next;
                delete tmp;
            }
            else
            {
                curnode = curnode->next;
            }
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};