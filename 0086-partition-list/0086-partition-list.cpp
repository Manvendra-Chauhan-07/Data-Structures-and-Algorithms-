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
    ListNode* partition(ListNode* head, int x) {

        ListNode *smallX = new ListNode(-1);
        ListNode *smallX_tail = smallX;

        ListNode *greatX = new ListNode(-1);
        ListNode *greatX_tail = greatX;

        ListNode *current=head;

        while(current){

            if((current->val)<x){
                smallX_tail->next=current;
                smallX_tail=smallX_tail->next;
                current=current->next;
                smallX_tail->next=nullptr;
            }
            else{
                greatX_tail->next=current;
                greatX_tail=greatX_tail->next;
                current=current->next;
                greatX_tail->next=nullptr;
            }
        }

        smallX_tail->next=greatX->next;

        return smallX->next;
        
    }
};