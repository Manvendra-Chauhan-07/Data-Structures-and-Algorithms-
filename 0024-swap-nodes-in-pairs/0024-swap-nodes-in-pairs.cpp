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

    ListNode *swap(ListNode *current,ListNode *future){
        if(future==nullptr){
            return current;
        }

        if(future->next==nullptr){
            current->next=nullptr;
            future->next=current;
            return future;
        }

        // current->next=nullptr;
        // future->next=current;

        current->next=swap(future->next,future->next->next);
        future->next=current;

        return future;
    }


    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr){
            return head;
        }

        return swap(head,head->next);
    }
};