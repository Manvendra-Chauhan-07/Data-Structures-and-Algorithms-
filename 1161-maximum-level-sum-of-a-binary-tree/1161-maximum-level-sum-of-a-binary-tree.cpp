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
    void bfs(TreeNode *root, int &level, int sum, int &maxi){

        queue<TreeNode *> q;
        q.push(root);

        int l=1;

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
            if(sum>maxi){
                maxi=sum;
                level=l;
            }
            l++;
        }
    }

    int maxLevelSum(TreeNode* root) {

        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        
        int level=0;
        long long int sum=0;
        int maxi=INT_MIN;
        bfs(root,level,sum,maxi);

        return level;
    }
};