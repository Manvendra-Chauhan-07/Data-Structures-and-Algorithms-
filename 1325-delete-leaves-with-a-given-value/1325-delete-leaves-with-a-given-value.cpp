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

    TreeNode *deleteLeaf(TreeNode *&root, int target){
        if(root==nullptr){
            return nullptr;
        }

        deleteLeaf(root->left,target);
        deleteLeaf(root->right,target);

        if(root->val==target && (root->left==nullptr && root->right==nullptr )){
            root = nullptr;
        }

        return root;

    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        return deleteLeaf(root,target);
    }
};