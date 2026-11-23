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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==nullptr){
            return head;
        }

        if(head->next==nullptr){
            return head;
        }

        ListNode dummyNode(-1);
        ListNode *dummy = &dummyNode;
        dummy->next = head;

        ListNode *previous = &dummyNode;
        ListNode *current = head;
        ListNode *future = head->next;

        while(future){
            
            if(current->val==future->val){
                while(future && current->val==future->val){
                future = future->next;
                }
                current = future;
            }
            else{
                previous->next = current;
                previous = current;
                current = future;
            }

            if(future) future = future->next;
        }

        previous->next = current;

        return dummy->next;
        
    }
};