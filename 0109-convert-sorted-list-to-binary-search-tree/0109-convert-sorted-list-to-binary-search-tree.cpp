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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    ListNode* current;

    TreeNode* traverse(int start, int end) {

        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;

        TreeNode* leftChild = traverse(start, mid - 1);

        TreeNode* root = new TreeNode(current->val);
        current = current->next;

        root->left = leftChild;

        root->right = traverse(mid + 1, end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        
        int n = 0;
        current = head;

        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        return traverse(0, n - 1);
    }
};