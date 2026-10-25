/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q){

        if(root==nullptr){
            return nullptr;
        }

        if(root==p || root==q){
            return root;
        }

        TreeNode *left = LCA(root->left,p,q);
        TreeNode *right = LCA(root->right,p,q);

        if(left!=nullptr && right!=nullptr){
            return root;
        }
        if(left!=nullptr && right==nullptr){
            return left;
        }

        return right;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return LCA(root,p,q);
    }
};