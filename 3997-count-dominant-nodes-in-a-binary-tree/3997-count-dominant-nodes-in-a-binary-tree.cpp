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

    int path(TreeNode *root, int &count){

        if(root == nullptr) {
            return 0 ;
        }


        
        int left = path(root->left,count);
        int right = path(root->right,count);

        if(root->val>=left && root->val>=right){
            count++;
        }

        return max(max(left,right),root->val);

    }

    int countDominantNodes(TreeNode* root) {

        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        
        int count=0;
        path(root,count);

        return count;
    }
};