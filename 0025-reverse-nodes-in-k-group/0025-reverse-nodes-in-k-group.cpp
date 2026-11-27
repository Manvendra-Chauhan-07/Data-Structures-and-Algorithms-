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

    ListNode *reverse(ListNode *head){

        ListNode *previous = nullptr;
        ListNode *current = head;

        while(current){
            ListNode *future = current->next;
            current->next = previous;
            previous = current;
            current = future;
        }

        return previous;
    }

    ListNode *breakNodes(ListNode *head, int k){

        int K=k;
        ListNode *currHead = head;
        ListNode *current = head;
        ListNode *lastNode = nullptr;

        while(K && current){
            lastNode = current;
            current = current->next;
            K--;
        }

        if(K>0 && current==nullptr){
            return currHead;
        }

        if(lastNode) lastNode->next = nullptr;

        ListNode *returnNode = breakNodes(current,k);
        ListNode *connectingNode = reverse(currHead);

        currHead->next = returnNode;

        return connectingNode;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }
        if(k==0){
            return head;
        }

        return breakNodes(head,k);

    }
};