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

    ListNode *reverse(ListNode *head){

        ListNode *future=head;
        ListNode *current=nullptr;
        ListNode *previous=nullptr;

        while(future){
            current=future;
            future=future->next;
            current->next=previous;
            previous=current;
        }

        return previous;
    }

    ListNode *path(ListNode *head, int k){

        if(head==nullptr){
            return head;
        }

        int count=k;
        ListNode *tempHead=head;
        ListNode *current=head;
        ListNode *previous=nullptr;

        while(current && count){
            previous=current;
            current=current->next;
            count--;
        }

        if(count>0){
            return tempHead;
        }

        ListNode *ans = path(current,k);

        previous->next=nullptr;

        ListNode *newHead = reverse(tempHead);

        tempHead->next=ans;

        return newHead;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        return path(head,k);
    }
};