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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }

        ListNode *starting = head;

        for(int i=1;i<k;i++){
            starting = starting->next;
        }

        ListNode *current = head;
        ListNode *previous = nullptr;

        while(current){
            ListNode *future = current->next;
            current->next = previous;
            previous = current;
            current = future;
        }

        ListNode *ending = previous;

        for(int i=1;i<k;i++){
            ending = ending->next;
        }

        ListNode *current1 = previous;
        ListNode *previous1 = nullptr;

        while(current1){
            ListNode *future1 = current1->next;
            current1->next = previous1;
            previous1 = current1;
            current1 = future1;
        }

        swap(starting->val,ending->val);

        return head;
    }
};