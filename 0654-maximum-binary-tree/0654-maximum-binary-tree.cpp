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
    TreeNode *createTree(vector<int> &nums, int start, int end){

        if(start > end) return nullptr;

        int maxi=INT_MIN;
        int index=-1;
        for(int i = start; i <= end; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                index = i;
            }
        }

        TreeNode *root = new TreeNode(maxi);
        root->left = createTree(nums,start,index-1);
        root->right = createTree(nums,index+1,end);

        return root;

    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        if(nums.size()==0){
            return {nullptr};
        }
        
        return createTree(nums,0,nums.size()-1);
    }
};