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

int path(TreeNode *root, int &sum){

    if(root==nullptr){
        return 0;
    }

    int leftSum=path(root->left,sum);
    int rightSum=path(root->right,sum);

    int currentSum=root->val+max(max(0,leftSum),max(0,rightSum));

    int nodeSum=root->val+max(0,leftSum)+max(0,rightSum);

    sum=max(sum,nodeSum);

    return currentSum;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {

        int sum=INT_MIN;
        path(root,sum);

        return sum;
        
    }
};