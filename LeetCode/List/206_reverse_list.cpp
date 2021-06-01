/*
 * @Author: junhuizhou
 * @Date: 2021-06-01 14:04:42
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-01 14:25:37
 * @Description: header
 * @FilePath: \LeetCode\List\206_reverse_list.cpp
 */

// 翻转链表

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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prenode = nullptr;
        ListNode* curnode = head;
        ListNode* tmp;
        
        while (curnode != nullptr)
        {
            tmp = curnode->next;
            curnode->next = prenode;
            prenode = curnode;
            curnode = tmp;
        }

        return prenode;
    }
};