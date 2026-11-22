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
    bool isPalindrome(ListNode* head) {
        
        if(head==nullptr){
            return true;
        }

        if(head->next==nullptr){
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * future = slow->next;

        slow->next = nullptr;

        ListNode *current = nullptr;
        ListNode *previous = nullptr;

        while(future){
            current = future;
            future = future->next;
            current->next = previous;
            previous = current;
        }

        ListNode *l1 = head;
        ListNode *l2 = previous;

        while(l1 && l2){
            if(l1->val!=l2->val){
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1==nullptr && l2!=nullptr){
            return true;
        }
        if(l1!=nullptr && l2==nullptr){
            return true;
        }
        if(l1==nullptr && l2==nullptr){
            return true;
        }

        return true;
    }
};