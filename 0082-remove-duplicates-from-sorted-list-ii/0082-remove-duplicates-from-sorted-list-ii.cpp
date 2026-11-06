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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==nullptr){
            return head;
        }

        unordered_map<int,int> mpp;

        ListNode *traverse=head;
        while(traverse){
            mpp[traverse->val]++;
            traverse=traverse->next;
        }

        ListNode dummyNode(-1);
        ListNode *dummyTail = &dummyNode;
        ListNode *current=head;

        while(current){
            if(mpp[current->val]==1){
                dummyTail->next=current;
                dummyTail=dummyTail->next;
            }
            current=current->next;
        }

        dummyTail->next=nullptr;

        return dummyNode.next;
    }
};