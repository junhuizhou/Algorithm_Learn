/*
 * @Author: junhuizhou
 * @Date: 2021-06-01 14:33:27
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 13:53:40
 * @Description: header
 * @FilePath: \LeetCode\List\24_swap_pairs.cpp
 */

// 两两交换节点

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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curnode = dummyHead;

        while (curnode->next != nullptr && curnode->next->next != nullptr)
        {
            ListNode* tmp1 = curnode->next;
            ListNode* tmp2 = curnode->next->next->next;
            
            curnode->next = curnode->next->next;
            curnode->next->next = tmp1;
            curnode->next->next->next = tmp2;
            
            curnode = curnode->next->next;
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};