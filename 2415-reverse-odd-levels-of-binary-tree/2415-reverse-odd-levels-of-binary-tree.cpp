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

    void reverse(vector<TreeNode *> &arr){
        
        int end=arr.size()-1;

        int start=0;

        while(start<end){
            swap(arr[start]->val,arr[end]->val);
            start++;
            end--;
        }

    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(root==nullptr){
            return nullptr;
        }

        if(root->left==nullptr && root->right==nullptr){
            return root;
        }

        queue<TreeNode *> q;
        q.push(root);
        int level=0;

        while(!q.empty()){

            int n = q.size();
            vector<TreeNode *>arr;

            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();

                if(level%2!=0){
                    arr.push_back(temp);
                }

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

            }
            
            if(level%2!=0){
                reverse(arr);
            }

            level++;
            
        }

        return root;
    }
};