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
    void traverse(TreeNode *root, long long &prevValue, bool &answer){
        if(root==nullptr){
            return;
        }

        traverse(root->left,prevValue,answer);

        if(root->val<=prevValue){
            answer=false;
        }else{
            prevValue=root->val;
        }

        traverse(root->right,prevValue,answer);
    }

    bool isValidBST(TreeNode* root) {
        
        long long prevValue = LLONG_MIN;
        bool answer=true;

        traverse(root,prevValue,answer);

        return answer;

    }
};