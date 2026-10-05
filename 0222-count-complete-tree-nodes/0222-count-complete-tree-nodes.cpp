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
    int leftHeight(TreeNode *root){
        int h=0;
        while(root!=nullptr){
            h++;
            root=root->left;
        }
        return h;
    }

    int rightHeight(TreeNode *root){
        int h=0;
        while(root!=nullptr){
            h++;
            root=root->right;
        }
        return h;
    }

    int path(TreeNode *root){
        if(root==nullptr){
            return 0;
        }

        int left=leftHeight(root);
        int right=rightHeight(root);

        if(left==right){
            return (pow(2,left)-1);
        }

        return 1+path(root->left)+path(root->right);
    }
    int countNodes(TreeNode* root) {

        return path(root);
        
    }
};