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

    int find(int index, vector<int> &inorder, vector<int> &postorder, int start, int end){
        for(int i=start;i>=end;i--){
            if(inorder[i]==postorder[index]){
                return i;
            }
        }

        return -1;
    }

    TreeNode *formTree(int &index, vector<int> &inorder, vector<int> &postorder, int start, int end){
        if(start<end){
            return nullptr;
        }

        int pos = find(index, inorder, postorder, start, end);

        TreeNode *temp = new TreeNode(postorder[index]);

        index--;

        temp->right=formTree(index,inorder,postorder,start,pos+1);
        temp->left=formTree(index,inorder,postorder,pos-1,end);

        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=postorder.size()-1;

        int index=n;

        return formTree(index,inorder,postorder,n,0);
    }
};