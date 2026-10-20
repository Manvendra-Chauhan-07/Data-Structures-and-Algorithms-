class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        }

        if (original == target) {
            return cloned;
        }

        TreeNode* left = getTargetCopy(
            original->left, cloned->left, target
        );

        if (left != nullptr) {
            return left;
        }

        return getTargetCopy(
            original->right, cloned->right, target
        );
    }
};