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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //Reversing 1st List.
        ListNode *future=l1;
        ListNode *current=nullptr;
        ListNode *previous=nullptr;

        while(future){
            current=future;
            future=future->next;
            current->next=previous;
            previous=current;
        }
        //New Head of 1st List is Previous.

        //Reversing 2nd List.
        ListNode *future1=l2;
        ListNode *current1=nullptr;
        ListNode *previous1=nullptr;

        while(future1){
            current1=future1;
            future1=future1->next;
            current1->next=previous1;
            previous1=current1;
        }
        //New Head of the second List is previous1.

        ListNode *ans=new ListNode(-1);
        ListNode *ans_tail=ans;

        int carry=0;

        while(previous || previous1 || carry){

            int val1 = (previous)? previous->val : 0;
            int val2 = (previous1)? previous1->val : 0;

            int sum=val1+val2+carry;
            carry = sum/10;

            ans_tail->next = new ListNode(sum%10);

            if(previous){
                previous=previous->next;
            }

            if(previous1){
                previous1=previous1->next;
            }

            ans_tail=ans_tail->next;
        }

        ans=ans->next;

        ListNode *future2=ans;
        ListNode *current2=nullptr;
        ListNode *previous2=nullptr;

        while(future2){
            current2=future2;
            future2=future2->next;
            current2->next=previous2;
            previous2=current2;
        }

        return previous2;
    }
};