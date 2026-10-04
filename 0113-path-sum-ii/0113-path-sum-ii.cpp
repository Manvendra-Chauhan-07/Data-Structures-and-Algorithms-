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

    bool path(TreeNode *root, int targetSum, vector<int> arr, vector<vector<int>> &ans){
        if(root==nullptr){
            return false;
        }

        arr.push_back(root->val);

        targetSum=targetSum-root->val;

        if((root->left==nullptr && root->right==nullptr) && targetSum==0){
            ans.push_back(arr);
        }

        return (path(root->left,targetSum,arr,ans) || path(root->right,targetSum,arr,ans));
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>arr;
        vector<vector<int>> ans;

        path(root,targetSum,arr,ans);

        return ans;
    }
};