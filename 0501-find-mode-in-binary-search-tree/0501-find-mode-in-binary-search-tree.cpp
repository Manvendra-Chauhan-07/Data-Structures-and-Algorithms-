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

    void traverse(TreeNode *root, unordered_map<int,int> &mpp, int &maximum){
        if(root==nullptr){
            return;
        }

        traverse(root->left,mpp,maximum);

        mpp[root->val]++;

        maximum=max(maximum,mpp[root->val]);

        traverse(root->right,mpp,maximum);

    }

    vector<int> findMode(TreeNode* root) {
        
        unordered_map<int,int> mpp;

        int maximum = -1;

        traverse(root,mpp,maximum);

        vector<int> ans;

        for(auto it : mpp){
            if(it.second==maximum){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};