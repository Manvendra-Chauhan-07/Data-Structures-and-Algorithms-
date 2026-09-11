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

ListNode *recursiveSwap(ListNode* previous,ListNode* current){

    if(current==nullptr){
        // current->next=previous;
        // previous->next=nullptr;
        return previous;
    }
    if(current->next==nullptr){
        current->next=previous;
        previous->next=nullptr;
        return current;
    }

    previous->next=recursiveSwap(current->next,current->next->next);

    current->next=previous;

    return current;

}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr){
            return head;
        }
        
        if(head->next==nullptr)
        {
            return head;
        }

        ListNode *previous=head;
        ListNode *current=head->next;

        return recursiveSwap(previous,current);

 
        
        
    }
};