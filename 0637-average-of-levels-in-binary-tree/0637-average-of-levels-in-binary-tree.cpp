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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if(root==nullptr){
            return {0};
        }

        queue<TreeNode *> q;
        q.push(root);

        vector<double> arr;
        
        double sum=0;

        while(!q.empty()){
            
            int n=q.size();

            sum=0;

            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();

                sum=sum+temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            arr.push_back(double(sum/n));
        }

        return arr;
    }
};