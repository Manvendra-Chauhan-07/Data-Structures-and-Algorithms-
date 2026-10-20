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

    TreeNode *traverse(TreeNode *root, TreeNode *p, TreeNode *q){

        if(root==nullptr){
            return nullptr;
        }

        if((root->val>p->val) && (root->val>q->val)){
            return traverse(root->left,p,q);
        }else if((root->val<p->val) && (root->val<q->val)){
            return traverse(root->right,p,q);
        }else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return traverse(root,p,q);

    }
};