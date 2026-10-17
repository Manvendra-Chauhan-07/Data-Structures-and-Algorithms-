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

    TreeNode *traverse(TreeNode *root, int &answer, TreeNode* &prevRoot){
        if(root==nullptr){
            return nullptr;
        }

        TreeNode *tempRoot = traverse(root->left,answer,prevRoot);

        if(prevRoot!=nullptr){
            int currentVal=root->val-prevRoot->val;

            if(currentVal<answer){
                answer=currentVal;
            }
        }

        prevRoot=root;

        return traverse(root->right,answer,prevRoot);

    }

    int minDiffInBST(TreeNode* root) {
        
        TreeNode *prevRoot=nullptr;
        int answer=INT_MAX;

        traverse(root,answer,prevRoot);


        return answer;
    }
};