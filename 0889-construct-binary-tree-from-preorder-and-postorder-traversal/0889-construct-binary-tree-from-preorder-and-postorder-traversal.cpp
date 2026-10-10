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

    int find(vector<int> &preorder, vector<int> &postorder, int start, int end, int nextRoot){
        for(int i=start;i<=end;i++){
            if(postorder[i]==nextRoot){
                return i;
            }
        }
        return -1;
    }

    TreeNode *formTree(vector<int> &preorder, vector<int> &postorder, int prelow, int prehigh, int postlow, int posthigh){

        if(prelow>prehigh || postlow>posthigh){
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[prelow]);

        if(prelow==prehigh){
            return root;
        }

        int nextRoot = preorder[prelow+1];

        int pos = find(preorder,postorder,postlow,posthigh,nextRoot);

        int size=pos-postlow+1;

        root->left = formTree(preorder, postorder, prelow+1, size+prelow, postlow, pos);
        root->right = formTree(preorder, postorder, prelow+size+1, prehigh, pos+1, posthigh-1);

        return root;

    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int prelow=0;
        int prehigh=preorder.size()-1;
        int postlow=0;
        int posthigh=postorder.size()-1;

        return formTree(preorder,postorder,prelow,prehigh,postlow,posthigh);
    }
};