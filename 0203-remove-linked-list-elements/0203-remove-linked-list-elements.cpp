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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==nullptr){
            return head;
        }

        ListNode dummyNode(-1);
        ListNode *dummy = &dummyNode;
        dummy->next = head;

        ListNode *current = head;
        ListNode *previous = &dummyNode;

        while(current){
            if(current->val==val){
                previous->next = current->next;
                ListNode *temp = current;
                current = current->next;
                delete temp;
            }
            else{
                previous=current;
                current=current->next;
            }
        }

        return dummy->next;
    }
};