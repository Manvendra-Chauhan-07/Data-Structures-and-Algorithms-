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

    void vecSize(TreeNode *root, int &left, int &right, int level){
        if(root==nullptr){
            return;
        }

        left=min(left,level);
        right=max(right,level);

        vecSize(root->left,left,right,level-1);
        vecSize(root->right,left,right,level+1);

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root == nullptr){
            return {};
        }   

        int left=INT_MAX;
        int right=INT_MIN;

        vecSize(root,left,right,0);

        vector<vector<pair<int,int>>> ansLeft((abs(left)+1));
        vector<vector<pair<int,int>>> ansRight(right+1);

        queue<TreeNode *>q;
        q.push(root);
        queue<pair<int,int>> i;
        i.push({0,0});

        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            int pos=i.front().first;
            int row=i.front().second;
            i.pop();

            if(pos>=0){
                ansRight[pos].push_back({row, temp->val});
            }else{
                ansLeft[abs(pos)].push_back({row, temp->val});
            }

            if(temp->left){
                q.push(temp->left);
                i.push({pos-1,row+1});
            }

            if(temp->right){
                q.push(temp->right);
                i.push({pos+1,row+1});
            }
        }

        vector<vector<int>> ans;

        for(auto &v : ansLeft)
        sort(v.begin(), v.end());

        for(auto &v : ansRight)
        sort(v.begin(), v.end());

        for(int i=ansLeft.size()-1;i>0;i--){

            vector<int> temp;

            for(auto p : ansLeft[i]) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }

        for(int i=0;i<ansRight.size();i++){

            vector<int> temp;

            for(auto p : ansRight[i]) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }


        return ans;

    }
};