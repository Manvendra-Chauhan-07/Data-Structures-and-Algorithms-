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

int height(TreeNode *root, int &maxi){

    if(root==nullptr){
        return 0;
    }

    int left = height(root->left,maxi);
    int right = height(root->right,maxi);

    int current=left+right;
    
    maxi=max(maxi,current);

    return 1+max(left,right);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi=INT_MIN;

        height(root,maxi);

        return maxi;
    }
};