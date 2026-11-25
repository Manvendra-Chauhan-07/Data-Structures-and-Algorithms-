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
        
        if(head==nullptr){
            return nullptr;
        }

        ListNode lessthanX(-1);
        ListNode *headLess = &lessthanX;
        ListNode *tailLess = &lessthanX;

        ListNode greaterthanX(-1);
        ListNode *headMore = &greaterthanX;
        ListNode *tailMore = &greaterthanX;

        ListNode *current = head;

        while(current){
            
            ListNode *future = current->next;
            
            if(current->val<x){
                tailLess->next = current;
                tailLess = tailLess->next;
            }
            else{
                tailMore->next = current;
                tailMore = tailMore->next;
            }
            current->next = nullptr;
            current = future;
        }

        tailLess->next = headMore->next;
        tailMore->next = nullptr;

        return headLess->next;
    }
};