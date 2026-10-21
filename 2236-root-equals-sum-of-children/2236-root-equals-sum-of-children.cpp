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
    
    void traverse(TreeNode *root, bool &flag){
        if((root->left==nullptr && root->right==nullptr) || flag==false){
            return;
        }

        int left = (root->left)? root->left->val : 0;
        int right = (root->right)? root->right->val : 0;

        if(root->val!=(left+right)){
            flag=false;
        }

        traverse(root->left,flag);
        traverse(root->right,flag);
    }
    bool checkTree(TreeNode* root) {
        
        bool flag = true;

        if(root==nullptr){
            return true;
        }

        traverse(root,flag);

        return flag;
    }
};