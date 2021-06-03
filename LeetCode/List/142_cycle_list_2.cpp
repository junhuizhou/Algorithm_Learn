/*
 * @Author: junhuizhou
 * @Date: 2021-06-03 19:11:02
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 20:24:16
 * @Description: header
 * @FilePath: \LeetCode\List\142_cycle_list_2.cpp
 */

// 找打链表环的入口

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
    ListNode *detectCycle(ListNode *head) 
    {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        
        return nullptr;
    }
};
