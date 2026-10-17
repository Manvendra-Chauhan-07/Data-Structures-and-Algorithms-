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
    void traverse(TreeNode *root, TreeNode *&prevRoot, int &answer){
        if(root==nullptr){
            return;
        }

        traverse(root->left,prevRoot, answer);

        if(prevRoot!=nullptr){
            int currentVal=root->val-prevRoot->val;

            if(currentVal<answer){
                answer=currentVal;
            }
        }

        prevRoot=root;

        traverse(root->right,prevRoot,answer);
    }

    int getMinimumDifference(TreeNode* root) {
        
        TreeNode *prevRoot=nullptr;

        int answer=INT_MAX;

        traverse(root,prevRoot,answer);

        return answer;
    }
};