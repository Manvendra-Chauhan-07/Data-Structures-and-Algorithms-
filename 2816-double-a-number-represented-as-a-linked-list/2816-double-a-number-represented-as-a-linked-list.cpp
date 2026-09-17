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
    ListNode* doubleIt(ListNode* head) {

        ListNode *future=head;
        ListNode *current=nullptr;
        ListNode *previous=nullptr;

        while(future){
            current=future;
            future=future->next;
            current->next=previous;
            previous=current;
        }

        int carry=0;

        ListNode *temp=new ListNode(-1);
        ListNode *tempTail=temp;

        while(previous || carry){

            int value = (previous)? ((previous->val)*2) : 0;

            int sum=value+carry;

            tempTail->next=new ListNode(sum%10);
            tempTail=tempTail->next;

            carry=sum/10;

            if(previous){
                previous=previous->next;
            }
        }

        temp=temp->next;

        ListNode *future1=temp;
        ListNode *current1=nullptr;
        ListNode *previous1=nullptr;

        while(future1){
            current1=future1;
            future1=future1->next;
            current1->next=previous1;
            previous1=current1;
        }
        
        return previous1;
    }
};