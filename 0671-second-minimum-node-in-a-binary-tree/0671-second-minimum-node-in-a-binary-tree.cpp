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

    void path(TreeNode *root, int &firstMin, int &secMin, bool &found){
        if(root==nullptr){
            return;
        }

        if(root->val<firstMin){
            secMin=firstMin;
            firstMin=root->val;
        }
        else if(root->val>firstMin && root->val<=secMin){
            secMin=root->val;
            found=true;
        }

        path(root->left,firstMin,secMin,found);
        path(root->right,firstMin,secMin,found);
        
    }
    int findSecondMinimumValue(TreeNode* root) {

        if(root==nullptr){
            return -1;
        }

        int firstMin=INT_MAX;
        int secondMin=INT_MAX;
        bool found = false;

        path(root,firstMin,secondMin,found);

        if(found==false){
            return -1;
        }

        return secondMin;
    }
};