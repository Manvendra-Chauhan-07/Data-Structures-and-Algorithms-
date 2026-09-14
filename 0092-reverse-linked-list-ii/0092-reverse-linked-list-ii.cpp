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


    ListNode *reverse(ListNode * start, ListNode *end){

        ListNode *future=start;
        ListNode *current=nullptr;
        ListNode *previous=nullptr;

        while(future!=end){
            current=future;
            future=future->next;
            current->next=previous;
            previous=current;
        }

        return previous;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *start=head;
        ListNode *previous1=nullptr;
        while(--left){
            previous1=start;
            start=start->next;
        }

        ListNode *end=head;
        ListNode *future1=head->next;

        while(--right){
            future1=future1->next;
            end=end->next;
        }

        ListNode *future=start;
        ListNode *current=nullptr;
        ListNode *previous=nullptr;

        while(future!=future1){
            current=future;
            future=future->next;
            current->next=previous;
            previous=current;
        }

        if(previous1==0){
            head=previous;
            start->next=future;
        }else{
            previous1->next=previous;
            start->next=future1;
        }

        return head;

    }
};