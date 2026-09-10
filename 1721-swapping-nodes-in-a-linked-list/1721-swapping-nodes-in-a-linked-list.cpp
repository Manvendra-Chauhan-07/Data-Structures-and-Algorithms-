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
        
        int k1=k-1;
        int k2=k-1;

        ListNode *traverse=head;

        while(k1 && traverse){
            traverse=traverse->next;
            k1--;
        }

        int value1=traverse->val;

        ListNode *future=head;
        ListNode *current=nullptr;
        ListNode *previous=nullptr;

        while(future)
        {
            current=future;
            future=future->next;
            current->next=previous;
            previous=current;
        }

        while(k2 && current)
        {
            current=current->next;
            k2--;
        }

        int value2=current->val;

        ListNode *future1=previous;
        ListNode *current1=nullptr;
        ListNode *previous1=nullptr;

        while(future1)
        {
            current1=future1;
            future1=future1->next;
            current1->next=previous1;
            previous1=current1;
        }

        swap(current->val , traverse->val);

        return head;

    }
};