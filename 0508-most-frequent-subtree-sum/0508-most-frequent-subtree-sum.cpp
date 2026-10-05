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
    int path(TreeNode *root, unordered_map<int, int> &mpp){
        if(root==nullptr){
            return 0;
        }

        int left=path(root->left,mpp);
        int right=path(root->right,mpp);

        int sum=root->val+left+right;
        if (mpp.find(sum) == mpp.end()) {
            mpp[sum] = 1;
        }
        else {
            mpp[sum]++;
        }

        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {

        if(root==nullptr){
            return {};
        }
        
        unordered_map<int, int> mpp;
        path(root,mpp);

        int maxFreq = 0;

        for (auto it : mpp) {
            maxFreq = max(maxFreq, it.second);
        }

        vector<int> ans;

        for (auto it : mpp) {
            if (it.second == maxFreq) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
    
};