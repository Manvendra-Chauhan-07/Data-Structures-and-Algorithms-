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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode *temp = new ListNode(-1);
        ListNode *tempTail=temp;

        ListNode *current=head->next;

        int sum=0;

        while(current){

            if(current->val==0){
                tempTail->next=new ListNode(sum);
                tempTail=tempTail->next;
                sum=0;
            }
            else{
                sum+=current->val;
            }

            current=current->next;
        }

        return temp->next;
    }
};