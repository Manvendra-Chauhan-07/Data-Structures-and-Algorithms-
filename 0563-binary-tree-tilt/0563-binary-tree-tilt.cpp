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
    int path(TreeNode *root, int &sum){
        if(root==nullptr){
            return 0;
        }
        int left=path(root->left,sum);
        int right=path(root->right,sum);

        sum=sum+abs(left-right);

        return root->val+left+right;
    }
    int findTilt(TreeNode* root) {

        if(root==nullptr){
            return 0;
        }
        
        int sum=0;
        path(root,sum);

        return sum;
    }
};