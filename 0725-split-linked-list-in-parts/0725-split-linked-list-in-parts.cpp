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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> arr(k, nullptr);

        int count=0;

        ListNode *traverse=head;
        
        while(traverse){
            count++;
            traverse=traverse->next;
        }

        int groups=count/k;
        int remaining=count%k;

        ListNode *current=head;
        ListNode *previous=nullptr;

        for(int i=0; current!=nullptr && i<k;i++){
            arr[i]=current;

            for(int j=1;j<=groups + (remaining>0 ? 1 : 0) ; j++){

                previous=current;
                current=current->next;
            }

            previous->next=nullptr;
            remaining--;
        }

        return arr;
    }
};