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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==nullptr){
            return nullptr;
        }

        if(n==0){
            return head;
        }

        int count = 0;
        ListNode *traverse = head;
        while(traverse){
            count++;
            traverse = traverse->next;
        }

        n = count - n;

        if(n==0){
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode *previous = nullptr;
        ListNode *current = head;

        for(int i=1;i<=n;i++){
            previous = current;
            current = current->next;
        }

        previous->next = current->next;

        delete current;

        return head;

    }
};