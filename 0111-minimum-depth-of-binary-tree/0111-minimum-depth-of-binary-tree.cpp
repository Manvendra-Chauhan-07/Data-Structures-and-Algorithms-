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

    int path(TreeNode *root){
        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        if(root->left==nullptr){
            return 1+path(root->right);
        }
        if(root->right==nullptr){
            return 1+path(root->left);
        }
        return 1+min(path(root->right),path(root->left));
    }
    int minDepth(TreeNode* root) {
        
        if(root==nullptr){
            return 0;
        }
        return path(root);
    }
};