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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *first = nullptr;

        ListNode *current=list1;

        while(current && a){
            first=current;
            current=current->next;
            a--; 
        }

        ListNode *second=nullptr;

        current=list1;

        b=b+1;

        while(current && b){
            second=current;
            current=current->next;
            b--;
        }

        ListNode *lastL2=nullptr;
        
        current=list2;

        while(current){
            lastL2=current;
            current=current->next;
        }

        first->next=list2;
        lastL2->next=second->next;


        return list1;

    }
};