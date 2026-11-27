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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }
        if(k==0){
            return head;
        }

        ListNode *traverse = head;
        
        int count = 0;

        while(traverse){
            count++;
            traverse = traverse->next;
        }

        k = k % count;

        if(k==0){
            return head;
        }

        count = count - k;

        ListNode *previous = nullptr;
        ListNode *current = head;

        for(int i=1;i<=count;i++){
            previous = current;
            current = current->next;
        }

        previous->next = nullptr;

        ListNode *newHead = current;

        while(newHead->next){
            newHead = newHead->next;
        }

        newHead->next = head;   

        return current;

        

    }
};