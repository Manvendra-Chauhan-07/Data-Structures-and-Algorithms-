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

    ListNode* removeNodes(ListNode* head) {

        head=reverse(head);

        int maxiValue=-1;

        ListNode *current=head;
        ListNode *previous=nullptr;

        while(current){

            maxiValue=max(current->val,maxiValue);

            if((current->val)<maxiValue){
                previous->next=current->next;
                // ListNode *temp=current;
                current=current->next;
                // delete(temp);

            }else{
                previous=current;
                current=current->next;
            }
        }

       return reverse(head);

    }
};