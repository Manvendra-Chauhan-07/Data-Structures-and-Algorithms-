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

    bool check(TreeNode* bigTree, TreeNode* subRoot) {

        if (bigTree == nullptr && subRoot == nullptr) {
            return true;
        }

        if (bigTree == nullptr || subRoot == nullptr) {
            return false;
        }

        if (bigTree->val != subRoot->val) {
            return false;
        }

        return check(bigTree->left, subRoot->left) &&
               check(bigTree->right, subRoot->right);
    }

    bool path(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr) {
            return false;
        }

        if (root->val == subRoot->val) {
            if (check(root, subRoot)) {
                return true;
            }
        }

        return path(root->left, subRoot) ||
               path(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (subRoot == nullptr) {
            return true;
        }

        if (root == nullptr) {
            return false;
        }

        return path(root, subRoot);
    }
};