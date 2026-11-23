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
        
        ListNode *slow = head;
        ListNode *fast = head;

        for(int i=1;i<=n;i++){
            fast = fast->next;
        }

        ListNode *previous = nullptr;

        while(fast){
            previous = slow;
            slow = slow->next;
            fast =fast->next;
        }

        if(previous==nullptr){
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        previous->next = slow->next;
        

        return head;
    }
};