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

    void checkEven(vector<int> &arr, bool &flag){
        if(arr.size()==1 ){
            return;
        }

        int n=arr.size();

        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1] || arr[i]%2==0){
                flag=false;
            }
        }
    }

    void checkOdd(vector<int> &arr, bool &flag){
        if(arr.size()==1){
            return;
        }

        int n=arr.size();

        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1] || arr[i]%2!=0){
                flag=false;
            }
        }
    }

    void levelOrder(TreeNode *root, bool &flag){

        if(root==nullptr){
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        int level=0;

        while(!q.empty()){
            
            int n=q.size();

            vector<int> arr;

            for(int i=0;i<n;i++){

                TreeNode *temp=q.front();
                q.pop();
                
                if(level%2==0){
                    if(temp->val%2==0){
                        flag=false;
                    }
                }
                if(level%2!=0){
                    if(temp->val%2!=0){
                        flag=false;
                    }
                }
                arr.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }

            if(level%2==0){
                checkEven(arr,flag);
            }else{
                checkOdd(arr,flag);
            }

            level++;

            if(flag==false){
                return;
            }
        }

    }

    bool isEvenOddTree(TreeNode* root) {

        if(root==nullptr){
            return true;
        }
        
        bool flag=true;;

        levelOrder(root,flag);

        return flag;
    }
};