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
        ListNode *even=new ListNode(-1);
        ListNode *odd=new ListNode(-1);

        ListNode *even_tail=even;
        ListNode *odd_tail=odd;

        ListNode *current=head;
        ListNode *previous=nullptr;

        int count=1;

        while(current)
        {
            if(count%2!=0)
            {
                odd_tail->next=current;
                odd_tail=odd_tail->next;
            }
            else
            {
                even_tail->next=current;
                even_tail=even_tail->next;
            }
            previous=current;
            current=current->next;
            previous->next=nullptr;
            count++;
        }

        even=even->next;
        odd_tail->next=even;

        return odd->next;

    }
};