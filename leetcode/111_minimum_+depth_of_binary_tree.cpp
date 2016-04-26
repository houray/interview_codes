class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) { return 0; }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!left || !right) {
            return left > right ? left + 1 : right + 1;
        }   else {
            return left > right ? right + 1 : left + 1;
        }
    }
};
