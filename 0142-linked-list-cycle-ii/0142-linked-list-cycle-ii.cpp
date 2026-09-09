/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *detectcycle2(ListNode *head, ListNode *fast)
    {
        ListNode *slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        // while(fast->next!=slow)
        // {
        //     fast=fast->next;
        // }

        return slow;

    }
    ListNode *detectCycle(ListNode *head) {
        
        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next==nullptr)
        {
            return nullptr;
        }

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow == fast)
            {
                return detectcycle2(head,fast);
            }
        }
        return nullptr;
    }
};