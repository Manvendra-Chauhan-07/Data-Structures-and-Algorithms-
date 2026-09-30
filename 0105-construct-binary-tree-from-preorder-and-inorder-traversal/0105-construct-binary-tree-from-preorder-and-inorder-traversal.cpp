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

    int cut(int index, vector<int> &preorder, vector<int> &inorder, int start, int end){

        for(int i=start;i<=end;i++){
            if(inorder[i]==preorder[index]){
                return i;
            }
        }

        return -1;
    }

    TreeNode *formTree(int &index, vector<int> &preorder, vector<int> &inorder, int start, int end){

        if(start>end){
            return nullptr;
        }

        int pos=cut(index,preorder,inorder,start,end);

        TreeNode *temp=new TreeNode(preorder[index]);

        index++;

        temp->left=formTree(index,preorder,inorder,start,pos-1);
        temp->right=formTree(index,preorder,inorder,pos+1,end);

        return temp;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int index=0;

        return formTree(index,preorder,inorder,0,preorder.size()-1);
    }
};