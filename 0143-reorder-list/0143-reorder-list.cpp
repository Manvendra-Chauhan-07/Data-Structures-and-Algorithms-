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
    void reorderList(ListNode* head) {

        if(head==nullptr || head->next==nullptr){
            return;
        }

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *future = slow->next;

        slow->next=nullptr;

        ListNode *current=nullptr;
        ListNode *previous=nullptr;
        
        while(future){
            current=future;
            future=future->next;
            current->next=previous;
            previous=current;
        }

        ListNode *start=head;
        ListNode *end=previous;


        while(end){

            ListNode *startNext=start->next;
            ListNode *endNext=end->next;

            start->next=end;
            end->next=startNext;

            start=startNext;
            end=endNext;
        }

        
    }
};