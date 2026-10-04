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

    void sum(TreeNode *root, int secSum, int &finalSum){
        if(root==nullptr){
            return;
        }
        secSum=((secSum*10)+root->val);

        if(root->left==nullptr && root->right==nullptr){
            finalSum=finalSum+secSum;
        }

        sum(root->left,secSum,finalSum);
        sum(root->right,secSum,finalSum);
    }
    int sumNumbers(TreeNode* root) {
        
        int finalSum=0;
        int secSum=0;

        sum(root,secSum,finalSum);

        return finalSum;
    }
};