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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr){
            return head;
        }
        
        if(k==0){
            return head;
        }

        int count = 0;
        ListNode *traverse = head;

        while(traverse){
            count++;
            traverse = traverse->next;
        }

        k = k % count;

        if(k==0){
            return head;
        }

        k = count - k;

        ListNode *current=head;
        ListNode *previous=nullptr;

        for(int i=1;i<=k;i++){
            previous=current;
            current=current->next;
        }

        previous->next=nullptr;

        ListNode *last = current;

        while(last->next){
            last = last->next;
        }

        last->next = head;

        return current;
        
    }
};