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
    ListNode* removeElements(ListNode* head, int val) {

        if(head==nullptr){
            return nullptr;
        }

        
        
        ListNode *current = new ListNode(-1);
        ListNode *currTail = current;
        ListNode *future = head;

        while(future){
            if(future->val!=val){
                currTail->next=future;
                currTail=currTail->next;
            }
            future=future->next;
        }

        currTail->next=nullptr;

        return current->next;
    }
};