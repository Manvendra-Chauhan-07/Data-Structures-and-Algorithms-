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

    void path(TreeNode *root, vector<string> &arr, string p){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            p+=to_string(root->val);
            arr.push_back(p);
        }

        p += to_string(root->val)+"->";

        path(root->left,arr,p);
        path(root->right,arr,p);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(root==nullptr){
            return {};
        }
        if(root->left==nullptr && root->right==nullptr){
            return {to_string(root->val)};
        }

        vector<string> arr;

        string p = "";   

        path(root,arr,p);

        return arr;
    }
};