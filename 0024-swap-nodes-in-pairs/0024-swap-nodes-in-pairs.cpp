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

    ListNode *swapNodes(ListNode *current, ListNode *future){

        if(future==nullptr){
            return current;
        }

        if(future->next==nullptr){
            current->next = nullptr;
            future->next = current;
            return future;
        }

        ListNode *currHead = current;

        ListNode *returnNode = swapNodes(future->next,future->next->next);

        current->next = returnNode;
        future->next = current;

        return future;

    }

    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }

        return swapNodes(head,head->next);
    }
};