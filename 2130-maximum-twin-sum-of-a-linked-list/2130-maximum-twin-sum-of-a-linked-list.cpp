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
    int pairSum(ListNode* head) {

        ListNode *traverse=head;
        int count=0;

        while(traverse){
            count++;
            traverse=traverse->next;
        }

        count=count/2;
        // count=count-1;

        ListNode *current=head;
        ListNode *previous=nullptr;

        while(count--)
        {
            previous=current;
            current=current->next;
        }

        previous->next=nullptr;

        ListNode *reverse=nullptr;
        ListNode *morePrevious=nullptr;

        while(current)
        {
            reverse=current;
            current=current->next;
            reverse->next=morePrevious;
            morePrevious=reverse;
        }

        long long ans=0;

        ListNode *head1=head;
        while(head1 && morePrevious)
        {
            int value=head1->val+morePrevious->val;
            if((value)>ans){
                ans=value;
            }

            head1=head1->next;
            morePrevious=morePrevious->next;
        }

        return ans;
    }
};