class Solution {
public:
    bool isB = true;
    int height(TreeNode* root) {
        if (!root) { return 0; }
        int left = height(root->left);
        int right = height(root->right);
        if (right - left > 1 || left - right > 1) {
            isB = false;
        }
        return left > right ? left + 1 : right + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) { return true; }
        height(root);
        return isB;
    }
};
