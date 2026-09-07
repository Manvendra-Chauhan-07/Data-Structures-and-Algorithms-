/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next==nullptr)
        {
            return head;
        }

        ListNode *odd=head;
        ListNode *even=head->next;

        ListNode *odd_tail=odd;
        ListNode *even_tail=even;

        while(even_tail && even_tail->next)
        {
            odd_tail->next=even_tail->next;
            odd_tail=odd_tail->next;

            even_tail->next=odd_tail->next;
            even_tail=even_tail->next;
        }

        odd_tail->next=even;

        return odd;
        
    }
};