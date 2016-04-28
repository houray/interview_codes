class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) { return 0; }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left < right ? right + 1 : left + 1;
    }
};