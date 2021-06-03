/*
 * @Author: junhuizhou
 * @Date: 2021-06-03 18:53:26
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 19:49:37
 * @Description: header
 * @FilePath: \LeetCode\List\141_cycle_list_1.cpp
 */

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
    bool hasCycle(ListNode *head) 
    {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
