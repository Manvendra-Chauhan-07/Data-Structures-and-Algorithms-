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
        
        ListNode *temp=new ListNode(-1);
        ListNode *tempTail=temp;

        int carry=0;

        while(l1 || l2 || carry){

            int value1 = l1? l1->val : 0;
            int value2 = l2? l2->val : 0;

            int sum=value1+value2+carry;

            tempTail->next=new ListNode(sum%10);
            tempTail=tempTail->next;

            carry=sum/10;

            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }

        }

        return temp->next;
    }
};