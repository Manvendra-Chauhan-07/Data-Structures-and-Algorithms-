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

    void traverse(TreeNode *root, int &k, int &answer){
        if(root==nullptr){
            return;
        }

        traverse(root->left,k,answer);

        if(k!=0 || k>0){
            k--;
            answer=root->val;
        }

        traverse(root->right,k,answer);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int answer = -1;

        traverse(root,k,answer);

        return answer;
    }
};