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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==nullptr){
            return head;
        }

        if(head->next==nullptr){
            return head;
        }

        ListNode dummyNode(-1);
        ListNode *headDummy = &dummyNode;
        headDummy->next = head;

        ListNode *previousLeft = &dummyNode;
        ListNode *leftCurrent = head;

        for(int i=1;i<left;i++){
            previousLeft = leftCurrent;
            leftCurrent = leftCurrent->next;

        }

        ListNode *futureNode = head->next;
        ListNode *rightCurrent = head;

        for(int j=1;j<right;j++){
            futureNode = futureNode->next;
            rightCurrent = rightCurrent->next;
        }

        rightCurrent->next = nullptr;

        
        ListNode *previous = nullptr;
        ListNode *current = leftCurrent;

        while(current){
            ListNode *future = current->next;
            current->next = previous;
            previous = current;
            current = future;
        }

        previousLeft->next = previous;
        leftCurrent->next = futureNode;

        return headDummy->next;
        
    }
};