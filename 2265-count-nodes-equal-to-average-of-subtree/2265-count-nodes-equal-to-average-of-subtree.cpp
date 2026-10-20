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

    int calculateNodes(TreeNode *root){

        if(root==nullptr){
            return 0;
        }

        int left=calculateNodes(root->left);
        int right=calculateNodes(root->right);

        return left+right+1;
    }

    int traverse(TreeNode *root, int nodeCount, int &ans){

        if(root==nullptr){
            return 0;
        }

        int left=traverse(root->left,nodeCount,ans);
        int right=traverse(root->right,nodeCount,ans);


        nodeCount = calculateNodes(root);
        
        int sum = left+right+root->val;

        int average=((sum)/nodeCount);

        if(average==root->val){
            ans++;
        }
        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        
        int nodeCount=0;
        int ans=0;

        traverse(root,nodeCount,ans);

        return ans;
    }
};