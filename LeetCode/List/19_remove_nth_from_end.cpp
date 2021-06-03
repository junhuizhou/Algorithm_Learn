/*
 * @Author: junhuizhou
 * @Date: 2021-06-03 14:00:02
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-03 14:30:08
 * @Description: header
 * @FilePath: \LeetCode\List\19_remove_nth_from_end.cpp
 */

// 移除倒数第N个数

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        while (n--)
        {
            fast = fast->next;
        }
        fast = fast->next;

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        head = dummyHead->next;
        delete tmp;
        delete dummyHead;
        return head;
    }
};
