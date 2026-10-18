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

    int find(vector<int> &preorder, int index, int start, int end){
        
        for(int i=start;i<=end;i++){
            if(preorder[i]>preorder[index]){
                return i;
            }
        }
        return end+1;
    }

    TreeNode *buildTree(vector<int> &preorder, int &index, int start, int end){
        if(start>end){
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[index]);

        int pos = find(preorder,index,start,end);
        index++;

        root->left = buildTree(preorder,index,start+1,pos-1);

        root->right = buildTree(preorder,index,pos,end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if(preorder.size()==0){
            return nullptr;
        }

        int start=0;
        int end=preorder.size()-1;
        int index=0;

        return buildTree(preorder,index,start,end);
        
    }
};