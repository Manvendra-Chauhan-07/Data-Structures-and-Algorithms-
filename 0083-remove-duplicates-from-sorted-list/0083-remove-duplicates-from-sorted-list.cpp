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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==nullptr){
            return head;
        }

        if(head->next==nullptr){
            return head;
        }
        
        ListNode *current = head;
        ListNode *future = head->next;

        while(future){
            if(future->val==current->val){
                ListNode *temp = future;
                future=future->next;
                current->next=future;
                delete temp;
            }else{
                current=future;
                future=future->next;
            }
        }

        return head;
    }
};