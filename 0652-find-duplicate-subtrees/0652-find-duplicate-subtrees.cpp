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

    string subTree(TreeNode *root, unordered_map<string, int> &mpp, vector<TreeNode *> &ans){
        if(root==nullptr){
            return "N";
        }

        string s = to_string(root->val)+","+subTree(root->left,mpp,ans)+","+subTree(root->right,mpp,ans);
        
        if(mpp[s]==1){
            ans.push_back(root);
        }

        mpp[s]++;

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode *>ans;
        unordered_map<string, int> mpp;

        subTree(root,mpp,ans);

        return ans;
    }
};